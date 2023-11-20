#pragma once

#include "Command.hpp"
#include <iostream>
#include "Session.hpp"

class DisplayMazesCommand : public Command
{
public:
    void execute(const vector<string> &params) override
    {
        if (params.size() == 0)
        {
                Session::printMazes();
        }
        else
        {
            cout << "Invalid parameters for display command." << endl;
        }
    }
};
