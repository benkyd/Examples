#include "shader.hpp"

#include <iostream>
#include <fstream>

Shader::Shader() {
    m_program = glCreateProgram();
}

Shader& Shader::use() {
    glUseProgram(m_program);
    return *this;
}

Shader& Shader::link() {
    glLinkProgram(m_program);
    return *this;
}

Shader& Shader::attatch() {
    glAttachShader(m_program, m_vert);
    glAttachShader(m_program, m_frag);
    return *this;
}

std::string readShader(std::string source) {
    std::ifstream t(source);
    std::string shaderCode((std::istreambuf_iterator<char>(t)),
                            std::istreambuf_iterator<char>());
    return shaderCode;
}

Shader& Shader::load(GLenum type, std::string sourceLoc) {
    const char* source = readShader(sourceLoc).c_str();

    if (type == GL_VERTEX_SHADER) {
        m_vertLoc = sourceLoc;
        m_vertSource = (std::string)source;
        m_vert = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(m_vert, 1, &source, NULL);
        glCompileShader(m_vert);

        glGetShaderiv(m_vert, GL_COMPILE_STATUS, &m_status);
        if (m_status == GL_FALSE) {
            char buf[512];
            glGetShaderInfoLog(m_vert, 512, NULL, buf);
            std::cerr << buf << std::endl;
        }

        std::cout << "Vertex shader at '" << sourceLoc << "' compiled..." << std::endl;
    } else if (type == GL_FRAGMENT_SHADER) {
        m_fragLoc = sourceLoc;
        m_fragSource = (std::string)source;
        m_frag = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(m_frag, 1, &source, NULL);
        glCompileShader(m_frag);
        
        glGetShaderiv(m_frag, GL_COMPILE_STATUS, &m_status);
        if (m_status == GL_FALSE) {
            char buf[512];
            glGetShaderInfoLog(m_frag, 512, NULL, buf);
            std::cerr << buf << std::endl;
        }

        std::cout << "Vertex shader at '" << sourceLoc << "' compiled..." << std::endl;
    }

    return *this;
}

Shader& Shader::load(std::string sourceLoc) {
    m_vertLoc = sourceLoc + ".vert";
    m_fragLoc = sourceLoc + ".frag";

    m_vertSource = readShader(m_vertLoc);
    m_fragSource = readShader(m_fragLoc);

    m_vert = glCreateShader(GL_VERTEX_SHADER);
    m_frag = glCreateShader(GL_FRAGMENT_SHADER);

    const char* vertSource = m_vertSource.c_str();
    glShaderSource(m_vert, 1, &vertSource, NULL);
    glCompileShader(m_vert);

    const char* fragSource = m_fragSource.c_str();
    glShaderSource(m_frag, 1, &fragSource, NULL);
    glCompileShader(m_frag);

    glGetShaderiv(m_vert, GL_COMPILE_STATUS, &m_status);
    if (m_status == GL_FALSE) {
        char buf[512];
        glGetShaderInfoLog(m_vert, 512, NULL, buf);
        std::cerr << buf << std::endl;
    }

    glGetShaderiv(m_frag, GL_COMPILE_STATUS, &m_status);
    if (m_status == GL_FALSE) {
        char buf[512];
        glGetShaderInfoLog(m_frag, 512, NULL, buf);
        std::cerr << buf << std::endl;
    }

    std::cout << "Vertex shader at '" << m_vertLoc << "' compiled..." << std::endl;
    std::cout << "Fragment shader at '" << m_fragLoc << "' compiled..." << std::endl;
    return *this;
}

GLuint Shader::getProgram() {
    return m_program;
}

GLuint Shader::getVertex() {
    return m_vert;
}

GLuint Shader::getFragment() {
    return m_frag;
}

Shader::~Shader() {
    glDeleteProgram(m_program);
    glDeleteShader(m_vert);
    glDeleteShader(m_frag);
}
