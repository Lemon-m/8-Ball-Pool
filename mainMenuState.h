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

	protected:

		sf::Text _title;

		sf::Text _playButton;

		sf::Text _tutorialButton;

		sf::Text _quitButton;

		sf::Texture _bgTexture;

		sf::Sprite _bg;
};
