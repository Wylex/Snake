#include "Command.h"

void goLeftCommand::execute(Snake & gameActor) const
{
    gameActor.goLeft();
}

void goRightCommand::execute(Snake & gameActor) const
{
    gameActor.goRight();
}

void goDownCommand::execute(Snake & gameActor) const
{
    gameActor.goDown();
}

void goUpCommand::execute(Snake & gameActor) const
{
    gameActor.goUp();
}
