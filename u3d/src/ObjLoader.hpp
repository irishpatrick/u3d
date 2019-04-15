#pragma once

#include <string>
#include "Mesh.hpp"

namespace u3d
{
    class ObjLoader
    {
        static Mesh load(const std::string&);
    };
}