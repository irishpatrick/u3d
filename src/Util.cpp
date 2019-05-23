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

void Util::to_radians(glm::vec3& v)
{
    v.x = glm::radians(v.x);
    v.y = glm::radians(v.y);
    v.z = glm::radians(v.z);
}
