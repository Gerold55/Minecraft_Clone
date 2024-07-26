#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <GL/glew.h>

class Shader {
public:
    GLuint Program;
    Shader(const char* vertexPath, const char* fragmentPath);
    void use();
private:
    std::string readFile(const char* filePath);
    void checkCompileErrors(GLuint shader, std::string type);
};

#endif // SHADER_H

