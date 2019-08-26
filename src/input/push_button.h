#pragma once

#include <Arduino.h>
#include "../configuration.h"
#include "../infrastructure/callback.h"

class Logger;

class PushButton {

public:

    ~PushButton() = default;

    explicit PushButton(const PushButtonConfig & config, Logger *logger);

    void Update1Ms();

    Callback * Pushed();
    Callback * Released();

    bool IsPushed();

private:

    bool RawButtonIsPushed();

    void setup();
    const String GetInputStateAsString(bool state) const;

    Logger * logger_;
    Callback pushed_callback_;
    Callback released_callback_;

    bool last_state_;

    const PushButtonConfig & config_;

    int debounce_counter_;
    bool debounce_state_;
};
