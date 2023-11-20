#include "Mymodal.hpp"
#include <iostream>

void Mymodal::saveMaze(Maze2d &maze,string inFile)
{
    MazeCompression mazeComp(maze);

    ofstream outFile(inFile, ios::binary | ios::app);
    if (!outFile)
    {
        cerr << "Error opening file for writing: "
             << inFile << endl;
        return;
    }

    string mazeName = mazeComp.getMazeName();
    int mazeID = mazeComp.getMazeID();
    int height = mazeComp.getHeight();
    int width = mazeComp.getWidth();
    pair<int, int> start = mazeComp.getStart();
    pair<int, int> end = mazeComp.getEnd();
    vector<pair<int, int>> paths = mazeComp.getPaths();

    int delimiter = -1;
    outFile.write(reinterpret_cast<const char *>(&delimiter), sizeof(delimiter));
    outFile.write(reinterpret_cast<const char *>(&mazeID), sizeof(mazeID));
    int mazeNameLength = mazeName.size();
    outFile.write(reinterpret_cast<const char *>(&mazeNameLength), sizeof(mazeNameLength));
    outFile.write(mazeName.c_str(), mazeNameLength);
    outFile.write(reinterpret_cast<const char *>(&height), sizeof(height));
    outFile.write(reinterpret_cast<const char *>(&width), sizeof(width));
    outFile.write(reinterpret_cast<const char *>(&start), sizeof(start));
    outFile.write(reinterpret_cast<const char *>(&end), sizeof(end));

    int pathsSize = paths.size();
    outFile.write(reinterpret_cast<const char *>(&pathsSize), sizeof(pathsSize));
    for (int i = 0; i < pathsSize; ++i)
    {
        outFile.write(reinterpret_cast<const char *>(&paths[i]), sizeof(paths[i]));
    }
    outFile.close();
}

Maze2d Mymodal::loadMaze(string targetMazeID,string outFile)
{
    MazeCompression mazeComp;

    ifstream inFile(outFile, ios::binary | ios::in);
    if (!inFile)
    {
        cerr << "Error opening file for reading: "
             << outFile << endl;
        return Maze2d();
    }

    while (inFile)
    {
        int delimiter;
        inFile.read(reinterpret_cast<char *>(&delimiter), sizeof(delimiter));

        if (delimiter == -1)
        {
            int mazeID;
            int height;
            int width;
            pair<int, int> start;
            pair<int, int> end;

            inFile.read(reinterpret_cast<char *>(&mazeID), sizeof(mazeID));
            int mazeNameLength;
            inFile.read(reinterpret_cast<char *>(&mazeNameLength), sizeof(mazeNameLength));
            char *mazeNameBuffer = new char[mazeNameLength + 1];
            inFile.read(mazeNameBuffer, mazeNameLength);
            mazeNameBuffer[mazeNameLength] = '\0';
            string mazeName(mazeNameBuffer);
            inFile.read(reinterpret_cast<char *>(&height), sizeof(height));
            inFile.read(reinterpret_cast<char *>(&width), sizeof(width));
            inFile.read(reinterpret_cast<char *>(&start), sizeof(start));
            inFile.read(reinterpret_cast<char *>(&end), sizeof(end));

            int pathsSize;
            inFile.read(reinterpret_cast<char *>(&pathsSize), sizeof(pathsSize));
            vector<pair<int, int>> paths(pathsSize);
            for (int i = 0; i < pathsSize; ++i)
            {
                inFile.read(reinterpret_cast<char *>(&paths[i]), sizeof(paths[i]));
            }

            if (mazeName == targetMazeID)
            {
                mazeComp.setMazeID(mazeID);
                mazeComp.setMazeName(mazeName);
                mazeComp.setHeight(height);
                mazeComp.setWidth(width);
                mazeComp.setStart(start);
                mazeComp.setEnd(end);
                mazeComp.setPaths(paths);

                inFile.close();
                Maze2d maze = MazeCompression::decompress(mazeComp);
                delete[] mazeNameBuffer;
                return maze;
            }
        }
    }

    inFile.close();
    cerr << "Maze ID not found" << endl;
    return Maze2d();
}

