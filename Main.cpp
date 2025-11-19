#define NOMINMAX
#include <windows.h>
#include "Game.h"
#include "MainMenuState.h"

static const float pi = 3.141592654f;

int main()
{
	HWND consoleWindow = GetConsoleWindow();
	ShowWindow(consoleWindow, SW_HIDE);

	Game game;
	game.pushState(std::make_unique<MainMenuState>(game));
	game.run();
}
 