#pragma once
#include "state.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "textLabel.h"
#include "popUp.h"

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
		sf::RectangleShape _volumeBarGrey;
		sf::RectangleShape _volumeBarGreen;
		sf::RectangleShape _volumeBarHitbox;
		TextLabel _playButton;
		TextLabel _tutorialButton;
		TextLabel _quitButton;
		TextLabel _volumeLabel;
		TextLabel _volumeValue;
		PopUp _popUp;
		TextLabel _popUpYes;
		TextLabel _popUpNo;
		bool _popUpActive;
		sf::Texture _bgTexture;
		sf::Sprite _bg;
};
