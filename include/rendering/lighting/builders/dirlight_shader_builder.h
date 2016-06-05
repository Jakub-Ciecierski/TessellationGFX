//
// Created by jakub on 5/27/16.
//

#ifndef DUCK_DIRLIGHT_SHADER_BUILDER_H
#define DUCK_DIRLIGHT_SHADER_BUILDER_H

#include "light_shader_builder.h"

namespace ifx {

    class DirlightShaderBuilder : public LightShaderBuilder {
    public:
        std::string DIRECTION;

        std::string AMBIENT;
        std::string DIFFUSE;
        std::string SPECULAR;

        DirlightShaderBuilder(int id);

        ~DirlightShaderBuilder();

        virtual void build() override;
    };
}

#endif //DUCK_DIRLIGHT_SHADER_BUILDER_H
