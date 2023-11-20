#pragma once

#include <filesystem>
#include "Command.hpp"
#include <iostream>

class FileCommand : public Command
{
public:
    void execute(const vector<string> &params) override
    {
        if (params.size() == 1)
        {
            cout << "Files in path: " << params[0] << endl;
            for (const auto &entry : filesystem::directory_iterator(params[0]))
            {
                cout << entry.path().filename().string();
                if (filesystem::is_directory(entry.status()))
                {
                    cout << " - " << " [folder]";
                }
                cout << endl;
            }
        }
        else
        {
            cout << "Invalid parameters for save command." << endl;
        }
    }
};
