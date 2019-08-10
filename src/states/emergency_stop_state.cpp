#include "emergency_stop_state.h"

#include "door_controller.h"
#include "../timer/Timer.h"

EmergencyStopState::EmergencyStopState(Timer *timer) : StateInterface("EmergencyStop"), timer_(timer) {}


void EmergencyStopState::Enter(DoorController * ctrl) {
    ctrl->EmergencyStopGate();
    Serial.println("em enter");
    timer_->every(5000, timeout_callback, ctrl, 1);
    Serial.println("em enterdone");
}

void EmergencyStopState::Exit(DoorController * ctrl) {}

void EmergencyStopState::StopButtonPushed(DoorController * ctrl) {}

void EmergencyStopState::timeout_callback(void *ptr) {
    Serial.println("em cb");
    static_cast<DoorController*>(ptr)->ChangeState(StateContainer::STOP);
}
