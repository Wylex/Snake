//InputHandler.cpp

#include "InputHandler.h"

InputHandler::InputHandler():keyH(new goLeftCommand), keyJ(new goDownCommand), keyK(new goUpCommand), keyL(new goRightCommand)
{
}

void InputHandler::handleInput(sf::RenderWindow & win)
{
    while(win.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            win.close();
    }
}
