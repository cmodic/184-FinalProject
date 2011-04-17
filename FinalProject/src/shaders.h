/*
 * Shaders.h
 *
 *  Created on: March 19, 2009
 *      Author: jima, based on nvidia and lighthouse3D example code.
 */

#ifndef SHADERS_H_
#define SHADERS_H_

#include "global.h"

bool setShader(GLhandleARB p, const char *srcfile, GLenum type);
bool linkAndValidateShader(GLhandleARB p);

// helpful class to set up shader
class Shader {
public:
    Shader(string vertShader, string fragmentShader);
    ~Shader() {
        glDeleteObjectARB(program);
    }

    void toggleShader() { shadersOn = !shadersOn; }
    void toggleBumpMap() { bumpMapEnabled = !bumpMapEnabled; }
    void toggleTextureMap() { textureMapEnabled = !textureMapEnabled; }
    void togglePhong() { phongEnabled = !phongEnabled; }

    GLint getTangentAttrib() { return tangentAttrib; }
    GLint getBitangentAttrib() { return bitangentAttrib; }

    bool on() { return shadersOn; }

    void set(bool forceOff = false) {
        if (!forceOff && on()) {
            glUseProgramObjectARB(program);
            glUniform1iARB(bumpMapEnabledUniform, bumpMapEnabled);
            glUniform1iARB(textureMapEnabledUniform, textureMapEnabled);
            glUniform1iARB(phongEnabledUniform, phongEnabled);
        } else {
            glUseProgramObjectARB(0);
        }
    }

private:
    bool shadersFailed;
    GLhandleARB program; // shaders
    GLint tangentAttrib, bitangentAttrib; // tangent space for uploading to shaders
    GLint bumpMapEnabledUniform, textureMapEnabledUniform, phongEnabledUniform;
    bool bumpMapEnabled, textureMapEnabled, phongEnabled;
    bool shadersOn;
};

#endif 

