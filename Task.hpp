#pragma once

#include <stdio.h>
#include <string>


namespace task
{

enum class Type : int
{
    OTHER       = 0,
    PHD         = 1,
    DYD         = 2,
    WB          = 3,
    IFO         = 4,
    BIRDS       = 5,
    DEVELOPMENT = 6,
};

enum class Priority : int
{
    NONE        = 0,
    LOW         = 1,
    MEDIUM      = 2,
    HIGH        = 3,
    URGENT      = 4,
};

class Task
{
public:
    Task() = default;

    Task(int id, std::string desc, Type type, Priority prio) 
    {
        _params.id = id;
        _params.desc = desc;
        _params.type = type;
        _params.priority = prio;
    };

    ~Task() = default;
    
    void print()
    {
        printf("|| Task: %i || %s || Type: %i || Priority: %i ||\n", _params.id, _params.desc.c_str(),  (int)_params.type,  (int)_params.priority);
    }

    void set_id(int i) {_params.id = i;};
    void set_desc(std::string s) {_params.desc = s;};
    void set_type(Type t) {_params.type = t;};
    void set_priority(Priority p) {_params.priority = p;};

private:

    struct TaskParameters
    {
        int id{0};
        std::string desc;
        Type type{Type::OTHER};
        Priority priority{Priority::NONE};

        // Date date;
        // Date deadline;
    } _params;
};

};
