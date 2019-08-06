#include "logger.h"
#include <Arduino.h>

// for arduino feather
//#define Serial SERIAL_PORT_USBVIRTUAL

Logger::Logger() {
    Serial.begin(9600);
}

void Logger::log(Severity severity, const String & message) {
    String str = String(String(millis()) + ";" + getSeverityAsString(severity) + ";" + message);
    Serial.println(str.c_str());
}


const String Logger::getSeverityAsString(Severity severity) const {
    switch (severity) {
        case DEBUG:
            return "DEBUG";
        case INFO:
            return "INFO";
        case ERROR:
            return "ERROR";
    }
    return "UNDEF";
}

