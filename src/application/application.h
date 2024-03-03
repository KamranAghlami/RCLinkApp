#pragma once

#include <cstdint>
#include <memory>

class application
{
public:
    application();
    virtual ~application();

    application(const application &) = delete;
    application(application &&) = delete;
    application &operator=(const application &) = delete;
    application &operator=(application &&) = delete;

    bool is_running() { return m_is_running; };

protected:
    virtual void update(float timestep) = 0;

    bool m_is_running;

private:
    static application *s_instance;
};

std::unique_ptr<application> create_application();