// General includes
#include <chrono>

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

int main(int argc, char** argv) {
	std::cout << "----- OpenGL Playground -----" << std::endl;
	std::cout << "-------- Version 1.0 --------" << std::endl;
	std::cout << "----- ©Benjamin Kyd 2019 ----" << std::endl << std::endl;

	// Get global variables ready
	Logger logger;
	SDL_Window* window = nullptr;
	SDL_GLContext glContext;
	bool isWindowClosed = true;

	logger << LOGGER_DEBUG << "debug" << LOGGER_ENDL;
	logger << LOGGER_INFO << "info" << LOGGER_ENDL;
	logger << LOGGER_WARN << "warn" << LOGGER_ENDL;
	logger << LOGGER_ERROR << "error" << LOGGER_ENDL;
	logger << LOGGER_PANIC << "panic" << LOGGER_ENDL << LOGGER_ENDL;

	// Initialize SDL and OpenGL
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

	window = SDL_CreateWindow("OpenGL Playground V1.0",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		1000, 1000,
		SDL_WINDOW_OPENGL);
	glContext = SDL_GL_CreateContext(window);
	SDL_GL_SetSwapInterval(0);

	gladLoadGLLoader(SDL_GL_GetProcAddress);
	isWindowClosed = false;

	logger << LOGGER_INFO << "OpenGL and SDL initialized" << LOGGER_ENDL;



	// Various timers needed for FPS counting
	std::chrono::high_resolution_clock timer;
	auto FPSCalculateLast = timer.now();
	auto FPSClock = SDL_GetTicks();

	auto UpdateClock = SDL_GetTicks();

	SDL_Event event;
	while (!isWindowClosed) {
		// Calculate and display framerate
		if (SDL_GetTicks() - FPSClock >= 1000) {
			auto deltaTime = std::chrono::duration_cast<std::chrono::nanoseconds>(timer.now() - FPSCalculateLast).count();
			logger << LOGGER_INFO << "FPS: " << (int)(1 / ((float)deltaTime * 1e-9)) << LOGGER_ENDL;
			FPSClock = SDL_GetTicks();
		}
		FPSCalculateLast = timer.now();

		// Update tick
		if (SDL_GetTicks() - UpdateClock >= 10) {

		}

		// Handle events
		while (SDL_PollEvent(&event) != 0)
			if (event.type == SDL_QUIT)
				isWindowClosed = true;

		// Swap GL frame buffers
		SDL_GL_SwapWindow(window);
	}

	return 0;
}
