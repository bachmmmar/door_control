#pragma once

#include "../configuration.h"

class Logger;

class VariableSpeedStarter {

public:
    explicit VariableSpeedStarter(const VariableSpeedStarterConfig & config, Logger *logger);

    void fwd();

    void rev();

    void stop();

    void emergency_stop();

private:
    void setup();

    const VariableSpeedStarterConfig & config_;
    Logger * logger_;
};

