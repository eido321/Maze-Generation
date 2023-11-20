#include "Maze2d.hpp"
#include "DFSGenerator.hpp"
#include "Maze2dSearchableAdapter.hpp"
#include "BFSSolver.hpp"
#include "AstarSolver.hpp"
#include "Solution.hpp"
class Demo
{
public:
    static void run()
    {
        DFSGenerator dfsGenerator;
        Maze2d maze = dfsGenerator.generate(40, 20, "Demo");
        maze.print();
        Maze2dSearchableAdapter searchableAdapter1(maze);
        BFSSolver<vector<vector<int>>,int> *tmp1 = new BFSSolver<vector<vector<int>>,int>();
        Solution<vector<vector<int>>> sol1 = tmp1->search(searchableAdapter1);
        Maze2d solution1;
        solution1.setGrid(sol1.getSolution().getState());
        solution1.setHeight(maze.getHeight());
        solution1.setWidth(maze.getWidth());
        solution1.setName("BFS");
        solution1.print();
        cout << endl;
        Maze2dSearchableAdapter searchableAdapter2(maze);
        AstarSolver<vector<vector<int>>,int> *tmp2 = new AstarSolver<vector<vector<int>>,int>();
        Solution<vector<vector<int>>> sol2 = tmp2->search(searchableAdapter2);
        Maze2d solution2;
        solution2.setGrid(sol2.getSolution().getState());
        solution2.setHeight(maze.getHeight());
        solution2.setWidth(maze.getWidth());
        solution2.setName("Astar");
        solution2.print();
    }
};
