#include "Assets.hpp"
#include <cstdio>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

void processNode(Mesh&, aiNode*, const aiScene*);
void processMesh(Mesh&, aiMesh*, const aiScene*);

void processNode(Mesh& mesh, aiNode* node, const aiScene* scene)
{
	printf("process node\n");
	if (node == nullptr || scene == nullptr)
	{
		printf("error: null\n");
		return;
	}

	printf("children=%d\tmeshes=%d\n", node->mNumChildren, node->mNumMeshes);

	unsigned int i;
	for (i = 0; i < node->mNumMeshes; ++i)
	{
		processMesh(mesh, scene->mMeshes[node->mMeshes[i]], scene);
	}
	for (i = 0; i < node->mNumChildren; ++i)
	{
		processNode(mesh, node->mChildren[i], scene);
	}
}

void processMesh(Mesh& mesh, aiMesh* amesh, const aiScene* scene)
{
	printf("process mesh\n");
	if (amesh == nullptr || scene == nullptr)
	{
		printf("null args\n");
		return;
	}
	unsigned int i, j;
	for (i = 0; i < amesh->mNumVertices; ++i)
	{
		for (j = 0; j < 3; ++j)
		{
			printf("%f ", amesh->mVertices[i][j]);
			mesh.vertices.push_back(amesh->mVertices[i][j]);
		}
		printf("\n");
		for (j = 0; j < 3; ++j)
		{
			mesh.normals.push_back(amesh->mNormals[i][j]);
		}
		if (amesh->mTextureCoords[0])
		{
			for (j = 0; j < 2; ++j)
			{
		//		printf("%f ", amesh->mVertices[i][j]);
				mesh.texcoords.push_back(amesh->mTextureCoords[0][i][j]);
			}
		//	printf("\n");
		}
	}

	for (i = 0; i < amesh->mNumFaces; ++i)
	{
		aiFace face = amesh->mFaces[i];
		for (j = 0; j < face.mNumIndices; ++j)
		{
			printf("%u ", face.mIndices[j]);
			mesh.indices.push_back(face.mIndices[j]);
		}
		printf("\n");
	}
}

Mesh Assets::loadMesh(const std::string& fn)
{
	Mesh out;

	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(fn, aiProcess_Triangulate | aiProcess_FlipUVs);
	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
	{
		printf("assimp error: %s\n", importer.GetErrorString());
		return out;
	}

	processNode(out, scene->mRootNode, scene);
	return out;
}

Scene Assets::loadScene(const std::string&)
{
	Scene out;

	return out;
}
