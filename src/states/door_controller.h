#pragma once

#include "state_interface.h"
#include "state_container.h"

class PushButton;
class Logger;
class VariableSpeedStarter;

class DoorController {
public:

    explicit DoorController(VariableSpeedStarter * starter, PushButton * opened, PushButton * closed, Logger *logger);

    void RegisterInputCallbacks(PushButton * open, PushButton * close, PushButton * stop, PushButton * opened, PushButton * closed);


    void ChangeState(StateContainer::States state);
    void OpenGate();
    void CloseGate();

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

    void Initialize(PushButton * opened, PushButton * closed);

    VariableSpeedStarter * starter_;
    Logger * logger_;

    StateInterface * current_state_;
    StateContainer states_;
};
