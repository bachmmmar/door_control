#include "opened_state.h"

#include "door_controller.h"

OpenedState::OpenedState() : StateInterface("Opened") {}


void OpenedState::Enter(DoorController * ctrl) {

}

void OpenedState::Exit(DoorController * ctrl) {

}

void OpenedState::StopButtonPushed(DoorController * ctrl) {
    ctrl->EmergencyStopGate();
    ctrl->ChangeState(StateContainer::EMERGENCY_STOP);
};

/* Optional functions */
void OpenedState::CloseButtonPushed(DoorController * ctrl) {
    ctrl->CloseGate();
    ctrl->ChangeState(StateContainer::CLOSING);
};

void OpenedState::MultifunctionButtonPushed(DoorController * ctrl) {
    ctrl->CloseGate();
    ctrl->ChangeState(StateContainer::CLOSING);
};