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
            printf("Enter new task name: \n");
            std::string taskname;
            std::cin >> taskname;

            printf("Enter task's type: \n");
            char type;
            std::cin >> type;
            int tp = type - '0';

            printf("Enter task's priority: \n");
            char prio;
            std::cin >> prio;
            int pr = prio - '0';

            Task t(_tstorage.size(), taskname, static_cast<Type>(tp), static_cast<Priority>(pr));

            _tstorage.add_task(&t);


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