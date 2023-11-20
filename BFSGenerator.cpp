#include "BFSGenerator.hpp"

Maze2d BFSGenerator::generate(int width, int height,string name) const
{
    Maze2d tmp;
    vector<vector<int>> maze(height, vector<int>(width, 1));
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < height - 1; i++)
    {
        for (int j = 0; j < width - 1; j++)
        {
            if(i == 0 || j == 0 || i == height - 1 || j == width - 1)
                maze[i][j] = 1;
            else
                maze[i][j] = (rand() % 2 == 0) ? 1 : 0; 
        }
    }

    StartAndEnd(maze, width, height);
    tmp.setGrid(maze);
    tmp.setHeight(height);
    tmp.setWidth(width);
    tmp.setName(name);
    return tmp;
}