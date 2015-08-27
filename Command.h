//Command.h

#include "Snake.h"

class Command
{
    public:
        virtual ~Command();
        virtual void execute(Snake & serpiente) = 0;
};

class goLeftCommand: public Command
{
    public: 
        virtual void execute(Snake & serpiente) { serpiente.goLeft(); }
}

class goRightCommand: public Command
{
    public: 
        virtual void execute(Snake & serpiente) { serpiente.goRight(); }
}

class goUpCommand: public Command
{
    public: 
        virtual void execute(Snake & serpiente) { serpiente.goUp(); }
}

class goDownCommand: public Command
{
    public: 
        virtual void execute(Snake & serpiente) { serpiente.goDown(); }
}
