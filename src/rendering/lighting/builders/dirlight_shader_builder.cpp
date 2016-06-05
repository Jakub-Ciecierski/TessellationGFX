//
// Created by jakub on 5/27/16.
//

#include <lighting/builders/light_shader_common_data.h>
#include "dirlight_shader_builder.h"

using namespace ifx;

ifx::DirlightShaderBuilder::DirlightShaderBuilder(int id) :
        LightShaderBuilder(id){

}

ifx::DirlightShaderBuilder::~DirlightShaderBuilder() {

}

void ifx::DirlightShaderBuilder::build() {
    DIRECTION= appendToBase(id,
                            LIGHT_DIRLIGHT_NAME,
                            LIGHT_DIRECTION_NAME);

    AMBIENT = appendToBase(id,
                           LIGHT_DIRLIGHT_NAME,
                           LIGHT_AMBIENT_NAME);
    DIFFUSE = appendToBase(id,
                           LIGHT_DIRLIGHT_NAME,
                           LIGHT_DIFFUSE_NAME);
    SPECULAR = appendToBase(id,
                            LIGHT_DIRLIGHT_NAME,
                            LIGHT_SPECULAR_NAME);
}
