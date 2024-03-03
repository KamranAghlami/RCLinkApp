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

protected:
    virtual void update(float timestep) = 0;

private:
    static application *s_instance;

    int64_t m_previous_timestamp = 0;
};

std::unique_ptr<application> create_application();