#include "closed_state.h"

#include "door_controller.h"

ClosedState::ClosedState() : StateInterface("Closed") {}


void ClosedState::Enter(DoorController * ctrl) {

}

void ClosedState::Exit(DoorController * ctrl) {

}

void ClosedState::StopButtonPushed(DoorController * ctrl) {
    ctrl->EmergencyStopGate();
    ctrl->ChangeState(StateContainer::EMERGENCY_STOP);
};

/* Optional functions */
void ClosedState::OpenButtonPushed(DoorController * ctrl) {
    ctrl->OpenGate();
    ctrl->ChangeState(StateContainer::OPENING);
};

