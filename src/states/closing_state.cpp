#include "closing_state.h"

#include "door_controller.h"

ClosingState::ClosingState() : StateInterface("Closing") {}


void ClosingState::Enter(DoorController * ctrl) {

}

void ClosingState::Exit(DoorController * ctrl) {

}

void ClosingState::StopButtonPushed(DoorController * ctrl) {
    ctrl->EmergencyStopGate();
    ctrl->ChangeState(StateContainer::EMERGENCY_STOP);
};

/* Optional functions */
void ClosingState::OpenButtonPushed(DoorController * ctrl) {
    ctrl->StopGate();
    ctrl->ChangeState(StateContainer::STOP);
};

void ClosingState::CloseButtonReleased(DoorController * ctrl) {
    ctrl->StopGate();
    ctrl->ChangeState(StateContainer::STOP);
};

void ClosingState::MultifunctionButtonReleased(DoorController * ctrl) {
    ctrl->StopGate();
    ctrl->ChangeState(StateContainer::STOP);
};

void ClosingState::GateClosed(DoorController * ctrl) {
    ctrl->StopGate();
    ctrl->ChangeState(StateContainer::CLOSED);
};
