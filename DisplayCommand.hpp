#pragma once

#include "Command.hpp"
#include <iostream>
#include "Session.hpp"

class DisplayCommand : public Command
{
public:
    void execute(const vector<string> &params) override
    {
        if (params.size() == 1)
        {
            if (Session::hasMaze(params[0]))
                Session::getMaze(params[0]).print();
            else
                cout << "No maze with that name exists." << endl;
        }
        else
        {
            cout << "Invalid parameters for display command." << endl;
        }
    }
};
