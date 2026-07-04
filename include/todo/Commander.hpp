#pragma once

enum class Command: int
{
    UNKNOWN,
    HELP,
    LIST,
    INFO,
    ADD,
    EDIT,
};

class Commander
{
public:


private:

    Command _last_cmd{(Command::UNKNOWN)};
    bool _last_result{false};

    bool handle_command(Command cmd);



};