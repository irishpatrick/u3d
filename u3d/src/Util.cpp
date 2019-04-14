#include "Util.hpp"

#include <cstdlib>
#include <cstdio>

namespace u3d
{
    void Util::check(int err)
    {
        if (err < 0)
        {
            printf("error: %d\n", err);
            exit(err);
        }
    }

    void Util::checkNull(void* ptr)
    {
        if (!ptr)
        {
            printf("pointer was null!\n");
            exit(-1);
        }
    }
}