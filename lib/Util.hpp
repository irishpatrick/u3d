#include "gl_includes.hpp"

class Util
{
public:
    static glm::vec3 ihat();
    static glm::vec3 jhat();
    static glm::vec3 khat();
    static float distance(glm::vec3&, glm::vec3&);
    static const std::string vector_to_str(glm::vec3);
    static void print_vec3(glm::vec3);
    static unsigned int currentTimeMillis();
    static glm::vec3 to_radians(glm::vec3);
    static glm::vec3 to_degrees(glm::vec3);
};
