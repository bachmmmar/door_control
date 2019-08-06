#pragma once


class String;

class Logger {

public:
    enum Severity {DEBUG=0, INFO=1, ERROR=2};
    explicit Logger();

    void log(Severity severity, const String & message);

private:
    const String getSeverityAsString(Severity severity) const;
};

