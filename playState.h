#pragma once
#include "state.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "game.h"
#include "ball.h"
#include "cueBall.h"
#include "table.h"
#include "turn.h"
#include "player.h"
#include "textLabel.h"
#include "popUp.h"

class PlayState : public State
{
	public:
		PlayState(Game& game);

		void handleEvent(sf::Event& event) override;

		void update(float dt) override;

		void render(sf::RenderWindow& window) override;

	protected:

		Player p1, p2;
		std::vector<int> scoredSolids, scoredStripes;
		std::vector<sf::Sprite> scoredSolidsUI, scoredStripesUI;
		std::vector<Ball> balls;
		Turn turn;
		CueBall cueBall;
		Table table;
		sf::Texture bgTexture;
		sf::Texture backTexture;
		sf::Sprite bg;
		sf::Sprite backBtn;
		PopUp backPopUp;
		PopUp winPopUp;
		TextLabel backPopUpYes;
		TextLabel backPopUpNo;
		TextLabel winPopUpReset;
		TextLabel resetBtn;
		TextLabel turnText;
		TextLabel preShotText;
		TextLabel player1Text;
		TextLabel player1Type;
		TextLabel player2Text;
		TextLabel player2Type;
		sf::Vector2f p1FirstUIBallPos;
		sf::Vector2f p2FirstUIBallPos;
		bool backPopUpActive;
		bool winPopUpActive;
		bool ballsStationary;
		bool gameEnded;
		int win = 0; // 0 - no win | 1 - p1 win | p2 - win
};
