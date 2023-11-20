#pragma once

#include "Command.hpp"
#include <iostream>
#include "Session.hpp"

class SaveCommand : public Command
{
public:
    void execute(const vector<string> &params) override
    {
        if (params.size() == 1)
        {
            if (Session::hasMaze(params[0]))
            {
                Maze2d maze = Session::getMaze(params[0]);
                Mymodal::saveMaze(maze,"mazes.bin");
                cout << "Maze was saved successfully" << endl;
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
