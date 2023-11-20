#pragma once
#include <iostream>
#include <vector>
#include "State.hpp"

template <class T>
class Solution
{
public:
    Solution(State<T> sol) : m_solution(sol) {}
    ~Solution() {};

    const State<T>& getSolution() const
    {
        return m_solution;
    }

private:
     State<T> m_solution;
};
