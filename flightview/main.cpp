#include <iostream>
#include <u3d.hpp>

Context ctx;
Camera camera;
Mesh vehicle;
Shader shader;
Texture dirt;

int init()
{
    ctx.init();

    camera.setup(70.0f, 16.0f / 9.0f, 0.1f, 100.0f);
    camera.position.z = -7;
    camera.position.y = 0;
    camera.rotation.z = 20;

    return 0;
}

void update()
{
    ctx.poll();
}

void render()
{
    ctx.clear();



    ctx.draw();
}

int main(int argc, char** argv)
{
    std::cout << "hello world" << std::endl;
    
    int err;
    
    err = init();
    if (err)
    {
        exit(err);
    }

    int running = 1;
    while (running)
    {
        int esc = glfwGetKey(ctx.window, GLFW_KEY_ESCAPE) == GLFW_PRESS;
        if (esc)
        {
            running = 0;
        }
        if (glfwWindowShouldClose(ctx.window))
        {
            running = 0;
        }

        update();
        render();
    }
    
    return 0;
}