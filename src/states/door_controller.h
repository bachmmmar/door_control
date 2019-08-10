#pragma once

#include "state_interface.h"
#include "state_container.h"

class PushButton;
class Logger;
class VariableSpeedStarter;
class Timer;

class DoorController {
public:

    explicit DoorController(VariableSpeedStarter * starter, PushButton * stop, PushButton * opened, PushButton * closed, Timer * timer, Logger *logger);

    void RegisterInputCallbacks(PushButton * open, PushButton * close, PushButton * stop, PushButton * opened, PushButton * closed);


    void ChangeState(StateContainer::States state);
    bool IsGateOpened();
    bool IsGateClosed();
    void OpenGate();
    void CloseGate();
    void EmergencyStopGate();
    void StopGate();

private:
    void OpenButtonPushed();

    void CloseButtonPushed();
    void CloseButtonReleased();

    void StopButtonPushed();
    void StopButtonReleased();

    void GateClosed();
    void GateOpened();


    static void open_pushed_callback(void *ptr);
    static void close_pushed_callback(void *ptr);
    static void close_released_callback(void *ptr);
    static void stop_pushed_callback(void *ptr);
    static void stop_released_callback(void *ptr);
    static void closed_activated_callback(void *ptr);
    static void opened_activated_callback(void *ptr);

    void Initialize();

    PushButton * stop_button_;
    PushButton * opened_;
    PushButton * closed_;
    VariableSpeedStarter * starter_;
    StateContainer states_;
    Logger * logger_;

    StateInterface * current_state_;
};
