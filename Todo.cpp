#include <stdio.h>
#include <iostream>

#include "Task.hpp"

int main()
{
    int id = 1;
    char opis[] = "Todo App Development";
    int type = 6;
    int prio = 2;
    Task *task1 = new Task(id, opis, type, prio);

    task1->print();

    return 0;
}