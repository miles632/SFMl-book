#include "game.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Event.hpp>

Game::Game()

   :mWindow(sf::VideoMode(800, 600), "SFML APPLICATION")
    ,mPlayer(sf::CircleShape(40.f))
{
        mPlayer.setPosition(100.f, 100.f);
        mPlayer.setFillColor(sf::Color::Cyan);
}

void Game::processEvents()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            mWindow.close();
    }
}

void Game::run()
    {
        while (mWindow.isOpen())
        {
            processEvents();
            update();
            render();
        }
    }

void Game::update()
{

}

void Game::render()
{
    mWindow.clear();
    mWindow.draw(mPlayer);
    mWindow.display();
}
