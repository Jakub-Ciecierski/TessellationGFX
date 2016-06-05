//
// Created by jakub on 5/24/16.
//

#ifndef DUCK_MESH_H
#define DUCK_MESH_H


#include "shaders/program.h"
#include "buffers/vbo.h"
#include "buffers/vao.h"
#include "mesh_data.h"

#include <GL/gl.h>
#include <vector>

#include <iostream>

/*
 * Contains the geometry of an object.
 * Vertices, indices, textures and material is defined.
 *
 * One instance of the same Mesh should be present in the system.
 * Use Multiple RenderObjects to bind the same Mesh
 */
class Mesh {
private:
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    std::vector<Texture> textures;
    GLenum drawingMode;

    GLenum polygonMode;

    Material material;

    VAO* vao;
    VBO* vbo;
    EBO* ebo;

    /*
     * Checks for errors in the Mesh class and throws exceptions;
     */
    void checkError();

    /*
     * Copy contructor/operator=
     */
    void copy(const Mesh& other);

    /*
     * Computes the Tanget Basis for all faces
     */
    void computeTangetBasis();

    /*
     * Computes Tanget Basis for the face represented by the vertices
     */
    void computeAndStoreTangetBasis(Vertex& v1, Vertex& v2, Vertex& v3);

    void initBuffers();

    /*
     * Binds all textures during draw operation
     */
    void bindTextures(const Program& program);
    void bindColor(const Program& program);
public:

    Mesh();
    Mesh(std::vector<Vertex> vertices,
         std::vector <GLuint>& indices,
         GLenum drawingMode = GL_TRIANGLES,
         GLenum polygonMode = GL_FILL);

    Mesh(std::vector<Vertex> vertices,
         std::vector <GLuint>& indices,
         std::vector<Texture>& textures,
         GLenum drawingMode = GL_TRIANGLES,
         GLenum polygonMode = GL_FILL);

    Mesh(std::vector<Vertex> vertices,
         std::vector <GLuint>& indices,
         std::vector<Texture>& textures,
         Material material,
         GLenum drawingMode  = GL_TRIANGLES,
         GLenum polygonMode = GL_FILL);

    Mesh(const Mesh& mesh);

    virtual ~Mesh();

    void setPolygonMode(GLenum polygonMode);
    void setDrawingMode(GLenum drawingMode);
    void setMaterial(const Material& material);

    void addTexture(Texture texture);

    std::vector<Texture*> getTextures(TextureTypes type);
    std::vector<Vertex> getVertices();

    virtual void draw(const Program& program);

    std::string toString() const;

    Mesh& operator=(const Mesh& other);
};

#endif //DUCK_MESH_H
