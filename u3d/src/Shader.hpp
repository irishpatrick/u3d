#pragma once

#include <string>
#include <cstdint>

namespace u3d
{
    class Shader
    {
    public:
        void compile(const std::string&, const std::string&);
        uint32_t getId();
    private:
        uint32_t pid;
    };
} // u3d
