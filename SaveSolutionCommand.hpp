#pragma once

#include "Command.hpp"
#include <iostream>

class SaveSolutionCommand : public Command
{
public:
    void execute(const vector<string> &params) override
    {
        if (params.size() == 1)
        {
            if (Session::hasSolution(params[0]))
            {
                Maze2d maze = Session::getSolution(params[0]);
                Mymodal::saveSolution(maze,"solutions.bin");
                cout << "Maze solution was saved successfully" << endl;
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
