#include "ObjLoader.hpp"

#include <vector>
#include <fstream>
#include <sstream>
#include <cstdio>

static bool startswith(const std::string& str, const std::string& prefix)
{
    if (str.size() < prefix.size())
    {
        return false;
    }

    for (int i=0; i<prefix.size(); i++)
    {
        if (str[i] != prefix[i])
        {
            return false;
        }
    }

    return true;
}

static std::vector<std::string> split(const std::string& str, const char delim)
{
    std::vector<std::string> out;
    std::string accumulator;
    for (int i=0; i<str.size(); i++)
    {
        if (str[i] == delim)
        {
            if (accumulator.size() != 0)
            {
                out.push_back(accumulator);
                accumulator.clear();
            }
            else
            {
                continue;
            }
            
        }
        else
        {
            accumulator.push_back(str[i]);
        }
    }

    return out;
}

template <typename T>
static std::vector<T> parseVector(const std::vector<T>& vec, int start, int stride)
{
    std::vector<T> out;
    
    if (start + stride > vec.size())
    {
        return out;
    }

    for (int i=start; i<start+stride; i++)
    {
        out.push_back(vec[i]);
    }
    return out;
}

namespace u3d
{
    Mesh ObjLoader::load(const std::string& fn)
    {
        std::ifstream fp(fn);
        if (!fp)
        {
            printf("cannot open file: %s\n", fn.c_str());
        }

        std::vector<float> v;
        std::vector<float> vt;
        std::vector<float> n;
        std::vector<int> f;

        std::vector<std::string> parts;

        std::string line;
        while (std::getline(fp, line))
        {
            if (startswith(line, "v "))
            {
                parts = split(line, ' ');
                for (auto& e : parts)
                {
                    v.push_back(atof(e.c_str()));
                }
            }
            else if (startswith(line, "vt "))
            {
                parts = split(line, ' ');
                for (auto& e : parts)
                {
                    vt.push_back(atof(e.c_str()));
                }
            }
            else if (startswith(line, "vn "))
            {
                parts = split(line, ' ');
                for (auto& e : parts)
                {
                    vt.push_back(atof(e.c_str()));
                }
            }
            else if (startswith(line, "f "))
            {
                parts = split(line, ' ');
                for (auto& e : parts)
                {
                    f.push_back(atoi(e.c_str()));
                }
            }
        }

        Mesh out;

        int dest = 0;
        for (auto& e : f)
        {
            if (dest == 0)
            {
                int index = e - 1;
                std::vector<float> data = parseVector(v, index, 3);
                out.buffer.insert(out.buffer.end(), data.begin(), data.end());     
            }
            else if (dest == 1)
            {
                int index = e - 1;
                std::vector<float> data = parseVector(vt, index, 2);
                out.buffer.insert(out.buffer.end(), data.begin(), data.end());
            }
            else if (dest == 2)
            {
                int index = e - 1;
                std::vector<float> data = parseVector(n, index, 3);
                out.buffer.insert(out.buffer.end(), data.begin(), data.end());
            }

            dest++;
            if (dest == 3)
            {
                dest = 0;
            }
        }
        
        return out;
    }
}
