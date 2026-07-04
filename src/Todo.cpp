#include <iostream>
#include <fstream>
#include <vector>

#include "todo/Config.hpp"
#include "todo/Parser.hpp"
#include "todo/Task.hpp"
#include "todo/Renderer.hpp"
#include "todo/Shell.hpp"
#include "todo/Commander.hpp"
#include "todo/TaskStorage.hpp"

int main()
{
    Config config;
    Renderer *rend = new Renderer();
    Parser *parser = new Parser(config.type);
    TaskStorage *tstorage = new TaskStorage();

    Commander *commander = new Commander(*tstorage, *rend);

    rend->print_init();

    printf("--- Checking saved task list ---\n");

    std::vector<Task*> tlist = parser->deserialize_tasks(config.TASK_LIST_PATH);
    tstorage->set_all_tasks(tlist);

    printf("### Loaded %i tasks from Task List ###\n", (int)tlist.size());

    printf("--- Checking saved app config ---\n");

    printf("Enter commands or type 'help' for usage:\n");

    Shell *sh = new Shell();

    bool app{true};

    while(app)
    {
        std::string user_input = sh->listen();

        Command cmd = parser->handle_input(user_input);
        
        app = commander->handle_command(cmd);
    }

    return 0;
}