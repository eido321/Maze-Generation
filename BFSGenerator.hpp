#pragma once

#include "Maze2dGenerator.hpp"

class BFSGenerator : public Maze2dGenerator {
public:
    Maze2d generate(int width,int height,string name) const override;
};