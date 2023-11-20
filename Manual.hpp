#include "Maze2d.hpp"

class Manual
{
public:
    Manual(Maze2d maze);
    void MoveUp();
    void MoveDown();
    void MoveRight();
    void MoveLeft();
    Maze2d getMaze(){return maze_;};
    void Play();

private:
    pair<int, int> player_;
    Maze2d maze_;
};
