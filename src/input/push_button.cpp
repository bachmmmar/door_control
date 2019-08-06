#include <Arduino.h>
#include "../infrastructure/logger.h"
#include "push_button.h"


PushButton::PushButton(const PushButtonConfig & config, Logger *logger) :
        config_(config), logger_(logger) {
    setup();
}

void PushButton::setup() {
    pinMode(config_.detection_pin, INPUT_PULLUP);
    last_state_ = IsPushed();
    logger_->log(Logger::DEBUG, config_.name + " Button initialized, " + GetInputStateAsString(last_state_));
};

bool PushButton::IsPushed() {
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
