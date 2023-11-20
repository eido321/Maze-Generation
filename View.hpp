#pragma once

#pragma once

#include <string>
#include "Observer.hpp"
#include "CLI.hpp"

class View : public Observer
{
public:
    View(CLI &cli);
    void updateModel(const string &message) override;
    void updateView(const string &message) override;

    void run();

private:
    CLI &cli;
};
