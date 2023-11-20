#pragma once

#include "Command.hpp"
#include <iostream>

class DisplaySolutionsCommand : public Command
{
public:
    void execute(const vector<string> &params) override
    {
        if (params.size() == 0)
        {
                Session::printSolutions();
        }
        else
        {
            cout << "Invalid parameters for display command." << endl;
        }
    }
};
