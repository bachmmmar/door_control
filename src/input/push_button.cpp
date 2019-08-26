#include <Arduino.h>
#include "../infrastructure/logger.h"
#include "push_button.h"


PushButton::PushButton(const PushButtonConfig & config, Logger *logger) :
        config_(config), logger_(logger) {
    setup();
}

void PushButton::setup() {
    pinMode(config_.detection_pin, INPUT_PULLUP);

    bool state = RawButtonIsPushed();
    last_state_ = state;

    // initialize debounce mechanism
    if (state) {
        debounce_counter_ = config_.threshold_max;
        debounce_state_ = true;
    } else {
        debounce_counter_ = 0;
        debounce_state_ = false;
    }
    logger_->log(Logger::DEBUG, config_.name + " Button initialized, " + GetInputStateAsString(last_state_));
};

/** Debounced Button state **/
bool PushButton::IsPushed() {
    if (RawButtonIsPushed()) {
        if (debounce_counter_ < config_.threshold_max)
            debounce_counter_ ++;
    } else {
        if (debounce_counter_ != 0)
            debounce_counter_ --;
    }

    if (debounce_counter_ >= config_.threshold_pushed) {
        debounce_state_ = true;
        return true;
    } else if (debounce_counter_ <= config_.threshold_released) {
        debounce_state_ = false;
        return false;
    } else {
        return debounce_state_;
    }
}

bool PushButton::RawButtonIsPushed() {
    if (config_.polarity) {
        return !static_cast<bool>(digitalRead(config_.detection_pin));
    } else {
        return static_cast<bool>(digitalRead(config_.detection_pin));
    }
}


void PushButton::Update1Ms() {
    bool state = IsPushed();

    if (state != last_state_) {
        if (state == HIGH) {
            pushed_callback_.CallCallback();
            logger_->log(Logger::DEBUG, config_.name + " Button pushed!");
        } else {
            released_callback_.CallCallback();
            logger_->log(Logger::DEBUG, config_.name + " Button released!");
        }
    }

    last_state_ = state;
}

const String PushButton::GetInputStateAsString(bool state) const {
    if (state) {
        return "PUSHED";
    } else {
        return "RELEASED";
    }
}

Callback * PushButton::Pushed() {
    return &pushed_callback_;
}

Callback * PushButton::Released() {
    return &released_callback_;
}
