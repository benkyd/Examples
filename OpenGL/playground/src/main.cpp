// General includes
#include <chrono>
#include <vector>

// GL includes
#include <glad/glad.h>

// SDL includes different on windows
// the way i have it set up so i gotta
// do it like this unfortunately 
#if _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Custom includes
#define LOGGER_DEFINITION
#include <logger.h>
#include "timers.h"
#include "object.h"
#include "shader.h"

int main(int argc, char** argv) {
	std::cout << "-----------------------------" << std::endl;
	std::cout << "----- OpenGL Playground -----" << std::endl;
	std::cout << "-------- Version 1.0 --------" << std::endl;
	std::cout << "----- ©Benjamin Kyd 2019 ----" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << 								    std::endl;

	// Get global variables ready
	Logger logger;
	SDL_Window* window = nullptr;
	SDL_GLContext glContext;
	bool isWindowOpen = false;

	// Initialize SDL and OpenGL
	// isWindowOpen = init(logger, window, glContext);
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);

	window = SDL_CreateWindow("OpenGL Playground V1.0",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		1280, 720,
		SDL_WINDOW_OPENGL);
	glContext = SDL_GL_CreateContext(window);
	SDL_GL_SetSwapInterval(0);

	gladLoadGLLoader(SDL_GL_GetProcAddress);
	isWindowOpen = true;
	logger << LOGGER_INFO << "OpenGL and SDL initialized" << LOGGER_ENDL;



	// Load an object into system memory
	std::vector<glm::vec4> vertices;
	std::vector<glm::vec3> normals;
	std::vector<GLushort> elements;

	LoadOBJ(logger, "./resources/dragon.obj", vertices, normals, elements);

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
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec4), &vertices[0], GL_STATIC_DRAW);

	// Generate another vertex buffer for the element array buffer
	GLuint ebo;
	glGenBuffers(1, &ebo);
	// Bind buffer to the GPU
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	// Copy buffer data to the buffer already on the GPU
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, elements.size() * sizeof(GLushort), &elements[0], GL_STATIC_DRAW);

	// Load, compile, apply and link shader programs
	Shader simpleShader{ logger };
	simpleShader.load("./resources/shaders/simple").attatch().link().use();

	GLint posAttrib = glGetAttribLocation(simpleShader.getProgram(), "position");
	glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(posAttrib, 4, GL_FLOAT, GL_FALSE, 0, 0);

	// Model matrice
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, {-12.0f, -20.0f, -20.0f});
	// Gets uniform for model matrice, to be used later
	GLint uniTrans = glGetUniformLocation(simpleShader.getProgram(), "model");

	// View matrice
	glm::mat4 view = glm::lookAt(
		glm::vec3(1.0f, 1.0f, 1.0f),
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 0.0f, 1.0f)
	);
	// Get uniform and send it to the GPU
	GLint uniView = glGetUniformLocation(simpleShader.getProgram(), "view");
	glUniformMatrix4fv(uniView, 1, GL_FALSE, glm::value_ptr(view));

	// Projection matrice
	glm::mat4 proj = glm::perspective(glm::radians(45.0f), 1280.0f / 720.0f, 1.0f, 1000.0f);
	// Get uniform and send it to the GPU    
	GLint uniProj = glGetUniformLocation(simpleShader.getProgram(), "proj");
	glUniformMatrix4fv(uniProj, 1, GL_FALSE, glm::value_ptr(proj));


	glEnable(GL_DEPTH_TEST);

	SDL_Event event;
	while (isWindowOpen) {
		FPSCount(logger);

		// Update tick (60ups)
		if (UPSTimer()) {
			model = glm::rotate(model, glm::radians(1.0f), glm::vec3(0.0f, 0.0f, 1.0f));
			model = glm::rotate(model, glm::radians(1.0f), glm::vec3(1.0f, 0.0f, 0.0f));
			glm::vec4 result = model * glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
			glUniformMatrix4fv(uniTrans, 1, GL_FALSE, glm::value_ptr(model));

			UpdateClock = SDL_GetTicks();
		}

		// Handle events
		while (SDL_PollEvent(&event) != 0)
			if (event.type == SDL_QUIT)
				isWindowOpen = false;

		// Clear
		const float clear[] = {0.1f, 0.45f, 0.9f, 1.0f};
		glClearBufferfv(GL_COLOR, 0, clear);
		glClear(GL_DEPTH_BUFFER_BIT);
		// Draw
		glDrawElements(GL_TRIANGLES, elements.size(), GL_UNSIGNED_SHORT, 0);
		// Swap
		SDL_GL_SwapWindow(window);
	}

	return 0;
}
