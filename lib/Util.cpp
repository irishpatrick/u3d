#include "Util.hpp"
#include <chrono>
#include <sstream>

glm::vec3 Util::ihat()
{
	return glm::vec3(1, 0, 0);
}

glm::vec3 Util::jhat()
{
	return glm::vec3(0, 1, 0);
}

glm::vec3 Util::khat()
{
	return glm::vec3(0, 0, 1);
}

float Util::distance(glm::vec3& a, glm::vec3& b)
{
	return sqrtf(powf(b.x - a.x, 2) + powf(b.y - a.y, 2) + powf(b.z - a.z, 2));
}

const std::string Util::vector_to_str(glm::vec3& v)
{
	std::stringstream ss;
	ss << "<" << v.x << "," << v.y << "," << v.z << ">";
	return ss.str();
}

unsigned int Util::currentTimeMillis()
{
	std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(
		std::chrono::system_clock::now().time_since_epoch());

	return (unsigned int)ms.count();
}

glm::vec3 Util::to_radians(glm::vec3 v)
{
    glm::vec3 r;
    r.x = glm::radians(v.x);
    r.y = glm::radians(v.y);
    r.z = glm::radians(v.z);
    return r;
}

glm::vec3 Util::to_degrees(glm::vec3 v)
{
    glm::vec3 d;
    d.x = glm::degrees(v.x);
    d.y = glm::degrees(v.y);
    d.z = glm::degrees(v.z);
	return d;
}
