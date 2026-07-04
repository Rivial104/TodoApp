#pragma once

#include <iostream>
#include <string>

class Shell
{
public:
    Shell();
    ~Shell();


    std::string get_input();

private:
    bool verify_request(std::string &req);

};