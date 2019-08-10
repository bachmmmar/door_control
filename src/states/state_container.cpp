
#include "state_container.h"
#include "../timer/Timer.h"
#include "closed_state.h"
#include "opened_state.h"
#include "closing_state.h"
#include "opening_state.h"
#include "stop_state.h"
#include "emergency_stop_state.h"


enum States {CLOSED, OPENED, OPENING, CLOSING, STOP, EMERGENCY_STOP};

StateContainer::StateContainer(Timer * timer) {
    closed_ = new ClosedState();
    opened_ = new OpenedState();
    opening_= new OpeningState();
    closing_= new ClosingState();
    stop_ = new StopState();
    emergency_stop_ = new EmergencyStopState(timer);
}

StateInterface * StateContainer::GetState(States state) {
    switch (state) {
        case CLOSED:
            return closed_;
        case OPENED:;
            return opened_;
        case OPENING:
            return opening_;
        case CLOSING:
            return closing_;
        case STOP:
            return stop_;
        case EMERGENCY_STOP:
            return emergency_stop_;
    }
}