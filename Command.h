//Command.h

#include "Snake.h"

class Command
{
    public:
        virtual ~Command();
        virtual void execute(Snake & serpiente) const = 0;
};

class goLeftCommand: public Command
{
    public: 
        virtual void execute(Snake & serpiente) const;
};

class goRightCommand: public Command
{
    public: 
        virtual void execute(Snake & serpiente) const;
};

class goUpCommand: public Command
{
    public: 
        virtual void execute(Snake & serpiente) const;
};

class goDownCommand: public Command
{
    public: 
        virtual void execute(Snake & serpiente) const;
};
