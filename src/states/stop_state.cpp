#include "stop_state.h"

#include "door_controller.h"

StopState::StopState() : StateInterface("Stop") {}


void StopState::Enter(DoorController * ctrl) {
    ctrl->StopGate();
}

void StopState::Exit(DoorController * ctrl) {

}

void StopState::StopButtonPushed(DoorController * ctrl) {
    ctrl->EmergencyStopGate();
    ctrl->ChangeState(StateContainer::EMERGENCY_STOP);
};

/* Optional functions */
void StopState::OpenButtonPushed(DoorController * ctrl) {
    if (!ctrl->IsGateOpened()) {
        ctrl->OpenGate();
        ctrl->ChangeState(StateContainer::OPENING);
    }
};

void StopState::CloseButtonPushed(DoorController * ctrl) {
    if (!ctrl->IsGateClosed()) {
        ctrl->CloseGate();
        ctrl->ChangeState(StateContainer::CLOSING);
    }
};

void StopState::GateClosed(DoorController * ctrl) {
    ctrl->StopGate();
    ctrl->ChangeState(StateContainer::CLOSED);
};

void StopState::GateOpened(DoorController * ctrl) {
    ctrl->StopGate();
    ctrl->ChangeState(StateContainer::OPENED);
};