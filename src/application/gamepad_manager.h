#pragma once

#include <vector>
#include <memory>

#include <emscripten/html5.h>

#include "gamepad.h"

class gamepad_manager
{
public:
    gamepad_manager();
    ~gamepad_manager();

    EM_BOOL on_gamepad_connected(const EmscriptenGamepadEvent *event);
    EM_BOOL on_gamepad_disconnected(const EmscriptenGamepadEvent *event);

    void poll();

private:
    std::vector<std::unique_ptr<gamepad>> m_gamepads;
};
