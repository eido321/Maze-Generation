//Controller 
#pragma once

#include <iostream>
#include <map>
#include "Maze2d.hpp"
using namespace std;

class Session
{
public:
    static void saveMaze(string name, Maze2d maze)
    {
        sessionMaze_[name] = maze;
    };

    static void saveSolution(string name, Maze2d maze)
    {
        sessionSolution_[name] = maze;
    };

    static void printMazes()
    {
        cout << "Mazes in this session:" << endl;
        for (const auto &pair : sessionMaze_)
        {
            cout << "Name: " << pair.first << endl;
        }
    }

    static void printSolutions()
    {
        cout << "\nSolutions in this session:" << endl;
        for (const auto &pair : sessionSolution_)
        {
            cout << "Name: " << pair.first << endl;
        }
    }

    static Maze2d getMaze(string name){return sessionMaze_[name];};
    static Maze2d getSolution(string name){return sessionSolution_[name];};

    static bool hasMaze(string name) {
        return sessionMaze_.find(name) != sessionMaze_.end();
    }

    static bool hasSolution(string name) {
        return sessionSolution_.find(name) != sessionSolution_.end();
    }

private:
    static map<string, Maze2d> sessionMaze_;
    static map<string, Maze2d> sessionSolution_;
};

map<string, Maze2d> Session::sessionMaze_;
map<string, Maze2d> Session::sessionSolution_;
