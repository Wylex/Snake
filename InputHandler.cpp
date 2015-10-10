//InputHandler.cpp

#include <iostream>

#include "InputHandler.h"

InputHandler::InputHandler():keyH(new goLeftCommand), keyJ(new goDownCommand), keyK(new goUpCommand), keyL(new goRightCommand),
keyEsc(new pauseCommand)
{
}

std::shared_ptr<Command> InputHandler::handleInput(sf::RenderWindow & win)
{
    while(win.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed:
                win.close();
                break;
            
            case sf::Event::KeyPressed:
                if(event.key.code == sf::Keyboard::H)
                    return keyH;
                else if(event.key.code == sf::Keyboard::J)
                    return keyJ;
                else if(event.key.code == sf::Keyboard::K)
                    return keyK;
                else if(event.key.code == sf::Keyboard::L)
                    return keyL;
                else if(event.key.code == sf::Keyboard::Escape)
                    return keyEsc;
                break;
        }
    }

    return 0;
}
