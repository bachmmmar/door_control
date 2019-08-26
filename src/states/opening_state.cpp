#include "opening_state.h"

#include "door_controller.h"

OpeningState::OpeningState() : StateInterface("Opening") {}


void OpeningState::Enter(DoorController * ctrl) {

}

void OpeningState::Exit(DoorController * ctrl) {

}

void OpeningState::StopButtonPushed(DoorController * ctrl) {
    ctrl->StopGate();
    ctrl->ChangeState(StateContainer::STOP);
};

/* Optional functions */
void OpeningState::CloseButtonPushed(DoorController * ctrl) {
    ctrl->StopGate();
    ctrl->ChangeState(StateContainer::STOP);
};

void OpeningState::MultifunctionButtonPushed(DoorController * ctrl) {
    ctrl->StopGate();
    ctrl->ChangeState(StateContainer::STOP);
};

void OpeningState::GateOpened(DoorController * ctrl) {
    ctrl->StopGate();
    ctrl->ChangeState(StateContainer::OPENED);
};
