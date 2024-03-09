#include "application/application.h"

#include <iostream>

class rclink : public application
{
public:
    rclink()
    {
    }

    ~rclink()
    {
    }

private:
    void update(float timestep) override
    {
    }
};

std::unique_ptr<application> create_application()
{
    return std::make_unique<rclink>();
}
