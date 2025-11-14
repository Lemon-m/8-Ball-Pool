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
		std::vector<Ball> balls;
		Turn turn;
		CueBall cueBall;
		Table table;
		sf::Texture _bgTexture;
		sf::Sprite _bg;
		sf::Text text;
		bool ballsStationary = true;
		bool gameEnded = false;
		int win = 0; // 0 - no win | 1 - p1 win | p2 - win
};
