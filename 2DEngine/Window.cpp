#include "Window.h"
#include "fatal.h"
namespace Engine {

	Window::Window()
	{
	}


	Window::~Window()
	{
	}


	int Window::create(std::string windowName, int screenWidth, int screenHeight, unsigned int currentFlag) {

		Uint32 flags = SDL_WINDOW_OPENGL;

		if (currentFlag & INVISIBLE) {
			flags |= SDL_WINDOW_HIDDEN;
		}

		if (currentFlag & FULLSCREEN) {
			flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
		}

		if (currentFlag & BORDERLESS)
		{
			flags |= SDL_WINDOW_BORDERLESS;
		}
		_sdlWindow = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, flags);
		if (_sdlWindow == nullptr) {
			fatalError("Sdl window could not load");
		}

		SDL_GLContext context = SDL_GL_CreateContext(_sdlWindow);
		if (context == nullptr) {
			fatalError("Could not initialize OpenGL");
		}
		glewExperimental = true;
		GLenum error = glewInit();
		if (error != GLEW_OK) {
			fatalError("could not initialize GLEW");
		}
		std::printf("*** OpenGL version %s *** \n", glGetString(GL_VERSION));

		glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

		SDL_GL_SetSwapInterval(0);

		return 0;
	}

	void Window::swapBuffer() {
		SDL_GL_SwapWindow(_sdlWindow);
	}

}