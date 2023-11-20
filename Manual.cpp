#include "Manual.hpp"

Manual::Manual(Maze2d maze)
{
    maze_ = maze;
    player_ = maze.findStart();
    maze_.setCell(player_.first, player_.second, -1);
}

void Manual::MoveLeft()
{
    if (maze_.getCell(player_.first - 1, player_.second) != 1)
    {
        maze_.setCell(player_.first, player_.second, 5);
        maze_.setCell(player_.first - 1, player_.second, -1);
        player_.first--;
    }
    else
    {
        cout << "Cannot move that way" << endl;
    }
}

void Manual::MoveRight()
{
    if (maze_.getCell(player_.first + 1, player_.second) != 1)
    {
        maze_.setCell(player_.first, player_.second, 5);
        maze_.setCell(player_.first + 1, player_.second, -1);
        player_.first++;
    }
    else
    {
        cout << "Cannot move that way" << endl;
    }
}

void Manual::MoveDown()
{
    if (maze_.getCell(player_.first, player_.second + 1) != 1)
    {
        maze_.setCell(player_.first, player_.second, 5);
        maze_.setCell(player_.first, player_.second + 1, -1);
        player_.second++;
    }
    else
    {
        cout << "Cannot move that way" << endl;
    }
}

void Manual::MoveUp()
{
    if (maze_.getCell(player_.first, player_.second - 1) != 1)
    {
        maze_.setCell(player_.first, player_.second, 5);
        maze_.setCell(player_.first, player_.second - 1, -1);
        player_.second--;
    }
    else
    {
        cout << "Cannot move that way" << endl;
    }
}

void Manual::Play()
{
    pair<int, int> finish = maze_.findEnd();
    bool exit = false;
    while (true)
    {
        maze_.print();
        cout << "Choose your move:" << endl;
        cout << "1 - Up" << endl;
        cout << "2 - Down" << endl;
        cout << "3 - Right" << endl;
        cout << "4 - Left" << endl;
        cout << "5 - Exit" << endl;
        char choice;
        cin.get(choice);
        switch (choice)
        {
        case '1':
            MoveUp();
            break;
        case '2':
            MoveDown();
            break;
        case '3':
            MoveRight();
            break;
        case '4':
            MoveLeft();
            break;
        case '5':
            exit = true;
            break;

        default:
            cout << "Invalid option." << endl;
            break;
        }
        if (exit)
        {
            break;
        }
        else if (finish.first == player_.second && finish.second == player_.first)
        {
            maze_.print();
            cout << "You Win!" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
        else
        {
            maze_.print();
        }
    }
}
