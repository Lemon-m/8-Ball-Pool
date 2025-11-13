#include "Ball.h"
#include "Game.h"
#include "MainMenuState.h"

unsigned int Ball::_ballCount = 0;
static const float pi = 3.141592654f;

int main()
{
	Game game;
	game.pushState(std::make_unique<MainMenuState>(game));
	game.run();
}
 