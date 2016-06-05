//
// Created by jakub on 5/27/16.
//

#include "light_loader.h"

LightLoader::LightLoader(){

}

LightLoader::~LightLoader() {

}

LightPoint *LightLoader::loadPointLight() {
    LightPoint* lightSource = new LightPoint();

    Light light;
    light.ambient = glm::vec3(0.2f, 0.2f, 0.2f);
    light.diffuse = glm::vec3(0.5f, 0.5f, 0.5f);
    light.specular= glm::vec3(1.0f, 1.0f, 1.0f);

    light.constant = 1.0f;
    light.linear = 0.09f;
    light.quadratic = 0.032;

    lightSource->setLight(light);

    return lightSource;
}

LightDirectional* LightLoader::loadDirLight() {
    LightDirectional* lightSource = new LightDirectional();

    Light light;
    light.ambient = glm::vec3(0.2f, 0.2f, 0.2f);
    light.diffuse = glm::vec3(0.5f, 0.5f, 0.5f);
    light.specular= glm::vec3(1.0f, 1.0f, 1.0f);

    light.constant = 1.0f;
    light.linear = 0.09f;
    light.quadratic = 0.032;

    light.cutOff = 22.5f;
    light.outerCutOff = 27.5f;

    lightSource->setLight(light);

    lightSource->setPosition(glm::vec3(0.0f, 100.0f, 0.0f));
    lightSource->setLookAt(glm::vec3(0.0f, 0.0f, 0.0f));
    lightSource->setFollow(false);

    return lightSource;
}

LightSpotlight* LightLoader::loadSpotlight() {
    LightSpotlight* lightSource = new LightSpotlight();

    Light light;
    //light.ambient = glm::vec3(0.2f, 0.2f, 0.2f);
    //light.diffuse = glm::vec3(0.5f, 0.5f, 0.5f);
    light.ambient = glm::vec3(0.9f, 0.9f, 0.9f);
    light.diffuse = glm::vec3(0.9f, 0.9f, 0.9f);
    light.specular= glm::vec3(1.0f, 1.0f, 1.0f);

    light.constant = 1.0f;
    light.linear = 0.09f;
    light.quadratic = 0.032;

    light.cutOff = 22.5f;
    light.outerCutOff = 27.5f;

    lightSource->setLight(light);

    lightSource->setLookAt(glm::vec3(0.0f, 0.0f, 0.0f));
    return lightSource;
}