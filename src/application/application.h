#pragma once

#include <cstdint>
#include <memory>

#include "gamepad_manager.h"
class application
{
public:
    application();
    virtual ~application();

    application(const application &) = delete;
    application(application &&) = delete;
    application &operator=(const application &) = delete;
    application &operator=(application &&) = delete;

protected:
    virtual void update(float timestep) = 0;

private:
    static application *s_instance;

    float m_previous_timestamp = 0;

    gamepad_manager m_gamepad_manager;
};

std::unique_ptr<application> create_application();