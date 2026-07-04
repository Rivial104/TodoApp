#include <iostream>
#include <fstream>
#include <vector>

#include "todo/Config.hpp"
#include "todo/Parser.hpp"
#include "todo/Task.hpp"
#include "todo/Renderer.hpp"
#include "todo/Shell.hpp"

Config config;

int main()
{
    Config config;
    Renderer *rend = new Renderer();
    Parser *parser = new Parser(config.type);

    rend->print_init();

    printf("--- Checking saved task list ---\n");

     std::vector<Task*> tlist = parser->deserialize_tasks(config.TASK_LIST_PATH);

    printf("### Loaded %i tasks from Task List ###\n", (int)tlist.size());

    printf("--- Checking saved app config ---\n");


    printf("Enter commands or type 'help' for manual");

    Shell *sh = new Shell();

    sh->listen();


    return 0;
}