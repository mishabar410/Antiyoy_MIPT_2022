#pragma once

#include <SFML/Graphics.hpp>
#include "Cell.cpp"
#include <vector>

class GameCore {

	sf::RenderWindow* window;
	void update(int elapsed);
	void draw();

public:
	GameCore();
	void start();
	~GameCore();
};

