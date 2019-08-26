#pragma once

#include "state_interface.h"

class StopState : public StateInterface {

public:
    explicit StopState();
    ~StopState() override = default;

    void Enter(DoorController * ctrl) override;
    void Exit(DoorController * ctrl) override;
    void StopButtonPushed(DoorController * ctrl) override;


    /* Optional functions */
    void OpenButtonPushed(DoorController * ctrl) override;
    void CloseButtonPushed(DoorController * ctrl) override;
    void GateClosed(DoorController * ctrl) override;
    void GateOpened(DoorController * ctrl) override;
    void MultifunctionButtonPushed(DoorController * ctrl) override;
};

