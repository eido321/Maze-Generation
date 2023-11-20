#include "MazeCompression.hpp"


MazeCompression::MazeCompression(Maze2d &maze)
{
    vector<int> allMazeIDs = MazeCompression::getAllIDs();
    int unusedID = 1;
    for (int id : allMazeIDs)
    {
        if (id != unusedID)
        {
            break;
        }
        unusedID++;
    }
    mazeID_ = unusedID;
    mazeName_ = maze.getName();
    width_ = maze.getWidth();
    height_ = maze.getHeight();
    start_ = maze.findStart();
    end_ = maze.findEnd();
    for (int i = 0; i < height_; i++)
    {
        for (int j = 0; j < width_; j++)
        {
            if (maze.getGrid()[i][j] == 0)
                paths_.push_back(pair<int, int>(i, j));
            if (maze.getGrid()[i][j] > 3)
                solve_.push_back(pair<int, int>(i, j));
        }
    }
}

Maze2d MazeCompression::decompress(MazeCompression &compressedMaze)
{
    Maze2d maze;
    vector<vector<int>> array(compressedMaze.height_, vector<int>(compressedMaze.width_, 1));
    maze.setHeight(compressedMaze.height_);
    maze.setWidth(compressedMaze.width_);
    maze.setName(compressedMaze.mazeName_);
    for (int i = 0; i < compressedMaze.paths_.size(); i++)
    {
        array[compressedMaze.paths_[i].first][compressedMaze.paths_[i].second] = 0;
    }
    for (int i = 0; i < compressedMaze.solve_.size(); i++)
    {
        array[compressedMaze.solve_[i].first][compressedMaze.solve_[i].second] = 5;
    }
    array[compressedMaze.start_.first][compressedMaze.start_.second] = 2;
    array[compressedMaze.end_.first][compressedMaze.end_.second] = 3;
    maze.setGrid(array);
    return maze;
}

vector<int> MazeCompression::getAllIDs()
{
    vector<int> mazeIDs;

    ifstream inFile1("mazes.bin", ios::binary | ios::in);
    if (!inFile1)
    {
        cerr << "Error opening file for reading: "
                  << "mazes.bin" << endl;
        return mazeIDs;
    }

    while (inFile1)
    {
        int delimiter;
        inFile1.read(reinterpret_cast<char*>(&delimiter), sizeof(delimiter));

        if (delimiter == -1)
        {
            int mazeID;
            inFile1.read(reinterpret_cast<char*>(&mazeID), sizeof(mazeID));
            mazeIDs.push_back(mazeID);
        }
    }
    
    inFile1.close();
    ifstream inFile2("solutions.bin", ios::binary | ios::in);
    if (!inFile2)
    {
        cerr << "Error opening file for reading: "
                  << "solutions.bin" << endl;
        return mazeIDs; 
    }

    while (inFile2)
    {
        int delimiter;
        inFile2.read(reinterpret_cast<char*>(&delimiter), sizeof(delimiter));

        if (delimiter == -1) 
        {
            int mazeID;
            inFile2.read(reinterpret_cast<char*>(&mazeID), sizeof(mazeID));
            mazeIDs.push_back(mazeID);
        }
    }
    
    inFile2.close();
    return mazeIDs;
}

vector<int> MazeCompression::getAllMazesIDs()
{
    vector<int> mazeIDs;

    ifstream inFile("mazes.bin", ios::binary | ios::in);
    if (!inFile)
    {
        cerr << "Error opening file for reading: "
                  << "mazes.bin" << endl;
        return mazeIDs;
    }

    while (inFile)
    {
        int delimiter;
        inFile.read(reinterpret_cast<char*>(&delimiter), sizeof(delimiter));

        if (delimiter == -1)
        {
            int mazeID;
            inFile.read(reinterpret_cast<char*>(&mazeID), sizeof(mazeID));
            mazeIDs.push_back(mazeID);
        }
    }
    
    inFile.close();
    
    return mazeIDs;
}

vector<int> MazeCompression::getAllSolutionsIDs()
{
    vector<int> mazeIDs;

    ifstream inFile("solutions.bin", ios::binary | ios::in);
    if (!inFile)
    {
        cerr << "Error opening file for reading: "
                  << "solutions.bin" << endl;
        return mazeIDs; 
    }

    while (inFile)
    {
        int delimiter;
        inFile.read(reinterpret_cast<char*>(&delimiter), sizeof(delimiter));

        if (delimiter == -1)
        {
            int mazeID;
            inFile.read(reinterpret_cast<char*>(&mazeID), sizeof(mazeID));
            mazeIDs.push_back(mazeID);
        }
    }
    
    inFile.close();
    return mazeIDs;
}
