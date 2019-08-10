#include <Arduino.h>
#include "src/input/push_button.h"
#include "src/timer/Timer.h"
#include "src/infrastructure/logger.h"
#include "src/configuration.h"
#include "src/states/door_controller.h"
#include "src/output/variable_speed_starter.h"


//Configuration config;
Timer timer;
Configuration config;

Logger * logger;
PushButton * open;
PushButton * close;
PushButton * stop;
PushButton * opened;
PushButton * closed;

DoorController * controller;
VariableSpeedStarter * starter;


/** Arduino loop function */
void loop() {
    timer.update();
}

/** 1ms loop function */
void ms_loop() {
    open->Update1Ms();
    close->Update1Ms();
    stop->Update1Ms();
    opened->Update1Ms();
    closed->Update1Ms();
}

/** Arduino setup function */
void setup() {
    logger = new Logger();
    logger->log(Logger::INFO, "Initializing inputs...");
    open = new PushButton(config.open_button, logger);
    close = new PushButton(config.close_button, logger);
    stop = new PushButton(config.stop_button, logger);

    opened = new PushButton(config.opened_contact, logger);
    closed = new PushButton(config.closed_contact, logger);

    logger->log(Logger::INFO, "Initializing outputs...");
    starter = new VariableSpeedStarter(config.starter, logger);

    logger->log(Logger::INFO, "Initializing Door Controller...");
    controller = new DoorController(starter, stop, opened, closed, &timer, logger);
    controller->RegisterInputCallbacks(open, close, stop, opened, closed);

    timer.every(1, ms_loop);
}
