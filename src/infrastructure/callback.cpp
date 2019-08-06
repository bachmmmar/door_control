#include "callback.h"


Callback::Callback() : callback_(nullptr), context_(nullptr) {}


void Callback::SetCallback(void (*callback)(void *), void *context) {
    callback_ = callback;
    context_ = context;
}
void Callback::CallCallback() {
    if (callback_!= nullptr) {
        (*callback_)(context_);
    }
}