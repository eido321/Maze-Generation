#include "DFSGenerator.hpp"

Maze2d DFSGenerator::generate(int width,int height,string name) const
{
    Maze2d tmp;
    vector<vector<int>> maze(height, vector<int>(width, 1));

    random_device rd;
    mt19937 gen(rd());

    int r = 1 + 2 * (gen() % (height / 2));
    int c = 1 + 2 * (gen() % (width / 2));

    maze[r][c] = 0;

    recursion(maze, r, c,width,height);
    BorderTheMaze(maze,width,height);
    StartAndEnd(maze,width,height);
    tmp.setGrid(maze);
    tmp.setWidth(width);
    tmp.setHeight(height);
    tmp.setName(name);
    return tmp;
}
