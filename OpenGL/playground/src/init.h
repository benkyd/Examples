#ifndef SRC_INIT_H_
#define SRC_INIT_H_

// General includes
#include <chrono>

// GL includes
#if _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

// Custom includes
#include <logger.h>

bool init(Logger& logger, SDL_Window* window, SDL_GLContext glContext) {
	std::cout << "-----------------------------" << std::endl;
	std::cout << "----- OpenGL Playground -----" << std::endl;
	std::cout << "-------- Version 1.0 --------" << std::endl;
	std::cout << "----- �Benjamin Kyd 2019 ----" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << 								    std::endl;

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

	logger << LOGGER_INFO << "OpenGL and SDL initialized" << LOGGER_ENDL;
    return true;
}

#endif
