#pragma once

#include "todo/TaskStorage.hpp"
#include "todo/Renderer.hpp"

enum class Command: int
{
    UNKNOWN,
    HELP,
    LIST,
    INFO,
    ADD,
    EDIT,
    EXIT,
};

class Commander
{
public:
    Commander(TaskStorage &tstorage, Renderer &rend);
    bool handle_command(Command cmd);   

private:
    TaskStorage &_tstorage;
    Renderer &_renderer;

    Command _last_cmd{(Command::UNKNOWN)};
    bool _last_result{false};
};