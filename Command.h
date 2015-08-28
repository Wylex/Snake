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
        virtual void execute(Snake & serpiente);
};

class goRightCommand: public Command
{
    public: 
        virtual void execute(Snake & serpiente);
};

class goUpCommand: public Command
{
    public: 
        virtual void execute(Snake & serpiente);
};

class goDownCommand: public Command
{
    public: 
        virtual void execute(Snake & serpiente);
};
