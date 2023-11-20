#pragma once

#include "Observer.hpp"
#include "CommandSet.hpp"
#include <string>
#include <vector>

class Model
{
public:
    Model(CommandSet &commandSet);
    void registerObserver(Observer *observer);
    void removeObserver(Observer *observer);
    void notifyObservers(const string &message);

private:
    vector<Observer *> observers;
    CommandSet &commandSet;
};
