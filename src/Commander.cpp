#include <stdio.h>

#include "todo/Commander.hpp"
 

bool Commander::handle_command(Command cmd)
{
    switch(cmd)
    {
        case Command::HELP:
        {
            printf("usage: help | list | info <id> | add | edit <id>");
            return true;
            break;
        }

        case Command::LIST:
        {
            return true;
            break;
        }
        

    }
    return false;
}