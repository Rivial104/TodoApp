#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include "Task.hpp"
#include "Commander.hpp"

class Parser
{
public:

    Parser(int type);
    ~Parser() {};

    void init();

    std::vector<Task*> deserialize_tasks(std::string tlistpath);

private:
    int _type{0};
    // char _config_path[];

    enum class Commands : int
    {
        UNKNOWN = 0,
        HELP = 1,
        LIST = 2,
        INFO = 3,
        ADD = 4,
        EDIT = 5,
    };

    Command handle_input(std::string input);

};