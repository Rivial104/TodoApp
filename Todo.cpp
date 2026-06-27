#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

#include "Interface.hpp"
#include "Task.hpp"


int main()
{
    const char TASK_LIST_PATH[] = "./task_list.txt";
    const int type = 2;
    Interface *ifc = new Interface(type);

    printf("--- Checking saved task list ---\n");

    std::vector<Task*> tlist = ifc->deserialize_tasks(TASK_LIST_PATH);

    printf("--- Checking saved app config ---\n");


    printf("Print tasks from file: \n");

    tlist[0]->print();
    tlist[1]->print();

    return 0;
}