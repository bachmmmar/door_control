#pragma once


class Callback {
public:
    Callback();

    void SetCallback(void (*callback)(void *), void *context);
    void CallCallback();

private:
    void (*callback_)(void *);
    void *context_;

};

