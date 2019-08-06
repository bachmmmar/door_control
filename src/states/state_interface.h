#pragma once

#include <Arduino.h>

class DoorController;

class StateInterface {

public:
    StateInterface(const char * name) : name_(name) {}
    virtual ~StateInterface() = default;

    virtual void Enter(DoorController * ctrl) = 0;
    virtual void Exit(DoorController * ctrl) = 0;

    virtual void OpenButtonPushed(DoorController * ctrl) {};

    virtual void CloseButtonPushed(DoorController * ctrl) {};
    virtual void CloseButtonReleased(DoorController * ctrl) {};

    virtual void StopButtonPushed(DoorController * ctrl) {};
    virtual void StopButtonReleased(DoorController * ctrl) {};

    virtual void GateClosed(DoorController * ctrl) {};
    virtual void GateOpened(DoorController * ctrl) {};

    const String & GetName() { return name_; }

private:
    String name_;
};

