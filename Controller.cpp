#include "Controller.hpp"
#include <iostream>

Controller::Controller(Model& model, View& view)
    : model(model), view(view) {
    model.registerObserver(this);
}

void Controller::updateModel(const string& message) {
    cout << "Controller: Received model update - " << message << endl;
}

void Controller::updateView(const string& message) {
    cout << "Controller: Received view update - " << message << endl;
}

void Controller::start() {
    cout << "Controller: Starting..." << endl;
    view.run();
}
