#pragma once

#include "state_interface.h"

class OpenedState : public StateInterface {

public:
    explicit OpenedState();
    ~OpenedState() override = default;

    void Enter(DoorController * ctrl) override;
    void Exit(DoorController * ctrl) override;
    void StopButtonPushed(DoorController * ctrl) override;


    /* Optional functions */
    void CloseButtonPushed(DoorController * ctrl) override;
};

