#include "Funcs.hpp"

vector<int> generateRandomDirections()
{
    vector<int> randoms = {1, 2, 3, 4};
    shuffle(randoms.begin(), randoms.end(),mt19937(random_device()()));

    return randoms;
}

void BorderTheMaze(vector<vector<int>> &maze,int width,int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 || j == 0 || i == height - 1 || j == width - 1)
            {
                maze[i][j] = 1;
            }
        }
    }
}

void StartAndEnd(vector<vector<int>> &maze,int width,int height)
{
    bool Start = false;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (maze[i][j] == 0 && !Start)
            {
                Start = true;
                maze[i][j] = 2;
            }
        }
    }
    Start = false;
    for (int i = height - 1; i >= 0; i--)
    {
        for (int j = width - 1; j >= 0; j--)
        {
            if (maze[i][j] == 0 && !Start)
            {
                Start = true;
                maze[i][j] = 3;
            }
        }
    }
}

void recursion(vector<vector<int>> &maze, int r, int c,int width,int height)
{
    vector<int> randDirs = generateRandomDirections();
    for (int i = 0; i < randDirs.size(); i++)
    {
        switch (randDirs[i])
        {
        case 1: 
            if (r - 2 <= 0)
                continue;
            if (maze[r - 2][c] != 0)
            {
                maze[r - 2][c] = 0;
                maze[r - 1][c] = 0;
                recursion(maze, r - 2, c,width,height);
            }
            break;
        case 2: 
            if (c + 2 >= width - 1)
                continue;
            if (maze[r][c + 2] != 0)
            {
                maze[r][c + 2] = 0;
                maze[r][c + 1] = 0;
                recursion(maze, r, c + 2,width,height);
            }
            break;
        case 3:
            if (r + 2 >= height - 1)
                continue;
            if (maze[r + 2][c] != 0)
            {
                maze[r + 2][c] = 0;
                maze[r + 1][c] = 0;
                recursion(maze, r + 2, c,width,height);
            }
            break;
        case 4: 
            if (c - 2 <= 0)
                continue;
            if (maze[r][c - 2] != 0)
            {
                maze[r][c - 2] = 0;
                maze[r][c - 1] = 0;
                recursion(maze, r, c - 2,width,height);
            }
            break;
        }
    }
}

int manhattanDistance(int r1, int c1, int r2, int c2)
{
    return abs(r1 - r2) + abs(c1 - c2);
}