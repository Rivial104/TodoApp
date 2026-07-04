#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include "todo/Task.hpp"
#include "todo/Commander.hpp"

class Parser
{
public:

    Parser(int type);
    ~Parser() {};

    void init();

    std::vector<Task*> deserialize_tasks(std::string tlistpath);
    Command handle_input(std::string input);

private:
    int _type{0};

};