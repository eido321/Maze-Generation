#pragma once
#include "Maze2dGenerator.hpp"

class DFSGenerator : public Maze2dGenerator
{
public:
    Maze2d generate(int width,int height,string name) const override;
};