template<typename T>
inline void Shader::setUniform(const std::string& id, T& data)
{
	GLuint id = -1;
	if (uniform_cache.find(id) == uniform_cache.end())
	{
		id = getUniform(id);
	}
	else
	{
		id = uniform_cache[id];
	}



}