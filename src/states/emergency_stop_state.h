#pragma once

#include "state_interface.h"

class Timer;

class EmergencyStopState : public StateInterface {

public:
    explicit EmergencyStopState(Timer * timer);
    ~EmergencyStopState() override = default;

    void Enter(DoorController * ctrl) override;
    void Exit(DoorController * ctrl) override;
    void StopButtonPushed(DoorController * ctrl) override;

private:
    static void timeout_callback(void *ptr);

    Timer * timer_;
};

