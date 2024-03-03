#include <emscripten.h>

#include "application/application.h"

int main()
{
    static auto application = create_application();

    return 0;
}
