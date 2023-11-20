#pragma once

#include <string>
using namespace std;

class Observer
{
public:
    Observer(){};
    ~Observer(){};
    virtual void updateModel(const string &message) = 0;
    virtual void updateView(const string &message) = 0;
};
