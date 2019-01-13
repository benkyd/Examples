#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <fstream>
#include <chrono>
#include <string>
#include <map>

#include "shader.hpp"

void GLAPIENTRY MessageCallback(GLenum source,
                                GLenum type,
                                GLuint id,
                                GLenum severity,
                                GLsizei length,
                                const GLchar* message,
                                const void* userParam) {
  fprintf(stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
           (type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : "" ),
            type, severity, message);
}


class Game {
public:
    SDL_Window* window = nullptr;
    SDL_GLContext glContext = nullptr;
    bool isWindowClosed = true;
};

int main(int argc, char** argv) {
    Game* game = new Game();
    SDL_Init(SDL_INIT_EVERYTHING);

	SDL_GL_SetSwapInterval(0);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	game->window = SDL_CreateWindow("GL CUBE", 
                                    SDL_WINDOWPOS_CENTERED, 
                                    SDL_WINDOWPOS_CENTERED, 
                                    1000, 1000, 
                                    SDL_WINDOW_OPENGL);
	game->glContext = SDL_GL_CreateContext(game->window);

    GLenum GLEWStatus = glewInit();
    if (GLEWStatus != GLEW_OK) {
        std::cerr << "FAILED TO INITALIZE GLEW" << std::endl;
        return 0;
    }

    // SDL_WarpMouseInWindow(m_window, width / 2, height / 2);
	// SDL_SetRelativeMouseMode(SDL_TRUE);

    game->isWindowClosed = false;

    // Set GL error handling callback
    // glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(MessageCallback, 0);

    // Set GL clear colour (light blue)
    glClearColor(0.1f, 0.45f, 0.9f, 1.0f);

    // GL Screen coordinates of a 2D triangle followed by the colour and the texture coordinates
    GLint numOfVerticies = 28;
    float vertices[] = {
    //  Positions       Colour               Texture 
       -0.5f,  0.5f,    1.0f, 0.0f, 0.0f,    0.0f, 0.0f, // Top-left
        0.5f,  0.5f,    0.0f, 1.0f, 0.0f,    1.0f, 0.0f, // Top-right
        0.5f, -0.5f,    0.0f, 0.0f, 1.0f,    1.0f, 1.0f, // Bottom-right
       -0.5f, -0.5f,    1.0f, 1.0f, 1.0f,    0.0f, 1.0f, // Bottom-left
    };

    // Element array - order of verticies drawn
    GLuint elements[] = {
        0, 1, 2,
        2, 3, 0
    };

    // Generate a vertex array object
    GLuint vao;
    glGenVertexArrays(1, &vao);
    // Bind array to GPU
    glBindVertexArray(vao);

    // Generate a vertex buffer object
    GLuint vbo;
    glGenBuffers(1, &vbo);
    // Bind buffer to the GPU
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    // Copy vertex data to the vertex buffer already on the GPU
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * numOfVerticies, vertices, GL_STATIC_DRAW);

    // Generate another vertex buffer for the element array buffer
    GLuint ebo;
    glGenBuffers(1, &ebo);
    // Bind buffer to the GPU
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    // Copy buffer data to the buffer already on the GPU
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);

    // Load, compile, apply and link shader programs
    Shader simpleShader;
    simpleShader.load("./resources/shaders/simple").attatch().link().use();

    // Load texture from file
    SDL_Surface* sur = IMG_Load("./resources/textures/dirtside.jpg");
    // Set up a GL texture
    GLuint tex;
    glBindTexture(GL_TEXTURE_2D, tex);
    // it won't work without this idk why yet
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    // Passes SDL texture into the texture buffer for GL to use in shaders
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, sur->w, sur->h, 0, GL_RGB, GL_UNSIGNED_BYTE, sur->pixels);

    GLint posAttrib = glGetAttribLocation(simpleShader.getProgram(), "position");
    glEnableVertexAttribArray(posAttrib);
    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE,
                        7*sizeof(float), 0);

    GLint colAttrib = glGetAttribLocation(simpleShader.getProgram(), "colour");
    glEnableVertexAttribArray(colAttrib);
    glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE,
                        7*sizeof(float), (void*)(2*sizeof(float)));

    GLint texAttrib = glGetAttribLocation(simpleShader.getProgram(), "texcoord");
    glEnableVertexAttribArray(texAttrib);
    glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE,
                       7*sizeof(float), (void*)(5*sizeof(float)));

    GLint triangleUniColour = glGetUniformLocation(simpleShader.getProgram(), "triangleColour");
    glUniform3f(triangleUniColour, 0.2f, 0.8f, 0.3f);

    SDL_Event event;
    while (!game->isWindowClosed) {
        // Input handling
        while (SDL_PollEvent(&event) != 0)
            if (event.key.keysym.sym == SDLK_ESCAPE || event.type == SDL_QUIT) 
                game->isWindowClosed = true;

        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT);
        // Draw a triangle from the 3 vertices
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        // Swap buffers
        SDL_GL_SwapWindow(game->window);
    }

	game->isWindowClosed = true;
    SDL_GL_DeleteContext(game->glContext);
	SDL_DestroyWindow(game->window);
	SDL_Quit();

    return 0;
}
