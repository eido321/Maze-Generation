//View 

#pragma once

#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <vector>
#include <sstream>
#include <limits>
#include "CommandSet.hpp"
using namespace std;

class CLI
{
private:
    CommandSet &commandSet;

public:
    CLI(CommandSet &cmdSet) : commandSet(cmdSet) {}

    void start()
    {
        string input;

        while (true)
        {
            cout << endl;
            cout << "Enter command (type 'exit' to end session) " << endl;
            cout << "Command List:" << endl;
            cout << "* dir <path>" << endl;
            cout << "* generate maze <name> <height> <width>" << endl;
            cout << "* display <name>" << endl;
            cout << "* save maze <name>" << endl;
            cout << "* load maze <name>" << endl;
            cout << "* maze size <name>" << endl;
            cout << "* file size <name>" << endl;
            cout << "* solve <name> <algorithm> (Algorithm options: BFS / Astar)" << endl;
            cout << "* solution display <name>" << endl;
            cout << "* save solution <name>" << endl;
            cout << "* load solution <name>" << endl;
            cout << "* all mazes" << endl;
            cout << "* all solutions" << endl;
            cout << "* run demo" << endl;
            cout << "* play maze <name>" << endl;
            cout << ">";

            getline(cin, input);
            if (input == "exit")
            {
                break;
            }

            istringstream inputStream(input);
            string line;
            string command;
            string commandName;

            bool combine = false;

            while (getline(inputStream, line))
            {
                istringstream lineStream(line);

                string commandName;
                lineStream >> commandName;

                string command;
                if (commandName == "load")
                {
                    lineStream >> command;
                }
                if (commandName == "save")
                {
                    lineStream >> command;
                }
                if (commandName == "generate")
                {
                    lineStream >> command;
                }
                if (commandName == "maze")
                {
                    lineStream >> command;
                }
                if (commandName == "file")
                {
                    lineStream >> command;
                }
                if (commandName == "solution")
                {
                    lineStream >> command;
                }
                if (commandName == "run")
                {
                    lineStream >> command;
                }
                if (commandName == "play")
                {
                    lineStream >> command;
                }
                if (commandName == "all")
                {
                    lineStream >> command;
                }
                vector<string> arguments;
                char angleBracket;
                while (lineStream >> angleBracket)
                {
                    if (angleBracket == '<')
                    {
                        string argument;
                        getline(lineStream, argument, '>');
                        arguments.push_back(argument);
                    }
                }

                string commandCombine = commandName + " " + command;
                istringstream iss(commandCombine);
                string token;
                string result;
                while (iss >> token)
                {
                    result += token + " ";
                }
                result.pop_back();
                cout << endl;
                commandSet.executeCommand(result, arguments);

                arguments.clear();
            }
        }
    }
};
