//
// Created by jakub on 5/24/16.
//

#ifndef DUCK_PROGRAM_H
#define DUCK_PROGRAM_H

#include "fragment_shader.h"
#include "vertex_shader.h"
#include "tess_control_shader.h"
#include "tess_eval_shader.h"

/*
 * This class encapsulates all shaders and is used to draw Meshes
 */
class Program {
private:
    GLuint id;

    void linkShaders(VertexShader &vertexShader,
                     FragmentShader &fragmentShader);
    void linkShaders(VertexShader &vertexShader,
                     FragmentShader &fragmentShader,
                     TessControlShader& tessControlShader,
                     TessEvalShader& tessEvalShader);
public:

    Program();
    Program(VertexShader& vertexShader, FragmentShader& fragmentShader);
    Program(VertexShader& vertexShader, FragmentShader& fragmentShader,
            TessControlShader& tessControlShader,
            TessEvalShader& tessEvalShader);

    ~Program();

    void use() const;

    GLuint getID() const;
};


#endif //DUCK_PROGRAM_H
