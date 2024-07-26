#ifndef CUBE_H
#define CUBE_H

#include <GL/glew.h>

class Cube {
public:
    Cube();
    ~Cube();
    void draw();
private:
    GLuint VAO, VBO;
};

#endif // CUBE_H

