#include <iostream>
#include <fstream>
#include <vector>

#include "Config.hpp"
#include "Parser.hpp"
#include "Task.hpp"
#include "Renderer.hpp"

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


    return 0;
}