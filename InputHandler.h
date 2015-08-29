//inputHandler.h

#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "Command.h"
#include <SFML/Graphics.hpp>
#include <memory>

class InputHandler
{
    public:
        InputHandler();
        std::shared_ptr<Command> handleInput(sf::RenderWindow & win);

    private: 
        sf::Event event;
 
        std::shared_ptr<Command> keyJ;
        std::shared_ptr<Command> keyK;
        std::shared_ptr<Command> keyL;
        std::shared_ptr<Command> keyH;
};

#endif
