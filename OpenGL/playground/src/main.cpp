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
#include <logger.h>
#include "timers.h"
#include "object.h"

int main(int argc, char** argv) {
	std::cout << "-----------------------------" << std::endl;
	std::cout << "----- OpenGL Playground -----" << std::endl;
	std::cout << "-------- Version 1.0 --------" << std::endl;
	std::cout << "----- �Benjamin Kyd 2019 ----" << std::endl;
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
	std::vector<glm::vec4> vertices;
	std::vector<glm::vec3> normals;
	std::vector<GLushort> elements;
	isWindowOpen = true;
	logger << LOGGER_INFO << "OpenGL and SDL initialized" << LOGGER_ENDL;





	LoadOBJ(logger, "./resources/dragon.obj", vertices, normals, elements);

	SDL_Event event;
	while (isWindowOpen) {
		FPSCount(logger);

		// Update tick (60ups)
		if (UPSTimer()) {

		}

		// Handle events
		while (SDL_PollEvent(&event) != 0)
			if (event.type == SDL_QUIT)
				isWindowOpen = false;


		// Clear
		const float clear[] = {0.1f, 0.45f, 0.9f, 1.0f};
		glClearBufferfv(GL_COLOR, 0, clear);
		glClear(GL_DEPTH_BUFFER_BIT);
		// Swap GL frame buffers
		SDL_GL_SwapWindow(window);
	}

	return 0;
}
