#pragma once

#include "state_interface.h"

class Timer;

class StateContainer {

public:
    enum States {CLOSED, OPENED, OPENING, CLOSING, STOP, EMERGENCY_STOP};

    explicit StateContainer(Timer * timer);
    StateInterface * GetState(States state);

private:
    StateInterface * closed_;
    StateInterface * opened_;
    StateInterface * closing_;
    StateInterface * opening_;
    StateInterface * stop_;
    StateInterface * emergency_stop_;
};

