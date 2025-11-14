#include "mainMenuState.h"
#include "game.h"
#include "playState.h"
#include <memory>
#include <stack>

MainMenuState::MainMenuState(Game& game) : State(game)
{
	_bgTexture.loadFromFile("assets/main_menu_bg.png");
	_bg.setTexture(_bgTexture);
	_bg.setScale(sf::Vector2f(0.833333f, 0.833333f));
	_bg.setPosition(sf::Vector2f(0.f, 0.f));

	_title.setFont(_game.frutiger);
	_title.setFillColor(sf::Color::Black);
	_title.setCharacterSize(130);
	_title.setOutlineThickness(3);
	_title.setOutlineColor(sf::Color(177, 177, 177));
	_title.setString("8-Ball Pool");
	sf::Vector2f titleCenter(_title.getLocalBounds().width / 2.f, _title.getLocalBounds().height / 2.f);
	_title.setOrigin(titleCenter);
	_title.setPosition(sf::Vector2f(600.f, 200.f));

	_playButton.setFont(_game.frutiger);
	_playButton.setFillColor(sf::Color::Black);
	_playButton.setCharacterSize(48);
	_playButton.setString("Play");
	sf::Vector2f playCenter(_playButton.getLocalBounds().width / 2.f, _playButton.getLocalBounds().height / 2.f);
	_playButton.setOrigin(playCenter);
	_playButton.setPosition(sf::Vector2f(600.f, 375.f));

	_tutorialButton.setFont(_game.frutiger);
	_tutorialButton.setFillColor(sf::Color::Black);
	_tutorialButton.setCharacterSize(48);
	_tutorialButton.setString("Tutorial");
	sf::Vector2f tutorialCenter(_tutorialButton.getLocalBounds().width / 2.f, _tutorialButton.getLocalBounds().height / 2.f);
	_tutorialButton.setOrigin(tutorialCenter);
	_tutorialButton.setPosition(sf::Vector2f(600.f, 450.f));

	_quitButton.setFont(_game.frutiger);
	_quitButton.setFillColor(sf::Color::Black);
	_quitButton.setCharacterSize(48);
	_quitButton.setString("Quit");
	sf::Vector2f quitCenter(_quitButton.getLocalBounds().width / 2.f, _quitButton.getLocalBounds().height / 2.f);
	_quitButton.setOrigin(quitCenter);
	_quitButton.setPosition(sf::Vector2f(600.f, 525.f));
}

void MainMenuState::handleEvent(sf::Event& event)
{
	float mouseX = _game.window.mapPixelToCoords(sf::Mouse::getPosition(_game.window)).x;
	float mouseY = _game.window.mapPixelToCoords(sf::Mouse::getPosition(_game.window)).y;

	if (_playButton.getGlobalBounds().contains(mouseX, mouseY))
	{
		_playButton.setFillColor(sf::Color(102, 102, 102));
		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
		{
			_game.changeState(std::make_unique<PlayState>(_game));
			return;
		}
	}
	else
	{
		_playButton.setFillColor(sf::Color::Black);
	}

	if (_tutorialButton.getGlobalBounds().contains(mouseX, mouseY))
	{
		_tutorialButton.setFillColor(sf::Color(102, 102, 102));
		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
		{
			//_game.changeState(std::make_unique<TutorialState>(_game));
			return;
		}
	}
	else
	{
		_tutorialButton.setFillColor(sf::Color::Black);
	}

	if (_quitButton.getGlobalBounds().contains(mouseX, mouseY))
	{
		_quitButton.setFillColor(sf::Color(102, 102, 102));
		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
		{
			_game.window.close();
			return;
		}
	}
	else
	{
		_quitButton.setFillColor(sf::Color::Black);
	}
		
}

void MainMenuState::update(float dt)
{
}

void MainMenuState::render(sf::RenderWindow& window)
{
	window.draw(_bg);
	window.draw(_title);
	window.draw(_playButton);
	window.draw(_tutorialButton);
	window.draw(_quitButton);
}
