#include <cstdio>
#include "u3d.hpp"

int main()
{
    printf("hello world\n");
    
    u3d::Context ctx;
    ctx.init(3, 2, 1, 24, 512, 480);
    ctx.clear();
    ctx.draw();
    ctx.destroy();
        
    return 0;
}