#pragma once

#include <vector>
#include <fstream>
#include "Task.hpp"


class Interface
{
public:

    Interface(int type);
    ~Interface() {};

    void init();

    bool wait_for_input();

    std::vector<task::Task*> deserialize_tasks(const char tlistpath[]);

private:
    int _type{0};
    // char _config_path[];

};