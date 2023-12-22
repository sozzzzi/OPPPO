#ifndef MAINCYCLE_H
#define MAINCYCLE_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <vector>
#include "../lib/list.h"

enum ErrorType
{
    Ok = 0,
    NotEnoughData = 1,
    NonExistObject = 2,
    NonExistColor = 3,
    NonExistCommand = 4,
    EmptyList = 5,
    NonExistFile = 6,
    BadRemove = 7,
    BadInput = 8,
    Error = 9
};
class MainCycle
{
public:
    MainCycle();
    ~MainCycle();
    int addCommand(std::string &command);
    int remCommand(std::string &command);
    int run(const std::string &path_file);
    List *figures;
private:
    int commandRemFigure(const std::string &type_figure);
    int commandRemFigureParams(std::stringstream &ss, const std::string &type_figure);
    int commandRemColor(std::stringstream &ss);
};

#endif // MAINCYCLE_H
