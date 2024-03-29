#include "application/application.h"

#include <assert.h>

#include <emscripten/html5.h>

application *application::s_instance = nullptr;

application::application()
{
    assert(s_instance == nullptr);

    s_instance = this;

    auto on_update = [](double time, void *user_data)
    {
        static const auto app = static_cast<application *>(user_data);

        app->m_gamepad_manager.poll();

        float timestep = time - app->m_previous_timestamp;
        app->m_previous_timestamp = time;

        if (timestep < 0.0f)
            timestep = 0.0f;

        app->update(timestep);

        return EM_TRUE;
    };

    emscripten_request_animation_frame_loop(on_update, this);
}

application::~application()
{
}
