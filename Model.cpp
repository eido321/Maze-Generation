#include "Model.hpp"
#include <iostream>
#include <algorithm>

Model::Model(CommandSet &commandSet) : commandSet(commandSet)
{}

void Model::registerObserver(Observer *observer)
{
    observers.push_back(observer);
}

void Model::removeObserver(Observer *observer)
{
    observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
}

void Model::notifyObservers(const string &message)
{
    for (Observer *observer : observers)
    {
        observer->updateModel(message);
    }
}
