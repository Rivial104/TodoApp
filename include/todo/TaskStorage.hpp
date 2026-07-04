#pragma once

#include <vector>

#include "todo/Task.hpp"

class TaskStorage
{
public:
    Task* get_task(int id) { return tlist[id]; };
    std::vector<Task*> get_all_tasks() {return tlist;};
    void set_all_tasks(std::vector<Task*> list) {tlist = list;};
    int size() {return tlist.size();};

private:

    std::vector<Task*> tlist;

};