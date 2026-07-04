#include "Shell.hpp"

Shell::Shell()
{
    

};

std::string Shell::get_input()
{
    std::string input;
    std::getline(std::cin, input);

    // if(verify_request(input)) return input;

    return input;
};