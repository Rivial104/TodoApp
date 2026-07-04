#pragma once

#include <iostream>
#include <string>

class Shell
{
public:
    Shell();
    ~Shell();


    std::string listen();

private:
    bool verify_request(std::string &req);

};