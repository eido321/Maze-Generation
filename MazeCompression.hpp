#pragma once

#include "Maze2d.hpp"
#include <fstream>
#include <iostream>
#include <string>

class MazeCompression
{
public:
    MazeCompression(){};
    MazeCompression(Maze2d &maze);
    static Maze2d decompress(MazeCompression &compressedMaze);
    vector<pair<int, int>> getPaths() { return paths_; };
    vector<pair<int, int>> getSolves() { return solve_; };
    int getMazeID() { return mazeID_; }
    int getWidth() { return width_; }
    int getHeight() { return height_; }
    pair<int, int> getStart() { return start_; }
    pair<int, int> getEnd() { return end_; }
    string getMazeName(){return mazeName_;}
    void setMazeName(string mazeName){mazeName_ = mazeName;}
    void setMazeID(int mazeID) { mazeID_ = mazeID; }
    void setWidth(int width) { width_ = width; }
    void setHeight(int height) { height_ = height; }
    void setStart(pair<int, int> &start) { start_ = start; }
    void setEnd(pair<int, int> &end) { end_ = end; }
    void setPaths(vector<pair<int, int>> &paths) { paths_ = paths; }
    void setSolves(vector<pair<int, int>> &solve) { solve_ = solve; }

    static vector<int> getAllIDs();
    static vector<int> getAllMazesIDs();
    static vector<int> getAllSolutionsIDs();

private:
    int mazeID_;
    string mazeName_;
    int width_;
    int height_;
    pair<int, int> start_;
    pair<int, int> end_;
    vector<pair<int, int>> paths_;
    vector<pair<int, int>> solve_;
};
