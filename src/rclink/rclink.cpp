#include "application/application.h"

#include <iostream>

class rclink : public application
{
public:
    rclink()
    {
        std::cout << "[RCLink] constructor\n";
    }

    ~rclink()
    {
        std::cout << "[RCLink] destructor\n";
    }

private:
    void update(float timestep) override
    {
        std::cout << "[RCLink] update " << timestep << "\n";
    }
};

std::unique_ptr<application> create_application()
{
    return std::make_unique<rclink>();
}