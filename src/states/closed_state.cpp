#include "closed_state.h"

#include "door_controller.h"

ClosedState::ClosedState() : StateInterface("Closed") {}


void ClosedState::Enter(DoorController * ctrl) {

}

void ClosedState::Exit(DoorController * ctrl) {

}

/* Optional functions */
 void ClosedState::OpenButtonPushed(DoorController * ctrl) {
     ctrl->OpenGate();
 };

 void ClosedState::CloseButtonPushed(DoorController * ctrl) {
     ctrl->CloseGate();
 }

 void ClosedState::CloseButtonReleased(DoorController * ctrl) {};

 void ClosedState::StopButtonPushed(DoorController * ctrl) {};
 void ClosedState::StopButtonReleased(DoorController * ctrl) {};

 void ClosedState::GateClosed(DoorController * ctrl) {};
 void ClosedState::GateOpened(DoorController * ctrl) {};