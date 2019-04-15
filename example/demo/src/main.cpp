#include <cstdio>
#include "u3d.hpp"

int main()
{
    printf("hello world\n");
    
    u3d::Context ctx;
    ctx.init(3, 2, 1, 24, 1280, 720);

    SDL_Event e;

    int running = 1;
    
    while (running)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                running = 0;
            }
        }

        ctx.clear();
        ctx.draw();
    }
        
    return 0;
}