#include <iostream>
#include "GenerateMazeCommand.hpp"
#include "DisplayCommand.hpp"
#include "SaveCommand.hpp"
#include "LoadCommand.hpp"
#include "MazeSizeCommand.hpp"
#include "MazeSizeFileCommand.hpp"
#include "SolveCommand.hpp"
#include "loadSolutionCommand.hpp"
#include "SaveSolutionCommand.hpp"
#include "DisplaySolutionCommand.hpp"
#include "FileCommand.hpp"
#include "DemoCommand.hpp"
#include "ManualPlayCommand.hpp"
#include "DisplayMazesCommand.hpp"
#include "DisplaySolutionsCommand.hpp"
#include "Controller.hpp"

int main()
{
    CommandSet commandSet;

    commandSet.addCommand("dir", new FileCommand);
    commandSet.addCommand("generate maze", new GenerateMazeCommand);
    commandSet.addCommand("display", new DisplayCommand);
    commandSet.addCommand("save maze", new SaveCommand);
    commandSet.addCommand("load maze", new LoadCommand);
    commandSet.addCommand("maze size", new MazeSizeCommand);
    commandSet.addCommand("file size", new MazeSizeFileCommand);
    commandSet.addCommand("solve", new SolveCommand);
    commandSet.addCommand("save solution", new SaveSolutionCommand);
    commandSet.addCommand("load solution", new LoadSolutionCommand);
    commandSet.addCommand("solution display", new DisplaySolutionCommand);
    commandSet.addCommand("all mazes", new DisplayMazesCommand);
    commandSet.addCommand("all solutions", new DisplaySolutionsCommand);
    commandSet.addCommand("run demo", new DemoCommand);
    commandSet.addCommand("play maze", new ManualPlayCommand);

    Model model(commandSet);
    CLI cli(commandSet);
    View view(cli);
    Controller controller(model, view);

    controller.start();

    return 0;
}