void Mymodal::saveSolution(Maze2d &maze,string inFile)
{
    MazeCompression mazeComp(maze);

    ofstream outFile(inFile, ios::binary | ios::app);
    if (!outFile)
    {
        cerr << "Error opening file for writing: "
             << inFile << endl;
        return;
    }

    string mazeName = mazeComp.getMazeName();
    int mazeID = mazeComp.getMazeID();
    int height = mazeComp.getHeight();
    int width = mazeComp.getWidth();
    pair<int, int> start = mazeComp.getStart();
    pair<int, int> end = mazeComp.getEnd();
    vector<pair<int, int>> paths = mazeComp.getPaths();
    vector<pair<int, int>> solves = mazeComp.getSolves();

    int delimiter = -1;
    outFile.write(reinterpret_cast<const char *>(&delimiter), sizeof(delimiter));
    outFile.write(reinterpret_cast<const char *>(&mazeID), sizeof(mazeID));
    int mazeNameLength = mazeName.size();
    outFile.write(reinterpret_cast<const char *>(&mazeNameLength), sizeof(mazeNameLength));
    outFile.write(mazeName.c_str(), mazeNameLength);
    outFile.write(reinterpret_cast<const char *>(&height), sizeof(height));
    outFile.write(reinterpret_cast<const char *>(&width), sizeof(width));
    outFile.write(reinterpret_cast<const char *>(&start), sizeof(start));
    outFile.write(reinterpret_cast<const char *>(&end), sizeof(end));

    int pathsSize = paths.size();
    outFile.write(reinterpret_cast<const char *>(&pathsSize), sizeof(pathsSize));
    for (int i = 0; i < pathsSize; ++i)
    {
        outFile.write(reinterpret_cast<const char *>(&paths[i]), sizeof(paths[i]));
    }
    int solvesSize = solves.size();
    outFile.write(reinterpret_cast<const char *>(&solvesSize), sizeof(solvesSize));
    for (int i = 0; i < solvesSize; ++i)
    {
        outFile.write(reinterpret_cast<const char *>(&solves[i]), sizeof(solves[i]));
    }
    outFile.close();
}

Maze2d Mymodal::loadSolution(string targetMazeID,string outFile)
{
    MazeCompression mazeComp;

    ifstream inFile(outFile, ios::binary | ios::in);
    if (!inFile)
    {
        cerr << "Error opening file for reading: "
             << outFile << endl;
        return Maze2d();
    }

    while (inFile)
    {
        int delimiter;
        inFile.read(reinterpret_cast<char *>(&delimiter), sizeof(delimiter));

        if (delimiter == -1)
        {
            int mazeID;
            int height;
            int width;
            pair<int, int> start;
            pair<int, int> end;

            inFile.read(reinterpret_cast<char *>(&mazeID), sizeof(mazeID));
            int mazeNameLength;
            inFile.read(reinterpret_cast<char *>(&mazeNameLength), sizeof(mazeNameLength));
            char *mazeNameBuffer = new char[mazeNameLength + 1];
            inFile.read(mazeNameBuffer, mazeNameLength);
            mazeNameBuffer[mazeNameLength] = '\0';
            string mazeName(mazeNameBuffer);
            inFile.read(reinterpret_cast<char *>(&height), sizeof(height));
            inFile.read(reinterpret_cast<char *>(&width), sizeof(width));
            inFile.read(reinterpret_cast<char *>(&start), sizeof(start));
            inFile.read(reinterpret_cast<char *>(&end), sizeof(end));

            int pathsSize;
            inFile.read(reinterpret_cast<char *>(&pathsSize), sizeof(pathsSize));
            vector<pair<int, int>> paths(pathsSize);
            for (int i = 0; i < pathsSize; ++i)
            {
                inFile.read(reinterpret_cast<char *>(&paths[i]), sizeof(paths[i]));
            }

            int solvesSize;
            inFile.read(reinterpret_cast<char *>(&solvesSize), sizeof(solvesSize));
            vector<pair<int, int>> solves(solvesSize);
            for (int i = 0; i < solvesSize; ++i)
            {
                inFile.read(reinterpret_cast<char *>(&solves[i]), sizeof(solves[i]));
            }

            if (mazeName == targetMazeID)
            {
                mazeComp.setMazeID(mazeID);
                mazeComp.setMazeName(mazeName);
                mazeComp.setHeight(height);
                mazeComp.setWidth(width);
                mazeComp.setStart(start);
                mazeComp.setEnd(end);
                mazeComp.setPaths(paths);
                mazeComp.setSolves(solves);
                inFile.close();
                Maze2d maze = MazeCompression::decompress(mazeComp);
                delete[] mazeNameBuffer;
                return maze;
            }
        }
    }

    inFile.close();
    cerr << "Maze ID not found" << endl;
    return Maze2d();
}