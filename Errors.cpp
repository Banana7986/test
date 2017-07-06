#include "Errors.h"
#include <iostream>
#include <cstdlib>
#include <SDL\SDL.h>

void fatalError(std::string errorString) {
	std::cout << errorString << std::endl;
	std::cout << "enter a key to exit" << std::endl;
	int tmp;
	std::cin >> tmp;
	SDL_Quit();
	exit(1);
}