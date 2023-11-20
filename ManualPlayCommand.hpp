#pragma once

#include "Command.hpp"
#include "Manual.hpp"
#include <iostream>

class ManualPlayCommand : public Command
{
public:
    void execute(const vector<string> &params) override
    {
        if (params.size() == 1)
        {
            if (Session::hasMaze(params[0]))
            {
                Maze2d maze = Session::getMaze(params[0]);
                Manual man(maze);
                man.Play();
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
