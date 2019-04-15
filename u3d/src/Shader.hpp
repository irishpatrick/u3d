#pragma once

#include <string>
#include <cstdint>

namespace u3d
{
    class Shader
    {
    public:
        void compile(const std::string&, const std::string&);
    
    private:
        uint32_t vsid;
        uint32_t fsid;
        uint32_t pid;
    };
} // u3d
