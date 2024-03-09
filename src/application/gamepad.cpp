#include "gamepad.h"

#include <iostream>

gamepad::gamepad(const EmscriptenGamepadEvent &state) : m_state(state)
{
    std::cout << "[gamepad] connected"
              << "\n timeStamp: " << m_state.timestamp
              << "\n connected: " << m_state.connected
              << "\n index: " << m_state.index
              << "\n numAxes: " << m_state.numAxes
              << "\n numButtons: " << m_state.numButtons
              << "\n id: \"" << m_state.id << "\""
              << "\n mapping: \"" << m_state.mapping << "\"\n";
}

gamepad::~gamepad()
{
    std::cout << "[gamepad] disconnected"
              << "\n timeStamp: " << m_state.timestamp
              << "\n connected: " << m_state.connected
              << "\n index: " << m_state.index
              << "\n numAxes: " << m_state.numAxes
              << "\n numButtons: " << m_state.numButtons
              << "\n id: \"" << m_state.id << "\""
              << "\n mapping: \"" << m_state.mapping << "\"\n";
}

void gamepad::poll()
{
    EmscriptenGamepadEvent state;

    if (emscripten_get_gamepad_status(m_state.index, &state) != EMSCRIPTEN_RESULT_SUCCESS)
        return;

    bool key_detected = false;

    for (int i = 0; i < state.numAxes; i++)
        if (state.axis[i] != m_state.axis[i])
        {
            std::cout << "[gamepad " << m_state.index << "] axis " << i << ": " << state.axis[i] << "\n";

            key_detected = true;
        }

    for (int i = 0; i < state.numButtons; i++)
        if (state.analogButton[i] != m_state.analogButton[i] || state.digitalButton[i] != m_state.digitalButton[i])
        {
            std::cout << "[gamepad " << m_state.index << "] button " << i << ": Digital: " << state.digitalButton[i] << ", Analog: " << state.analogButton[i] << "\n";

            key_detected = true;
        }

    if (key_detected)
        m_state = state;
}