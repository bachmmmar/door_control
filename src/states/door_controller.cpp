
#include "../infrastructure/logger.h"
#include "door_controller.h"
#include "../input/push_button.h"
#include "../output/variable_speed_starter.h"

DoorController::DoorController(VariableSpeedStarter * starter, PushButton * stop, PushButton * opened, PushButton * closed, Timer * timer, Logger * logger) :
        stop_button_(stop), opened_(opened), closed_(closed), starter_(starter), states_(timer), logger_(logger) {
    // Preload all states
    Initialize();
}

void DoorController::Initialize() {
    if (IsGateOpened()) {
        logger_->log(Logger::INFO, "Gate seems to be fully opened --> start in state OPENED");
        current_state_ = states_.GetState(StateContainer::OPENED);
    } else if (IsGateClosed()) {
        logger_->log(Logger::INFO, "Gate seems to be fully closed --> start in state CLOSED");
        current_state_ = states_.GetState(StateContainer::CLOSED);
    } else {
        logger_->log(Logger::INFO, "Gate seems to be somewhere in between --> start in state STOP");
        current_state_ = states_.GetState(StateContainer::STOP);
    }
    current_state_->Enter(this);
}

void DoorController::ChangeState(StateContainer::States state) {
    StateInterface * old_state = current_state_;
    StateInterface * new_state = states_.GetState(state);
    old_state->Exit(this);
    new_state->Enter(this);
    logger_->log(Logger::INFO, "State Change " + old_state->GetName() + " -> " + new_state->GetName());
    current_state_ = new_state;

}

void DoorController::RegisterInputCallbacks(PushButton * open, PushButton * close, PushButton * stop, PushButton * multifunction, PushButton * opened, PushButton * closed) {
    open->Pushed()->SetCallback(open_pushed_callback, this);
    close->Pushed()->SetCallback(close_pushed_callback, this);
    close->Released()->SetCallback(close_released_callback, this);
    stop->Pushed()->SetCallback(stop_pushed_callback, this);
    stop->Released()->SetCallback(stop_released_callback, this);
    multifunction->Pushed()->SetCallback(multifunction_pushed_callback, this);
    multifunction->Released()->SetCallback(multifunction_released_callback, this);
    closed->Pushed()->SetCallback(closed_activated_callback, this);
    opened->Pushed()->SetCallback(opened_activated_callback, this);
}

bool DoorController::IsGateOpened() {
    return opened_->IsPushed();
}

bool DoorController::IsGateClosed() {
    return closed_->IsPushed();
}

void DoorController::OpenGate() {
    starter_->fwd();
}

void DoorController::CloseGate() {
    starter_->rev();
}

void DoorController::EmergencyStopGate() {
    starter_->emergency_stop();
}

void DoorController::StopGate() {
    starter_->stop();
}

void DoorController::OpenButtonPushed() {
    current_state_->OpenButtonPushed(this);
}


void DoorController::CloseButtonPushed() {
    current_state_->CloseButtonPushed(this);
}

void DoorController::CloseButtonReleased() {
    current_state_->CloseButtonReleased(this);
}

void DoorController::StopButtonPushed() {
    current_state_->StopButtonPushed(this);
}

void DoorController::StopButtonReleased() {
    current_state_->StopButtonReleased(this);
}

void DoorController::MultifunctionButtonPushed() {
    current_state_->MultifunctionButtonPushed(this);
}

void DoorController::MultifunctionButtonReleased() {
    current_state_->MultifunctionButtonReleased(this);
}


void DoorController::GateClosed() {
    current_state_->GateClosed(this);
}

void DoorController::GateOpened() {
    current_state_->GateOpened(this);
}



/* Static Callback Functions */
void DoorController::open_pushed_callback(void *ptr) {
    static_cast<DoorController*>(ptr)->OpenButtonPushed();
}

void DoorController::close_pushed_callback(void *ptr) {
    static_cast<DoorController*>(ptr)->CloseButtonPushed();
}

void DoorController::close_released_callback(void *ptr) {
    static_cast<DoorController*>(ptr)->CloseButtonReleased();
}

void DoorController::stop_pushed_callback(void *ptr) {
    static_cast<DoorController*>(ptr)->StopButtonPushed();
}

void DoorController::stop_released_callback(void *ptr) {
    static_cast<DoorController*>(ptr)->StopButtonReleased();
}

void DoorController::multifunction_pushed_callback(void *ptr) {
    static_cast<DoorController*>(ptr)->MultifunctionButtonPushed();
}

void DoorController::multifunction_released_callback(void *ptr) {
    static_cast<DoorController*>(ptr)->MultifunctionButtonReleased();
}

void DoorController::closed_activated_callback(void *ptr) {
    static_cast<DoorController*>(ptr)->GateClosed();
}

void DoorController::opened_activated_callback(void *ptr) {
    static_cast<DoorController*>(ptr)->GateOpened();
}