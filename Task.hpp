#pragma once

#include <stdio.h>
#include <string>

class Task
{
public:
    Task() = default;

    Task(int id, std::string desc, int type, int prio) 
    {
        _params.id = id;
        _params.desc = desc;
        _params.type = type;
        _params.priority = prio;
    };

    ~Task() = default;
    
    void print()
    {
        printf("|| Task: %i || %s || Type: %i || Priority: %i ||\n", _params.id, _params.desc.c_str(),  _params.type,  _params.priority);
    }

    void set_id(int i) {_params.id = i;};
    void set_desc(std::string s) {_params.desc = s;};
    void set_type(int t) {_params.type = t;};
    void set_priority(int p) {_params.priority = p;};

private:

    enum class Type : int
    {
        OTHER       = 0,
        PHD         = 1,
        DYD         = 2,
        WB          = 3,
        IFO         = 4,
        BIRDS       = 5,
        DEVELOPMENT = 6,
    } _type;

    enum class Priority : int
    {
        NONE        = 0,
        LOW         = 1,
        MEDIUM      = 2,
        HIGH        = 3,
        URGENT      = 4,
    } _priority;

    struct TaskParameters
    {
        int id{0};
        std::string desc;
        int type{0};
        int priority{0};

        // Date date;
        // Date deadline;
    } _params;
};