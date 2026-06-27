#include <iostream>
#include <fstream>
#include <list>
#include <bits/stdc++.h>

#include "Interface.hpp"
#include "Task.hpp"

std::list<Task*> deserialize(const char *filepath)
{
    std::list<Task*> task_list;
    std::string task;
    std::ifstream tlist(filepath);

    if(tlist.is_open())
    {
        while(getline (tlist, task))
        {
                int left{0};
                int right{1};
                int param{0};
                Task *tmp = new Task();
                while(right < task.size() && task[right] != '!')
                {
                    if(task[right] == '#')
                    {
                        switch(param)
                        {
                            case 0:
                            {
                                const std::string num = task.substr(left+1, right-1);
                                const int id = std::stoi(num);
                                tmp->set_id(id);
                                left = right;
                                param++;
                                break;
                            }
                            case 1:
                            {
                                const std::string s = task.substr(left+1, right-left-1);
                                tmp->set_desc(s);
                                left = right;
                                param++;
                                break;
                            }
                            case 2: 
                            {
                                const std::string type = task.substr(left+1, right-1);
                                const int t = std::stoi(type);
                                tmp->set_type(t);
                                left = right;
                                param++;
                                break;
                            }
                            case 3: 
                            {
                                const std::string prio = task.substr(left+1, right-1);
                                const int p = std::stoi(prio);
                                tmp->set_priority(p);
                                left = right;
                                param++;
                                break;
                            }
                        }
                    }
                    right++;
                }


            task_list.insert(task_list.begin(), tmp);
        }
    }

    return task_list;
}

int main()
{
    printf("###########    TODO LIST APP     ###########\n");
    printf("###########  Author: pzawadzki   ###########\n");
    printf("###########   Version: 0.0.1v    ###########\n");

    printf("--- Checking saved task list ---\n");

    const char TASK_LIST_PATH[] = "./task_list.txt";

    std::list<Task*> tlist = deserialize(TASK_LIST_PATH);

    printf("--- Checking saved app config ---\n");

    // const char TASK_LIST_PATH[] = "./task_list.txt";

    // int id = 1;
    // char opis[] = "Todo App Development";
    // int type = 6;
    // int prio = 2;
    // Task *task1 = new Task(id, opis, type, prio);

    // task_list.insert(task_list.begin(), task1);
    // task1->print();

    printf("Print tasks from file: \n");

    tlist.front()->print();
    tlist.back()->print();


    return 0;
}