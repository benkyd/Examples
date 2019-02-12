#include <iostream>
#include <glad/glad.h>
#ifdef _WIN32
#include <SDL.h>
#include <SDL_image.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#endif
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <fstream>
#include <chrono>
#include <string>
#include <map>

#include "shader.hpp"

// void GLAPIENTRY MessageCallback(GLenum source,
//                                 GLenum type,
//                                 GLuint id,
//                                 GLenum severity,
//                                 GLsizei length,
//                                 const GLchar* message,
//                                 const void* userParam) {
//   fprintf(stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
//            (type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : "" ),
//             type, severity, message);
// }

class Game {
public:
    SDL_Window* window = nullptr;
    SDL_GLContext glContext = nullptr;
    bool isWindowClosed = true;
};

int main(int argc, char** argv) {
    Game* game = new Game();

    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

	game->window = SDL_CreateWindow("GL CUBE", 
                                    SDL_WINDOWPOS_CENTERED, 
                                    SDL_WINDOWPOS_CENTERED, 
                                    500, 500, 
                                    SDL_WINDOW_OPENGL);
	game->glContext = SDL_GL_CreateContext(game->window);
	SDL_GL_SetSwapInterval(0);

    gladLoadGLLoader(SDL_GL_GetProcAddress);

    // SDL_WarpMouseInWindow(m_window, width / 2, height / 2);
	// SDL_SetRelativeMouseMode(SDL_TRUE);

    game->isWindowClosed = false;

    // Set GL error handling callback
    // glEnable(GL_DEBUG_OUTPUT);
    // glDebugMessageCallback(MessageCallback, 0);

    // Set GL clear colour (light blue)
    glClearColor(0.1f, 0.45f, 0.9f, 1.0f);

    // GL Screen coordinates of a 2D triangle followed by the colour and the texture coordinates
    GLint numOfVerticies = 288;
    float vertices[] = {
    //  Positions               Colour               Texture 
        -0.5f, -0.5f, -0.5f,    1.0f, 1.0f, 1.0f,    0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,    1.0f, 1.0f, 1.0f,    1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,    1.0f, 1.0f, 1.0f,    1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,    1.0f, 1.0f, 1.0f,    1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,    1.0f, 1.0f, 1.0f,    0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,    1.0f, 1.0f, 1.0f,    0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,    1.0f, 1.0f, 1.0f,    0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,    1.0f, 1.0f, 1.0f,    1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,    1.0f, 1.0f, 1.0f,    1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,    1.0f, 1.0f, 1.0f,    1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,    1.0f, 1.0f, 1.0f,    0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,    1.0f, 1.0f, 1.0f,    0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,    1.0f, 1.0f, 1.0f,    1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,    1.0f, 1.0f, 1.0f,    1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,    1.0f, 1.0f, 1.0f,    0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,    1.0f, 1.0f, 1.0f,    0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,    1.0f, 1.0f, 1.0f,    0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,    1.0f, 1.0f, 1.0f,    1.0f, 0.0f,

         0.5f,  0.5f,  0.5f,    1.0f, 1.0f, 1.0f,    1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,    1.0f, 1.0f, 1.0f,    1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,    1.0f, 1.0f, 1.0f,    0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,    1.0f, 1.0f, 1.0f,    0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,    1.0f, 1.0f, 1.0f,    0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,    1.0f, 1.0f, 1.0f,    1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,    1.0f, 1.0f, 1.0f,    0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,    1.0f, 1.0f, 1.0f,    1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,    1.0f, 1.0f, 1.0f,    1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,    1.0f, 1.0f, 1.0f,    1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,    1.0f, 1.0f, 1.0f,    0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,    1.0f, 1.0f, 1.0f,    0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,    1.0f, 1.0f, 1.0f,    0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,    1.0f, 1.0f, 1.0f,    1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,    1.0f, 1.0f, 1.0f,    1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,    1.0f, 1.0f, 1.0f,    1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,    1.0f, 1.0f, 1.0f,    0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,    1.0f, 1.0f, 1.0f,    0.0f, 1.0f
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
    SDL_Surface* sur = IMG_Load("./resources/textures/dirt.png");
    if (sur == NULL) {
        std::cerr << "Failed to load image: " << IMG_GetError() << std::endl;
    } else {
        std::cout << "Loaded texture 'dirt.png'" << std::endl;
    }
    // Set up a GL texture
    GLuint tex;
	glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    // Set mag and min filtering levels
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    // Passes SDL texture into the texture buffer for GL to use in shaders
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, sur->w, sur->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, sur->pixels);

    GLint posAttrib = glGetAttribLocation(simpleShader.getProgram(), "position");
    glEnableVertexAttribArray(posAttrib);
    glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE,
                        8*sizeof(float), 0);

    GLint colAttrib = glGetAttribLocation(simpleShader.getProgram(), "colour");
    glEnableVertexAttribArray(colAttrib);
    glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE,
                        8*sizeof(float), (void*)(3*sizeof(float)));

    GLint texAttrib = glGetAttribLocation(simpleShader.getProgram(), "texcoord");
    glEnableVertexAttribArray(texAttrib);
    glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE,
                        8*sizeof(float), (void*)(6*sizeof(float)));


    // Model matrice
    glm::mat4 model = glm::mat4(1.0f);
    // Gets uniform for model matrice, to be used later
    GLint uniTrans = glGetUniformLocation(simpleShader.getProgram(), "model");

    // View matrice
    glm::mat4 view = glm::lookAt(
        glm::vec3(1.2f, 1.2f, 1.2f),
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(0.0f, 0.0f, 1.0f)
    );
    // Get uniform and send it to the GPU
    GLint uniView = glGetUniformLocation(simpleShader.getProgram(), "view");
    glUniformMatrix4fv(uniView, 1, GL_FALSE, glm::value_ptr(view));

    // Projection matrice
    glm::mat4 proj = glm::perspective(glm::radians(45.0f), 1.0f, 1.0f, 10.0f);
    // Get uniform and send it to the GPU    
    GLint uniProj = glGetUniformLocation(simpleShader.getProgram(), "proj");
    glUniformMatrix4fv(uniProj, 1, GL_FALSE, glm::value_ptr(proj));

    // Enable depth buffer
    glEnable(GL_DEPTH_TEST);

    std::chrono::high_resolution_clock timer;
    auto FPSCalculateLast = timer.now();
    auto FPSClock = SDL_GetTicks();

    auto UpdateClock = SDL_GetTicks();

    SDL_Event event;
    while (!game->isWindowClosed) {
        // Measure fps
        if (SDL_GetTicks() - FPSClock >= 1000) {
            auto deltaTime = std::chrono::duration_cast<std::chrono::nanoseconds>(timer.now() - FPSCalculateLast).count();
            std::cout << "FPS: " << (int)(1 / ((float)deltaTime * 1e-9)) << std::endl;
            FPSClock = SDL_GetTicks();
        }
        FPSCalculateLast = timer.now();

        // Input handling
        while (SDL_PollEvent(&event) != 0)
            if (event.type == SDL_QUIT) 
                game->isWindowClosed = true;

        // Rotate cube
        if (SDL_GetTicks() - UpdateClock >= 10) {
            model = glm::rotate(model, glm::radians(1.0f), glm::vec3(0.0f, 0.0f, 1.0f));
            model = glm::rotate(model, glm::radians(1.0f), glm::vec3(1.0f, 0.0f, 0.0f));
            glm::vec4 result = model * glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
            glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(model));
            UpdateClock = SDL_GetTicks();
        }

        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // Draw a triangle from the 3 vertices
        // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        // Swap buffers
        SDL_GL_SwapWindow(game->window);
    }

	game->isWindowClosed = true;
    SDL_GL_DeleteContext(game->glContext);
	SDL_DestroyWindow(game->window);
	SDL_Quit();

    return 0;
}
