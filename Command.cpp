#include "Command.h"

Command::~Command()
{
}

void goLeftCommand::execute(Snake & serpiente)
{
    serpiente.goLeft();
}

void goRightCommand::execute(Snake & serpiente)
{
    serpiente.goRight();
}

void goDownCommand::execute(Snake & serpiente)
{
    serpiente.goDown();
}

void goUpCommand::execute(Snake & serpiente)
{
    serpiente.goUp();
}
