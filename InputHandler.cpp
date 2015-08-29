//InputHandler.cpp

#include "InputHandler.h"

InputHandler::InputHandler():keyH(new goLeftCommand), keyJ(new goDownCommand), keyK(new goUpCommand), keyL(new goRightCommand)
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
                break;
        }
    }

    return 0;
}
