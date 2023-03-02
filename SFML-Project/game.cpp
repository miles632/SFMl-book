#include "game.hpp"
#include <SFML/Graphics.hpp>

Game::Game()
{
    mWindow(sf::VideoMode(800, 600), "SFML APPLICATION");
    mPlayer();
    {
        mPlayer.setRadius(40.f);
        mPlayer.setPosition(100.f, 100.f);
        mPlayer.setFillColor(sf::Color::Cyan);
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
}

void Game::processEvents()
{

}
