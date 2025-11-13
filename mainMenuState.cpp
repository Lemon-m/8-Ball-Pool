#include "mainMenuState.h"
#include "game.h"
#include "playState.h"
#include <memory>
#include <stack>

MainMenuState::MainMenuState(Game& game) : State(game) { }

void MainMenuState::handleEvent(sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
	{
		_game.changeState(std::make_unique<PlayState>(_game));
	}
		
}

void MainMenuState::update(float dt)
{
}

void MainMenuState::render(sf::RenderWindow& window)
{
}
