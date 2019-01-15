#ifndef _SHADER_H_
#define _SHADER_H_

#include <glad/glad.h>
#include <string>

class Shader {
public:
    Shader();

    Shader& use();
    Shader& link();
    Shader& attatch();
    Shader& load(GLenum type, std::string sourceLoc);
    Shader& load(std::string sourceLoc);

    GLuint getProgram();
    GLuint getVertex();
    GLuint getFragment();

    virtual ~Shader();
private:
    Shader(Shader const &) = delete;
    Shader & operator=(Shader const &) = delete;
  
    GLuint m_program;
    GLuint m_vert;
    GLuint m_frag;

    std::string m_vertSource;
    std::string m_fragSource;
    std::string m_vertLoc;
    std::string m_fragLoc;

    GLint m_status;
};

#endif
