#include "Maze2d.hpp"
#include <iostream>

void Maze2d::setCell(int x, int y, int value)
{
    maze[y][x] = value;
}

char Maze2d::getCell(int x, int y)
{
    return maze[y][x];
}

int Maze2d::getWidth() const
{
    return width_;
}

int Maze2d::getHeight() const
{
    return height_;
}

void Maze2d::setGrid(vector<vector<int>> grid)
{
    maze = grid;
}

void Maze2d::print() const
{
    cout << "Maze Name: " << mazeName_ << endl;
    for (int i = 0; i < height_; i++)
    {
        for (int j = 0; j < width_; j++)
        {
            if (maze[i][j] == -1)
                cout << "P";
            else if (maze[i][j] == 1)
                cout << "#";
            else if (maze[i][j] == 2)
                cout << "S";
            else if (maze[i][j] == 3)
                cout << "E";
            else if (maze[i][j] > 3)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}

void Maze2d::printDebug() const
{
    cout << "Maze Name: " << mazeName_ << endl;
    for (int i = 0; i < height_; i++)
    {
        for (int j = 0; j < width_; j++)
        {
            cout << maze[i][j];
        }
        cout << endl;
    }
}

pair<int, int> Maze2d::findStart() const
{
    pair<int, int> tmp;
    for (int i = 0; i < height_; i++)
    {
        for (int j = 0; j < width_; j++)
        {
            if (maze[i][j] == 2)
                tmp = make_pair(i, j);
        }
    }
    return tmp;
}

pair<int, int> Maze2d::findEnd() const
{
    pair<int, int> tmp;
    for (int i = 0; i < height_; i++)
    {
        for (int j = 0; j < width_; j++)
        {
            if (maze[i][j] == 3)
                tmp = make_pair(i, j);
        }
    }
    return tmp;
}

int Maze2d::calculateRealSize() const
{
    int size = 0;
    for (const auto &row : maze)
    {
        size += row.size() * sizeof(int);
    }
    size+=mazeName_.size();
    size+=sizeof(width_);
    size+=sizeof(height_);
    return sizeof(*this) + size;
}
