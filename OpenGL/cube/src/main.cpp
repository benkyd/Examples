#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>

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
                                    400, 400, 
                                    SDL_WINDOW_OPENGL);
	game->glContext = SDL_GL_CreateContext(game->window);

    GLenum GLEWStatus = glewInit();
    if (GLEWStatus != GLEW_OK) {
        std::cerr << "FAILED TO INITALIZE GLEW" << std::endl;
    }

    // SDL_WarpMouseInWindow(m_window, width / 2, height / 2);
	// SDL_SetRelativeMouseMode(SDL_TRUE);
    game->isWindowClosed = false;

    glClearColor(0.1f, 0.45f, 0.9f, 1.0f);

    SDL_Event event;
    while (!game->isWindowClosed) {
        glClear(GL_COLOR_BUFFER_BIT);

        while (SDL_PollEvent(&event) != 0)
            if (event.key.keysym.sym == SDLK_ESCAPE) 
                game->isWindowClosed = true;


        SDL_GL_SwapWindow(game->window);
    }

	game->isWindowClosed = true;
    SDL_GL_DeleteContext(game->glContext);
	SDL_DestroyWindow(game->window);
	SDL_Quit();
}
