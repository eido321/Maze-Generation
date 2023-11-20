#pragma once
#include <iostream>
#include <algorithm>
#include <random>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

class Maze2d
{
public:
    Maze2d(){};
    void setCell(int x, int y, int value);
    char getCell(int x, int y);
    int getWidth() const;
    int getHeight() const;
    string getName() { return mazeName_; };
    void setName(string name) { mazeName_ = name; };
    void setWidth(int width) { width_ = width; };
    void setHeight(int height) { height_ = height; };
    void setGrid(vector<vector<int>> grid);
    vector<vector<int>> getGrid() { return maze; };
    void print() const;
    void printDebug() const;
    pair<int, int> findStart() const;
    pair<int, int> findEnd() const;
    int calculateRealSize() const;

private:
    string mazeName_;
    vector<vector<int>> maze;
    int width_;
    int height_;
};
