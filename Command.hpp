#pragma once


#include "Mymodal.hpp"
#include <vector>
#include <string>
class Command
{
public:
    virtual void execute(const vector<string> &parameters) = 0;
    virtual ~Command() {}
};