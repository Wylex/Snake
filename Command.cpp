#include "Command.h"

Command::~Command()
{
}

void goLeftCommand::execute(Snake & serpiente) const
{
    serpiente.goLeft();
}

void goRightCommand::execute(Snake & serpiente) const
{
    serpiente.goRight();
}

void goDownCommand::execute(Snake & serpiente) const
{
    serpiente.goDown();
}

void goUpCommand::execute(Snake & serpiente) const
{
    serpiente.goUp();
}
