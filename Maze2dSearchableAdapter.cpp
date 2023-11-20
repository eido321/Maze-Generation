#include "Maze2dSearchableAdapter.hpp"

Maze2dSearchableAdapter::Maze2dSearchableAdapter( Maze2d &maze) : maze_(maze) {}

State<pair<int, int>> *Maze2dSearchableAdapter::getStartState()
{
    pair<int, int> startCoords = maze_.findStart();
    return new State<pair<int, int>>(startCoords);
}

State<pair<int, int>> *Maze2dSearchableAdapter::getGoalState()
{
    pair<int, int> goalCoords = maze_.findEnd();
    return new State<pair<int, int>>(goalCoords);
}

State<vector<vector<int>>> *Maze2dSearchableAdapter::getProblemState()
{
    vector<vector<int>> maze = maze_.getGrid();
    return new State<vector<vector<int>>>(maze);
}

State<int> *Maze2dSearchableAdapter::getWidthState(){
    return new State<int>(maze_.getWidth());
}

State<int> *Maze2dSearchableAdapter::getHeightState(){
    return new State<int>(maze_.getHeight());
}

