
#include "variable_speed_starter.h"
#include "../infrastructure/logger.h"

VariableSpeedStarter::VariableSpeedStarter(const VariableSpeedStarterConfig & config, Logger *logger) :
        config_(config), logger_(logger) {
    setup();
}

void VariableSpeedStarter::setup() {
    pinMode(config_.fwd_pin, OUTPUT);
    digitalWrite(config_.fwd_pin, LOW);

    pinMode(config_.rev_pin, OUTPUT);
    digitalWrite(config_.rev_pin, LOW);

    pinMode(config_.extflt_pin, OUTPUT);
    digitalWrite(config_.extflt_pin, HIGH);

    pinMode(config_.fref_pin, OUTPUT);
    digitalWrite(config_.fref_pin, LOW);
}


void VariableSpeedStarter::fwd() {
    logger_->log(Logger::DEBUG, "Rotate Motor FWD");
    digitalWrite(config_.extflt_pin, HIGH);
    digitalWrite(config_.fwd_pin, HIGH);
    digitalWrite(config_.rev_pin, LOW);
}

void VariableSpeedStarter::rev() {
    logger_->log(Logger::DEBUG, "Rotate Motor REV");
    digitalWrite(config_.extflt_pin, HIGH);
    digitalWrite(config_.rev_pin, HIGH);
    digitalWrite(config_.fwd_pin, LOW);
}

void VariableSpeedStarter::stop() {
    digitalWrite(config_.rev_pin, LOW);
    digitalWrite(config_.fwd_pin, LOW);
    logger_->log(Logger::DEBUG, "Motor Stopped");
}

void VariableSpeedStarter::emergency_stop() {
    digitalWrite(config_.extflt_pin, LOW);
    logger_->log(Logger::INFO, "Motor Emergency Stop");
    stop();
}