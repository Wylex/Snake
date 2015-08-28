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
        void handleInput(sf::RenderWindow & win);

    private: 
        sf::Event event;
 
        std::unique_ptr<Command> keyJ;
        std::unique_ptr<Command> keyK;
        std::unique_ptr<Command> keyL;
        std::unique_ptr<Command> keyH;
};

#endif
