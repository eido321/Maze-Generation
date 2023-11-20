#pragma once

#include "Maze2d.hpp"
#include "Funcs.hpp"

class Maze2dGenerator
{
public:
    virtual ~Maze2dGenerator() = default;
    virtual Maze2d generate(int width,int height,string name) const = 0;
};

