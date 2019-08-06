#pragma once

#include <pins_arduino.h>
#include <Arduino.h>

#define ACTIVE_HIGH true
#define ACTIVE_LOW false

struct PushButtonConfig {
    uint8_t detection_pin;
    bool polarity;
    String name;

    explicit PushButtonConfig(uint8_t pin, bool polarity, String name) : detection_pin(pin), polarity(polarity), name(name) {}
};

struct VariableSpeedStarterConfig {
    uint8_t fwd_pin;
    uint8_t rev_pin;
    uint8_t extflt_pin;
    uint8_t fref_pin;

    VariableSpeedStarterConfig() : fwd_pin(6), rev_pin(7), extflt_pin(10), fref_pin(3) {}
};

struct Configuration {
    PushButtonConfig open_button;
    PushButtonConfig close_button;
    PushButtonConfig stop_button;

    PushButtonConfig opened_contact;
    PushButtonConfig closed_contact;

    VariableSpeedStarterConfig starter;

    Configuration() :
        open_button(A0, ACTIVE_HIGH, "open"),
        close_button(A1, ACTIVE_HIGH, "close"),
        stop_button(A2, ACTIVE_LOW, "stop"),

        opened_contact(A5, ACTIVE_LOW, "opened"),
        closed_contact(A4, ACTIVE_LOW, "closed"),
        starter()
         {}
};


