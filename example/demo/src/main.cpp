#include <cstdio>
#include "u3d.hpp"

int main()
{
    printf("hello world\n");
    u3d::Shader shader;
    u3d::Context ctx;
    ctx.init(3, 2, 1, 24, 1280, 720);
    shader.compile("assets/vertex.glsl", "assets/fragment.glsl");
    SDL_Event e;

    Mesh test = ObjLoader::load("assets/cube.obj");
    test.create(shader.)

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