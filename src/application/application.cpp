#include "application/application.h"

#include <assert.h>

application *application::s_instance = nullptr;

application::application() : m_is_running(true)
{
    assert(s_instance == nullptr);

    s_instance = this;
}

application::~application()
{
}