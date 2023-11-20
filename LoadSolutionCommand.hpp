#pragma once

#include "Command.hpp"
#include <iostream>

class LoadSolutionCommand  : public Command
{
public:
    void execute(const vector<string> &params) override
    {
        if (params.size() == 1)
        {
            Maze2d maze = Mymodal::loadSolution(params[0],"solutions.bin");
            Session::saveSolution(maze.getName(),maze);
            maze.print();
        }
        else
        {
            cout << "Invalid parameters for save command." << endl;
        }
    }
};
