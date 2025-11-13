#pragma once
#include "state.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class PlayState;

class MainMenuState : public State
{
	public:

		MainMenuState(Game& game);

		void handleEvent(sf::Event& event) override;

		void update(float dt) override;

		void render(sf::RenderWindow& window) override;
};
