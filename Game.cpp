#include "Game.h"
#include <iostream>
#include <string>
#include "Errors.h"


Game::Game() : _x(1024), _y(768), _time(0.0f), _window(nullptr), _gameState(GameState::play), _maxFps(60.0f)
{//_window = nullptr;
	//_x = 1280;
	//_y = 960;
	//_gameState = GameState::play;
}

Game::~Game()
{
}

void Game::run() {
	
	init();
	sprites.push_back(new Sprite());
	sprites.back()->Init(-1.0f, -1.0f, 1.0f, 2.0f, "textures/PNG/CharacterRight_Standing.png");

	sprites.push_back(new Sprite());
	sprites.back()->Init(0.0f, -1.0f, 1.0f, 2.0f, "textures/PNG/CharacterRight_Standing.png");
	Update();
}
void Game::init() {
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	_window = SDL_CreateWindow("Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->_x, this->_y, SDL_WINDOW_OPENGL);
	if (_window == nullptr) {
		fatalError("Sdl window could not load");
	}

	SDL_GLContext context = SDL_GL_CreateContext(_window);
	if (context == nullptr) {
		fatalError("Could not initialize OpenGL");
	}
	glewExperimental = true;
	GLenum error = glewInit();
	if (error != GLEW_OK) {
		fatalError("could not initialize GLEW");
	}
	
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

	initShaders();
	}

void Game::initShaders() 
{
	_colorProgram.compileShaders("shaders/colorshading.vert", "shaders/colorshading.frag");
	_colorProgram.addAttrib("vertexPosition");
	_colorProgram.addAttrib("vertexColor");
	_colorProgram.addAttrib("vertexUV");
	_colorProgram.linkShaders();
}

void Game::Update() {
	while (_gameState != GameState::exit) {
		float startTicks = SDL_GetTicks();
		input();
		_time += 0.01f;
		render();
		calculateFps();
		//print only once 1 second
		static int frameCounter;
		frameCounter++;
		if (frameCounter == 10) {
			std::cout << _fps << std::endl;
			frameCounter = 0;
		}

		float frameTicks = SDL_GetTicks() - startTicks;
		//Limit fps
		if (1000.0 / _maxFps > frameTicks) {
			SDL_Delay(1000.0 / _maxFps - frameTicks);
		}
	}
}

void Game::input() {
	SDL_Event evnt;
	while (SDL_PollEvent(&evnt) == 1) {
		switch (evnt.type) {
		case SDL_QUIT:
			_gameState = GameState::exit;
			break;
		case SDL_MOUSEMOTION:
		//	std::cout << evnt.motion.x << "  " << evnt.motion.y << std::endl;
			break;
		case SDL_KEYDOWN:
		
		
	
		switch (evnt.key.keysym.sym) {
		case SDLK_r:
		

			break;
		case SDLK_g:
		
			break;
		case SDLK_b:
			
			break;
		}
		break;
		}
		
		
	}
}

void Game::render() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	_colorProgram.use();
	glActiveTexture(GL_TEXTURE0);

	GLint texturelocation = _colorProgram.getUniformLocation("character");
	glUniform1i(texturelocation, 0);
	GLint timeLocation = _colorProgram.getUniformLocation("time");
	glUniform1f(timeLocation, _time);
	for (int i = 0; i < sprites.size(); i++)
	{
		sprites[i]->render();
	}

	
	glBindTexture(GL_TEXTURE_2D, 0);
	_colorProgram.unuse();
	SDL_GL_SwapWindow(_window);

}

void Game::calculateFps()
{
	static const int numSamples = 10;
	static float frameTimes[numSamples];
	static int currentFrame = 0;


	static float prevTicks = SDL_GetTicks();
	 float currentTicks;
	 currentTicks = SDL_GetTicks();
	 _frameTime = currentTicks - prevTicks;
	 frameTimes[currentFrame % numSamples] =  _frameTime;

	 prevTicks = currentTicks;

	 int count;

	 currentFrame++;

	 if (currentFrame < numSamples)
	 {
		 count = currentFrame;
	 }
	 else {
		 count = numSamples;
	 }

	 float frameTimeAverage =0;

	 for (int i = 0; i < count; i++) {
		 frameTimeAverage += frameTimes[i];
	 }

	 frameTimeAverage /= count;

	 if (frameTimeAverage > 0) {
		 _fps = 1000.0f / frameTimeAverage;
	 }
	 else {
		 _fps = 70.00000f;
	 }
	 
}