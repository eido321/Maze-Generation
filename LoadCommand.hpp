#pragma once

#include "Command.hpp"
#include <iostream>

class LoadCommand : public Command
{
public:
    void execute(const vector<string> &params) override
    {
        if (params.size() == 1)
        {
            Maze2d maze = Mymodal::loadMaze(params[0],"mazes.bin");
            Session::saveMaze(maze.getName(),maze);
            maze.print();
        }
        else
        {
            cout << "Invalid parameters for save command." << endl;
        }
    }
};
