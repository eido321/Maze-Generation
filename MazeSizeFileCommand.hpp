#pragma once

#include "Command.hpp"
#include "MazeCompression.hpp"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <filesystem>

class MazeSizeFileCommand : public Command
{
public:
    void execute(const vector<string> &params) override
    {
        if (params.size() == 1)
        {
            if (Session::hasMaze(params[0]))
            {
                ofstream outputFile("tmp.bin");
                if (outputFile.is_open())
                {
                    Maze2d maze = Session::getMaze(params[0]);
                    Mymodal::saveSolution(maze, "tmp.bin");
                    filesystem::path filePath("tmp.bin");
                    if (filesystem::exists(filePath))
                    {
                        uintmax_t fileSize = filesystem::file_size(filePath);
                        cout << "The size of the maze " << params[0] << " in the memory is " << fileSize << " bytes." << endl;
                    }
                    else
                    {
                        cout << "File doesn't exist." << endl;
                    }
                    outputFile.close();
                    filesystem::remove(filePath);
                }
                else
                {
                    cout << "Unable to create or open the file." << endl;
                    return;
                }
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
