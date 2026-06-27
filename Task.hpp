#pragma once

#include <stdio.h>
#include <string>

class Task
{
public:
    Task(int id, char* desc, int type, int prio) 
    {
        _params.id = id;
        _params.desc = desc;
        _params.type = type;
        _params.priority = prio;
    };

    ~Task() {};
    
    void print()
    {
        printf("|| Task: %i || %s || Type: %i || Priority: %i ||\n", _params.id, _params.desc,  _params.type,  _params.priority);
    }

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
        int id;
        char* desc;
        int type{0};
        int priority{0};

        // Date date;
        // Date deadline;
    } _params;
};