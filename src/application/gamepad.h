#pragma once

#include <emscripten/html5.h>

class gamepad
{
public:
    ~gamepad();

private:
    gamepad(const EmscriptenGamepadEvent &state);

    void poll();

    EmscriptenGamepadEvent m_state;

    friend class gamepad_manager;
};
