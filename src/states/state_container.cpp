
#include "state_container.h"
#include "closed_state.h"


enum States {CLOSED, OPENED, OPENING, CLOSING, STOP, EMERGENCY_STOP};

StateContainer::StateContainer() {
    closed_ = new ClosedState();
    opened_ = closed_;
    opening_= closed_;
    closing_= closed_;
    stop_ = closed_;
    emergency_stop_ = closed_;
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