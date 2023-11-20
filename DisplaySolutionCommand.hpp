#pragma once

#include "Command.hpp"
#include <iostream>

class DisplaySolutionCommand : public Command
{
public:
    void execute(const vector<string> &params) override
    {
        if (params.size() == 1)
        {
            if (Session::hasSolution(params[0]))
                Session::getSolution(params[0]).print();
            else
                cout << "No maze solution with that name exists." << endl;
        }
        else
        {
            cout << "Invalid parameters for display command." << endl;
        }
    }
};
