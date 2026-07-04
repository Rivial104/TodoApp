#pragma once

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
    bool handle_command(Command cmd);   

private:

    Command _last_cmd{(Command::UNKNOWN)};
    bool _last_result{false};
};