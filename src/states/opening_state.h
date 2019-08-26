#pragma once

#include "state_interface.h"

class OpeningState : public StateInterface {

public:
    explicit OpeningState();
    ~OpeningState() override = default;

    void Enter(DoorController * ctrl) override;
    void Exit(DoorController * ctrl) override;
    void StopButtonPushed(DoorController * ctrl) override;


    /* Optional functions */
    void GateOpened(DoorController * ctrl) override;
    void CloseButtonPushed(DoorController * ctrl) override;
    void MultifunctionButtonPushed(DoorController * ctrl) override;
};

