#pragma once

#include <queue>
#include <unordered_map>
#include "CommonSearcher.hpp"
#include "Maze2dSearchableAdapter.hpp"
#include "Solution.hpp"
#include "Node.hpp"
#include "Funcs.hpp"

template <class T,class K>
class AstarSolver : public CommonSearcher<T,K>
{
public:
    virtual Solution<T> search(Searchable<T,K> &s) override
    {
        pair<int, int> start = s.getStartState()->getState();
        pair<int, int> end = s.getGoalState()->getState();
        vector<vector<int>> solution = s.getProblemState()->getState();
        int height = s.getHeightState()->getState();
        int width = s.getWidthState()->getState();
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        priority_queue<Node> openSet;
        openSet.emplace(start.first, start.second, 0, manhattanDistance(start.first, start.second, end.first, end.second));

        while (!openSet.empty())
        {
            Node current = openSet.top();
            openSet.pop();

            if (current.row == end.first && current.col == end.second)
            {
                pair<int, int> pos = {end.first, end.second};
                while (pos != start)
                {
                    solution[pos.first][pos.second] = 5; 
                    int nextDir = solution[pos.first][pos.second] - 1;
                    int newRow = pos.first - directions[nextDir].first;
                    int newCol = pos.second - directions[nextDir].second;
                    pos = {newRow, newCol};
                }
                break;
            }

            for (auto dir : directions)
            {
                int newRow = current.row + dir.first;
                int newCol = current.col + dir.second;

                if (newRow >= 0 && newRow < height && newCol >= 0 && newCol < width && solution[newRow][newCol] == 0)
                {
                    int tentativeG = current.g + 1;
                    int heuristic = manhattanDistance(newRow, newCol, end.first, end.second);

                    Node neighbor(newRow, newCol, tentativeG, heuristic);
                    openSet.push(neighbor);
                    solution[newRow][newCol] = 5;
                }
            }
        }
        State<vector<vector<int>>> tmp(solution);
        Solution<T> sol(tmp);
        return sol;
    };
};
