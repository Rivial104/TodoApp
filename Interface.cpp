#include "Interface.hpp"

using namespace task;

Interface::Interface(int type)
{
    _type = type;

}

void Interface::init()
{
    printf("###########    TODO LIST APP     ###########\n");
    printf("###########  Author: pzawadzki   ###########\n");
    printf("###########   Version: 0.0.1v    ###########\n");

}


std::vector<Task*> Interface::deserialize_tasks(const char tlistpath[])
{
    std::vector<Task*> task_list;
    std::string task;
    std::ifstream tlist(tlistpath);

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
                                const task::Type t = static_cast<task::Type>(std::stoi(type));
                                tmp->set_type(t);
                                left = right;
                                param++;
                                break;
                            }
                            case 3: 
                            {
                                const std::string prio = task.substr(left+1, right-1);
                                const task::Priority p = static_cast<task::Priority>(std::stoi(prio));
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