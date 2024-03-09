#include "gamepad_manager.h"

#include <iostream>
#include <functional>

gamepad_manager::gamepad_manager()
{
    auto on_connected = [](int event_type, const EmscriptenGamepadEvent *event, void *user_data)
    {
        auto manager = static_cast<gamepad_manager *>(user_data);

        return manager->on_gamepad_connected(event);
    };

    emscripten_set_gamepadconnected_callback(this, EM_TRUE, on_connected);

    auto on_disconnected = [](int event_type, const EmscriptenGamepadEvent *event, void *user_data)
    {
        auto manager = static_cast<gamepad_manager *>(user_data);

        return manager->on_gamepad_disconnected(event);
    };

    emscripten_set_gamepaddisconnected_callback(this, EM_TRUE, on_disconnected);
}

gamepad_manager::~gamepad_manager()
{
}

EM_BOOL gamepad_manager::on_gamepad_connected(const EmscriptenGamepadEvent *event)
{
    m_gamepads.emplace_back(new gamepad(*event));

    return EM_TRUE;
}

EM_BOOL gamepad_manager::on_gamepad_disconnected(const EmscriptenGamepadEvent *event)
{
    auto gamepad = std::find_if(m_gamepads.begin(), m_gamepads.end(),
                                [event](const auto &gamepad)
                                {
                                    return gamepad->m_state.index == event->index;
                                });

    m_gamepads.erase(gamepad);

    return EM_TRUE;
}

void gamepad_manager::poll()
{
    if (emscripten_sample_gamepad_data() != EMSCRIPTEN_RESULT_SUCCESS)
        return;

    for (auto &gamepad : m_gamepads)
        gamepad->poll();
}