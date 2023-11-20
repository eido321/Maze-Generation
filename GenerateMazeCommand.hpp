#pragma once

#include "Command.hpp"
#include <iostream>
using namespace std;
#include "BFSGenerator.hpp"
#include "DFSGenerator.hpp"
#include <exception>
#include "Session.hpp"

class GenerateMazeCommand : public Command
{
public:
    void execute(const vector<string> &params) override
    {
        int choise;
        if (params.size() == 3)
        {
            try
            {
                if (stoi(params[2]) < 4 && stoi(params[1]) < 4)
                {
                    cout << "Invalid Maze Size." << endl;
                    return;
                }
                while (true)
                {
                    cout << "Please select generation method: " << endl;
                    cout << "1 - Bfs generator (may not be solveable)" << endl;
                    cout << "2 - Dfs generator" << endl;
                    cin >> choise;
                    if (choise == 1)
                    {
                        BFSGenerator bfsGenerator;
                        Maze2d maze = bfsGenerator.generate(stoi(params[2]), stoi(params[1]), params[0]);
                        maze.print();
                        Session::saveMaze(params[0], maze);
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        break;
                    }
                    else if (choise == 2)
                    {
                        DFSGenerator dfsGenerator;
                        Maze2d maze = dfsGenerator.generate(stoi(params[2]), stoi(params[1]), params[0]);
                        maze.print();
                        Session::saveMaze(params[0], maze);
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }
                    else
                    {
                        cout << "Invalid input." << endl;
                    }
                }
            }
            catch (const out_of_range &ex)
            {
                cout << "The string represents a number that is out of range for int." << endl;
            }
            catch (const invalid_argument &ex)
            {
                cout << "The string is not a valid number." << endl;
            }
            catch (const exception &ex)
            {
                cout << "An exception occurred: " << ex.what() << endl;
            }
        }
        else
        {
            cout << "Invalid parameters for generate maze command." << endl;
        }
    }
};
