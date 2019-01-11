#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <fstream>
#include <chrono>
#include <string>
#include <map>

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

std::map<std::string, GLuint> VertexShaders;
std::map<std::string, GLuint> FragmentShaders;
std::map<std::string, GLuint> ShaderPrograms;

std::string readShader(std::string source) {
    std::ifstream t(source);
    std::string shaderCode((std::istreambuf_iterator<char>(t)),
                            std::istreambuf_iterator<char>());
    // std::cout << shaderCode << std::endl;
    return shaderCode;
}

bool loadShader(std::string shaderSource, GLenum type, std::string shader) {
    const char* source = shaderSource.c_str();

    if (type == GL_VERTEX_SHADER) {
        GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &source, NULL);
        glCompileShader(vertexShader);

        GLint status;
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);
        if (status == GL_FALSE) {
            char buf[512];
            glGetShaderInfoLog(vertexShader, 512, NULL, buf);
            std::cerr << buf << std::endl;
            return false;
        }

        VertexShaders[shader] = vertexShader;
        std::cout << "Vertex shader at '" << shader << "' compiled..." << std::endl;
    } else if (type == GL_FRAGMENT_SHADER) {
        GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &source, NULL);
        glCompileShader(fragmentShader);

        GLint status;
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &status);
        if (status == GL_FALSE) {
            char buf[512];
            glGetShaderInfoLog(fragmentShader, 512, NULL, buf);
            std::cerr << buf << std::endl;
            return false;
        }

        FragmentShaders[shader] = fragmentShader;
        std::cout << "Fragment shader at '" << shader << "' compiled..." << std::endl;
    }
    return true;
}

void makeShaderProgram(std::string vert, std::string frag, std::string program) {
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, VertexShaders[vert]);
    glAttachShader(shaderProgram, FragmentShaders[frag]);
    ShaderPrograms[program] = shaderProgram;
    std::cout << "Shader program '" << program << "' created" << std::endl;
}

void applyShader(std::string shader) {
    glLinkProgram(ShaderPrograms[shader]);
    glUseProgram(ShaderPrograms[shader]);
    std::cout << "Shader program '" << shader << "' applied" << std::endl;
}

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
                                    400, 400, 
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

    // GL Screen coordinates of a 2D triangle followed by the colour
    GLint numOfVerticies = 15;
    float vertices[] = {
        0.0f,  0.5f,    1.0f, 0.0f, 0.0f, // Vertex 1: (X, Y,  R, G, B)
        0.5f, -0.5f,    0.0f, 1.0f, 0.0f, // Vertex 2: (X, Y,  R, G, B)
       -0.5f, -0.5f,    0.0f, 0.0f, 1.0f  // Vertex 3: (X, Y,  R, G, B)
    };

    // Generate a vertex array object
    GLuint vao;
    glGenVertexArrays(1, &vao);
    // Bind array to GPU
    glBindVertexArray(vao);

    // Generate a vertex buffer object
    GLuint vbo;
    glGenBuffers(1, &vbo);
    // Binding buffer to GPU
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    // Copy vertex data to the vertex buffer already on the GPU
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * numOfVerticies, vertices, GL_STATIC_DRAW);

    // Load, compile, apply and link shader programs
    if (!loadShader(readShader("shaders/simple.vert"), GL_VERTEX_SHADER  , "simpleVert") ||
        !loadShader(readShader("shaders/simple.frag"), GL_FRAGMENT_SHADER, "simpleFrag")) {
        return 0;
    }
    makeShaderProgram("simpleVert", "simpleFrag", "simpleProc");
    applyShader("simpleProc");

    GLint posAttrib = glGetAttribLocation(ShaderPrograms["simpleProc"], "position");
    glEnableVertexAttribArray(posAttrib);
    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE,
                        5*sizeof(float), 0);

    GLint colAttrib = glGetAttribLocation(ShaderPrograms["simpleProc"], "colour");
    glEnableVertexAttribArray(colAttrib);
    glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE,
                        5*sizeof(float), (void*)(2*sizeof(float)));

    GLint triangleUniColour = glGetUniformLocation(ShaderPrograms["simpleProc"], "triangleColour");
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
        glDrawArrays(GL_TRIANGLES, 0, 3);
        // Swap buffers
        SDL_GL_SwapWindow(game->window);
    }

	game->isWindowClosed = true;
    SDL_GL_DeleteContext(game->glContext);
	SDL_DestroyWindow(game->window);
	SDL_Quit();

    return 0;
}
