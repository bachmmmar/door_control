#pragma once

#include "state_interface.h"

class ClosingState : public StateInterface {

public:
    explicit ClosingState();
    ~ClosingState() override = default;

    void Enter(DoorController * ctrl) override;
    void Exit(DoorController * ctrl) override;
    void StopButtonPushed(DoorController * ctrl) override;


    /* Optional functions */
    void GateClosed(DoorController * ctrl) override;
    void OpenButtonPushed(DoorController * ctrl) override;
    void CloseButtonReleased(DoorController * ctrl) override;
};

