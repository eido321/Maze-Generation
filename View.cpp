#include "View.hpp"
#include <iostream>

View::View(CLI& cli) : cli(cli) {}

void View::updateModel(const string& message) {
    cout << "View: Received model update - " << message << endl;
}

void View::updateView(const string& message) {
    cout << "View: Received view update - " << message << endl;
}

void View::run() {
    cout << "View: Starting user interface..." << endl;
    cli.start();
}
