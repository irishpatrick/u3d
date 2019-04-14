#pragma once

#include <SDL.h>
#include <cstdint>

namespace u3d
{
    class Context
    {
    public:

        void init(uint32_t, uint32_t, uint8_t, uint32_t, uint32_t, uint32_t);
        void clear();
        void draw();
        void destroy();

    private:
        SDL_Window* window;
        SDL_GLContext context;
    };
}