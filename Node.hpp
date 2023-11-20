#include <iostream>
using namespace std;

class Node
{
public:
    int row, col, g, h, f;

    Node(int r, int c, int cost, int heuristic)
        : row(r), col(c), g(cost), h(heuristic), f(cost + heuristic) {}

    bool operator<(const Node &other) const
    {
        return f > other.f; 
    }
};


