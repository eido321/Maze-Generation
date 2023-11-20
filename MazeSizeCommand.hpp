#pragma once

#include "Command.hpp"
#include <iostream>


class MazeSizeCommand : public Command
{
public:
    void execute(const vector<string> &params) override
    {
        if (params.size() == 1)
        {
            if (Session::hasMaze(params[0]))
            {
                cout << "The size of the maze " << params[0] << " in the memory is " << Session::getMaze(params[0]).calculateRealSize() << " bytes." << endl;
            }
            else
            {
                cout << "No maze with that name exists." << endl;
            }
        }
        else
        {
            cout << "Invalid parameters for save command." << endl;
        }
    }
};
