#include "todo/Shell.hpp"

Shell::Shell()
{
    

};

std::string Shell::listen()
{
    std::string input;
    std::getline(std::cin, input);

    // if(verify_request(input)) return input;

    return input;
};