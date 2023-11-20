// Model

#pragma once

#include <map>
#include <iostream>
#include <functional>
#include "Command.hpp"

class CommandSet
{
public:
    void addCommand(const string &name, Command *command)
    {
        commands[name] = command;
    }

    void executeCommand(const string &name, const vector<string> &parameters)
    {
        auto it = commands.find(name);
        if (it != commands.end())
        {
            it->second->execute(parameters);
        }
        else
        {
            cout << "Command not found: " << name << endl;
        }
    }

private:
    map<string, Command *> commands;
};
