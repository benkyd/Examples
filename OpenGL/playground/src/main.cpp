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
#include "init.h"
#include "timers.h"
#include "object.h"

int main(int argc, char** argv) {
	// Get global variables ready
	Logger logger;
	SDL_Window* window = nullptr;
	SDL_GLContext glContext;
	bool isWindowOpen = false;

	// Initialize SDL and OpenGL
	isWindowOpen = init(logger, window, glContext);

	std::vector<glm::vec4> vertices;
	std::vector<glm::vec3> normals;
	std::vector<GLushort> elements;
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

		// Swap GL frame buffers
		SDL_GL_SwapWindow(window);
	}

	return 0;
}
