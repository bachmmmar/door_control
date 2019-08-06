#pragma once

#include "state_interface.h"

class ClosedState : public StateInterface {

public:
    explicit ClosedState();

    ~ClosedState() override = default;

    void Enter(DoorController * ctrl) override;
    void Exit(DoorController * ctrl) override;


    /* Optional functions */
    void OpenButtonPushed(DoorController * ctrl) override;

    void CloseButtonPushed(DoorController * ctrl) override;
    void CloseButtonReleased(DoorController * ctrl) override;

    void StopButtonPushed(DoorController * ctrl) override;
    void StopButtonReleased(DoorController * ctrl) override;

    void GateClosed(DoorController * ctrl) override;
    void GateOpened(DoorController * ctrl) override;

};

