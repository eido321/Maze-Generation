#pragma once

#include "CommonSearcher.hpp"
#include "Maze2dSearchableAdapter.hpp"
#include "Solution.hpp"
#include <queue>
#include <unordered_map>

template <class T,class K>
class BFSSolver : public CommonSearcher<T,K>
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

        queue<pair<int, int>> q;
        q.push(start);
        bool flag = false;
        while (!q.empty())
        {
            if(flag)
                break;
            pair<int, int> current = q.front();
            q.pop();

            for (auto dir : directions)
            {
                int newRow = current.first + dir.first;
                int newCol = current.second + dir.second;
                if (newRow == end.first && newCol == end.second)
                {
                    flag = true;
                    break;
                }
                if (newRow >= 0 && newRow < height && newCol >= 0 && newCol < width && solution[newRow][newCol] == 0)
                {
                    solution[newRow][newCol] = 5;
                    q.push({newRow, newCol});
                }
            }
        }
        State<vector<vector<int>>> tmp(solution);
        Solution<T> sol(tmp);
        return sol;
    };
};