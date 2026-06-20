#pragma once

#include <string>

enum class Type : int
{
    PHD = 0,
    DYD = 1,
    WB = 2,
    IFO = 3,
    OTHER = 4,
};

enum class Priority : int
{
    NONE = 0,
    LOW = 1,
    MEDIUM = 2,
    HIGH = 3,
    URGENT = 4,
} priority;

class Task
{
public:
    Task() {};

    ~Task() {};
    
    void print()
    {
        std::cout << "Task " << std::endl;
    }

private:

    struct TaskParameters
    {
        int id;
        std::string desc;

        // int Priority::prio{0};
        // Date date;
        // Date deadline;

        // int Type::type{0};
    };
};