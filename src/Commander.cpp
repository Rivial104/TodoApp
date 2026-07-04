#include <stdio.h>

#include "todo/Commander.hpp"
 
Commander::Commander(TaskStorage &tstorage, Renderer &rend) : _tstorage(tstorage), _renderer(rend)
{
}

bool Commander::handle_command(Command cmd)
{
    switch(cmd)
    {
        case Command::HELP:
        {
            printf("usage: help | list | info <id> | add | edit <id> | exit\n");
            return true;
        }

        case Command::LIST:
        {
            for (size_t i=0;i<_tstorage.size();i++)
            {
                _renderer.print_task(_tstorage.get_task(i));
            }
           return true;
 
        }

        case Command::ADD:
        {
            return true;
        }

        case Command::EXIT:
        {
            return false;
        }
        
        default:
        {
            return true;
        }
    }
}