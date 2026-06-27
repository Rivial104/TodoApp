#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

#include "Interface.hpp"
#include "Task.hpp"

using namespace task;

int main()
{
    const char TASK_LIST_PATH[] = "./task_list.txt";
    const int type = 1;
    Interface *ifc = new Interface(type);
    ifc->init();

    printf("--- Checking saved task list ---\n");

    std::vector<Task*> tlist = ifc->deserialize_tasks(TASK_LIST_PATH);

    printf("--- Loaded %i tasks from Task List\n", (int)tlist.size());

    printf("--- Checking saved app config ---\n");

    printf("Print tasks from file: \n");

    tlist[0]->print();
    tlist[1]->print();

    return 0;
}