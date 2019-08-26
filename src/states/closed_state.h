#pragma once

#include "state_interface.h"

class ClosedState : public StateInterface {

public:
    explicit ClosedState();
    ~ClosedState() override = default;

    void Enter(DoorController * ctrl) override;
    void Exit(DoorController * ctrl) override;
    void StopButtonPushed(DoorController * ctrl) override;


    /* Optional functions */
    void OpenButtonPushed(DoorController * ctrl) override;
    void MultifunctionButtonPushed(DoorController * ctrl) override;
};

