#include <iostream>
#include <algorithm>
#include <random>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

void BorderTheMaze(vector<vector<int>> &maze,int width,int height);
vector<int> generateRandomDirections();
void StartAndEnd(vector<vector<int>> &maze,int width,int height);
void recursion(vector<vector<int>> &maze, int r, int c,int width,int height);
int manhattanDistance(int r1, int c1, int r2, int c2);