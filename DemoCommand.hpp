#pragma once

#include "Command.hpp"
#include "Demo.hpp"
#include <iostream>

class DemoCommand : public Command
{
public:
    void execute(const vector<string> &params) override
    {
        if (params.size() == 0)
        {
            cout << "here" << endl;
            Demo::run();
        }
        else
        {
            cout << "Invalid parameters for save command." << endl;
        }
    }
};
