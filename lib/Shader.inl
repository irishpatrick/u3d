template<typename T>
inline void Shader::setUniform(const std::string& name, T& data)
{
	GLuint id = 0;
	if (uniform_cache.find(name) == uniform_cache.end())
	{
		id = getUniform(name);
	}
	else
	{
		id = uniform_cache[name];
	}

}
