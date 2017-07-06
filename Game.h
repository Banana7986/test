#pragma once
#include <SDL\SDL.h>
#include <GL/glew.h>
#include "Sprite.h"
#include "GLSLprogram.h"
#include "glTexture.h"
#include <vector>

enum  class GameState {
	play,
	exit
};
class Game
{
public:
	Game();
	~Game();

	void run();
	
	
private :
	std::vector<Sprite*> sprites;
	Sprite sprite;
	GameState _gameState;
	void init();
	void initShaders();
	void input();
	void Update();
	void render();
	SDL_Window* _window;
	void calculateFps();


	int _x;
	int _y;
	GLSLprogram _colorProgram;
	float _time;
	float _fps;
	float _maxFps;
	float _frameTime;
};



