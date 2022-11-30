#include "GameCore.h"
#include <iostream>
#include "Cell.h"
#include "Entity.h"


void GameCore::update(int elapsed) //event handler
{
    sf::Event event;
    bool drag = false;
    window->setFramerateLimit(60);
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window->close();
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) 
                window->close();
        }
            
        /*if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mouse_pos = sf::Mouse::getPosition() - window->getPosition();
               
                

            }
        }*/
        
    }
}

void GameCore::draw()
{
    window->clear();
    float x = 500;
    float y = 500;
    Cell cell = Cell(x, y, window);
    cell.render();
    /*for (auto cell : map)
        cell->render();
        */
    Entity entity = Entity("wild.png");
    
    window->draw(entity.sprite);


    window->display();
}

void GameCore::start() {
	sf::Clock clc;
	while (window->isOpen()) {
		int elapsed = clc.restart().asMilliseconds();
		update(elapsed);
		draw();
	}
	
}

GameCore::GameCore()
{
    window = new sf::RenderWindow(sf::VideoMode(800, 800), "SFML window");
}

GameCore::~GameCore()
{
    delete window;
}
