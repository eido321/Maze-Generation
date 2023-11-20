#pragma once

#include "Searchable.hpp"
#include "Maze2d.hpp"

class Maze2dSearchableAdapter : public Searchable<vector<vector<int>>,int> {
public:
    Maze2dSearchableAdapter( Maze2d& maze);

    State<pair<int, int>>* getStartState() override;
    State<pair<int, int>>* getGoalState() override;
    State<vector<vector<int>>> *getProblemState() override;
    State<int> *getWidthState() override;
    State<int> *getHeightState() override;

     Maze2d& getMaze() {return maze_;};

private:
     Maze2d& maze_;
};
