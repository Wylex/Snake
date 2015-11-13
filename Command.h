//Command.h

#ifndef COMMAND_H
#define COMMAND_H

#include "Snake.h"

class Command
{
    public:
        virtual void execute(Snake & gameActor) const = 0;
};

class pauseCommand: public Command
{
    private: 
        virtual void execute(Snake & gameActor) const override {}
};

class goLeftCommand: public Command
{
    public: 
        virtual void execute(Snake & gameActor) const override {gameActor.goLeft();}
};

class goRightCommand: public Command
{
    public: 
        virtual void execute(Snake & gameActor) const override {gameActor.goRight();}
};

class goUpCommand: public Command
{
    public: 
        virtual void execute(Snake & gameActor) const override {gameActor.goUp();}
};

class goDownCommand: public Command
{
    public: 
        virtual void execute(Snake & gameActor) const override {gameActor.goDown();}
};

#endif
