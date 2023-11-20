#pragma once

#include <string>
#include <memory>
#include <utility>
using namespace std;

template <class T>
class State {
public:
    State(const T& state) : m_state(state), m_cost(0), m_cameFrom(nullptr) {}
    ~State() {}

    bool operator==(const State& s) { return m_state == s.m_state; }
    const T& getState() const { return m_state; }
    void setCameFrom(State* cameFrom) { m_cameFrom = cameFrom; }
    const State* getCameFrom() const { return m_cameFrom.get(); }

private:
    T m_state;
    double m_cost;
    State* m_cameFrom;
};
