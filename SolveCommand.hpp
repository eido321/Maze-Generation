#pragma once

#include "Command.hpp"
#include "Maze2dSearchableAdapter.hpp"
#include "Solution.hpp"
#include "BFSSolver.hpp"
#include "AstarSolver.hpp"
#include <iostream>

class SolveCommand : public Command
{
public:
    void execute(const vector<string> &params) override
    {
        if (params.size() == 2)
        {
            if (Session::hasMaze(params[0]))
            {
                Maze2d maze = Session::getMaze(params[0]);
                if (params[1] == "BFS")
                {
                    Maze2dSearchableAdapter searchableAdapter(maze);
                    BFSSolver<vector<vector<int>>,int> *tmp = new BFSSolver<vector<vector<int>>,int>();
                    Solution<vector<vector<int>>> sol = tmp->search(searchableAdapter);
                    Maze2d solution;
                    solution.setGrid(sol.getSolution().getState());
                    solution.setHeight(maze.getHeight());
                    solution.setWidth(maze.getWidth());
                    string tmpName;
                    cout << "Enter Solution name: " << endl;
                    getline(cin, tmpName);
                    solution.setName(tmpName);
                    solution.print();
                    Session::saveSolution(tmpName, solution);
                }
                else if (params[1] == "Astar")
                {
                    Maze2dSearchableAdapter searchableAdapter(maze);
                    AstarSolver<vector<vector<int>>,int> *tmp = new AstarSolver<vector<vector<int>>,int>();
                    Solution<vector<vector<int>>> sol = tmp->search(searchableAdapter);
                    Maze2d solution;
                    solution.setGrid(sol.getSolution().getState());
                    solution.setHeight(maze.getHeight());
                    solution.setWidth(maze.getWidth());
                    string tmpName;
                    cout << "Enter Solution name: " << endl;
                    getline(cin, tmpName);
                    solution.setName(tmpName);
                    solution.print();
                    Session::saveSolution(tmpName, solution);
                }
                else
                {
                    cout << "Invalid Algorithm" << endl;
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
