#include "Util.hpp"
#include <chrono>

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

unsigned int Util::currentTimeMillis()
{
	std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(
		std::chrono::system_clock::now().time_since_epoch());

	return (unsigned int)ms.count();
}