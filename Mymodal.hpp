#pragma once

#include "Maze2d.hpp"
#include "Maze2dGenerator.hpp"
#include "MazeCompression.hpp"
#include <unordered_map>
#include <fstream>
#include <iostream>

class Mymodal {
public:
    static void saveMaze(Maze2d &maze,string inFile);
    static void saveSolution(Maze2d &maze,string inFile);
    static Maze2d loadMaze(string targetMazeID,string outFile) ;
    static Maze2d loadSolution(string targetMazeID,string outFile);
};
