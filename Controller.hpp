#pragma once

#include "Model.hpp"
#include "View.hpp"
#include <string>

class Controller : public Observer {
public:
    Controller(Model& model, View& view);
    void updateModel(const string& message) override;
    void updateView(const string& message) override;

    void start();

private:
    Model& model;
    View& view;
};
