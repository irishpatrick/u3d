#include <cstdio>
#include "u3d.hpp"

int main()
{
    printf("hello world\n");
    u3d::Camera camera;
    u3d::Shader shader;
    u3d::Context ctx;
    ctx.init(3, 2, 1, 24, 1280, 720);
    shader.compile("assets/vertex.glsl", "assets/fragment.glsl");
    SDL_Event e;

    camera.init(shader.getId());

    u3d::Mesh test = u3d::ObjLoader::load("assets/cube.obj");
    test.create(shader.getId());

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

        //test.update();
        test.draw();

        ctx.draw();
    }
        
    return 0;
}