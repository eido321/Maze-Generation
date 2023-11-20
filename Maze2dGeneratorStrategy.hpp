#pragma once

#include "Maze2dGenerator.hpp"
#include "State.hpp"

class Maze2dGeneratorStrategy {
public:
    virtual ~Maze2dGeneratorStrategy() = default;
    virtual Maze2dGenerator* createGenerator() const = 0;
};
