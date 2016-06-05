//
// Created by jakub on 5/28/16.
//

#ifndef DUCK_MODEL_LOADER_H
#define DUCK_MODEL_LOADER_H

#include <mesh/model.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

/*
 * Loads Models using Assimp.
 * The Mesh Material shininess is not provided !
 */
class ModelLoader {
private:
    std::string filepath;

    std::string directory;

    /*
     * Multiple meshes may use the same texture.
     * We do not want to load the same texture twice.
     */
    std::vector<Texture> textureCache;

    void checkError(const aiScene* scene,
                    std::string errorString);

    /*
     * Processes each assimp Node recursively
     */
    void processNode(aiNode* node, const aiScene* scene,
                     std::vector<Mesh*>& meshes);

    /*
     * Translates the Assimp::Mesh into ifx::Mesh
     */
    Mesh* processMesh(aiMesh* mesh, const aiScene* scene);

    /*
     * Loads all vertices
     */
    std::vector<Vertex> processVertices(aiMesh *mesh);
    /*
     * Loads all indices
     */
    std::vector<GLuint> processIndices(aiMesh *mesh);
    /*
     * Loads all textures.
     * Uses loadMaterialTextures to load all textures of specific type.
     * Update this function to support more textures types.
     */
    std::vector<Texture> processTextures(aiMesh* mesh, const aiScene* scene);
    /*
     * Loads all texture of specific type e.g. Diffuse or Specular
     */
    std::vector<Texture> loadMaterialTextures(aiMaterial* mat,
                                              aiTextureType type,
                                              TextureTypes texType);

    void printInfo(const Model& model);

public:

    ModelLoader(std::string filepath);

    ~ModelLoader();

    Model loadModel();
};


#endif //DUCK_MODEL_LOADER_H
