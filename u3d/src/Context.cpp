#include "Context.hpp"
#include "Util.hpp"
#include <GL/glew.h>

namespace u3d
{
    void Context::init(uint32_t major, uint32_t minor, uint8_t db, uint32_t depth, uint32_t w, uint32_t h)
    {
        Util::check(SDL_Init(SDL_INIT_VIDEO));
        
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, major);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, minor);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, db);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, depth);

        window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
        Util::checkNull(window);

        context = SDL_GL_CreateContext(window);


        SDL_GL_SetSwapInterval(1);

        glClearColor(0.2, 0.2, 0.2, 1.0);
    }

    void Context::clear()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Context::draw()
    {
        SDL_GL_SwapWindow(window);
    }

    void Context::destroy()
    {
        SDL_GL_DeleteContext(context);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
}