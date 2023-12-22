#include "maincycle.h"
#include "algorithm"

MainCycle::MainCycle()
{
    figures = new List();;
}

MainCycle::~MainCycle()
{
    delete figures;
}

int MainCycle::commandRemFigure(const std::string &type_figure)
{
    Node* currNode = figures->getHead();
    bool fullCycle = false;
    do
    {
        FlatFigure* tmp = currNode->fig;
        std::string type = typeid(*tmp).name();
        type.erase(0, 1);

        fullCycle = (currNode == figures->getTail());

        if (type == type_figure)
        {
            auto h = currNode->next;
            figures->deleteNode(currNode);
            currNode = h;
        }
        else
            currNode = currNode->next;
    }
    while (!fullCycle);

    return Ok;
}

int MainCycle::commandRemFigureParams(std::stringstream &ss, const std::string &type_figure)
{
    std::vector<std::string> output;
    std::string value;
    while (ss >> value)
        output.push_back(value);


    Node* currNode = figures->getHead();
    bool fullCycle = false;

    if (type_figure == "circle")
    {
        int x, y, r;
        Circle *check;

        if (output.size() == 3)
        {
            std::istringstream (output[0]) >> x;
            std::istringstream (output[1]) >> y;
            std::istringstream (output[2]) >> r;
        }
        else
        {
            return NotEnoughData;
        }
        do
        {
            fullCycle = (currNode == figures->getTail());

            check = dynamic_cast<Circle*>(currNode->fig);
            if (check->checkParamsCircle(x, y, r))
            {
                auto h = currNode->next;
                figures->deleteNode(currNode);
                currNode = h;
            }
            else
                currNode = currNode->next;
        }
        while (!fullCycle);
    }
    else if (type_figure == "rectangle")
    {
        float lx, ly, rx, ry;
        Rectangle *check;

        if (output.size() == 4)
        {
            std::istringstream (output[0]) >> lx;
            std::istringstream (output[1]) >> ly;
            std::istringstream (output[2]) >> rx;
            std::istringstream (output[3]) >> ry;
        }
        else
            return NotEnoughData;
        do
        {
            fullCycle = (currNode == figures->getTail());
            check = dynamic_cast<Rectangle*>(currNode->fig);
            if (check->checkParamsRectangle(lx, ly, rx, ry))
            {
                auto h = currNode->next;
                figures->deleteNode(currNode);
                currNode = h;
            }
            else
                currNode = currNode->next;
        }
        while (!fullCycle);
    }
    else
    {
        float x1, x2, x3, y1, y2, y3;
        Triangle *check;

        if (output.size() == 6)
        {
            std::istringstream (output[0]) >> x1;
            std::istringstream (output[1]) >> y1;
            std::istringstream (output[2]) >> x2;
            std::istringstream (output[3]) >> y2;
            std::istringstream (output[4]) >> x3;
            std::istringstream (output[5]) >> y3;
        }
        else
            return NotEnoughData;

        do
        {
            fullCycle = (currNode == figures->getTail());
            check = dynamic_cast<Triangle*>(currNode->fig);
            if (check->checkParamsTriangle(x1, y1, x2, y2, x3, y3))
            {
                auto h = currNode->next;
                figures->deleteNode(currNode);
                currNode = h;
            }
            else
                currNode = currNode->next;
        }
        while (!fullCycle);
    }
    return Ok;
}

int MainCycle::commandRemColor(std::stringstream &ss)
{
    std::string del_color;
    ss >> del_color;

    Node* currNode = figures->getHead();
    bool fullCycle = false;

    if (stringToEnum(del_color) != ColorError)
    {
        FlatFigure* check;
        do
        {
            check = currNode->fig;

            fullCycle = (currNode == figures->getTail());

            if (check->getColor() == stringToEnum(del_color))
            {
                auto h = currNode->next;
                figures->deleteNode(currNode);
                currNode = h;
            }
            else
                currNode = currNode->next;
        }
        while (!fullCycle);
    }
    else
    {
        return NonExistColor;
    }
    return Ok;
}

int MainCycle::addCommand(std::string &command)
{
    std::transform(command.begin(), command.end(), command.begin(), ::tolower);
    std::stringstream ss(command);
    std::string type;
    ss >> type;
    if (type == "circle")
    {
        std::vector<std::string> output;
        std::string value;
        while (ss >> value)
            output.push_back(value);
        if (output.size() != 4)
            return NotEnoughData;
        if (stringToEnum(output[3]) == ColorError)
            return NonExistColor;
        FlatFigure* new_obj = new Circle(output[0], output[1], output[2], output[3]);
        if (new_obj->getIsValid())
            figures->addList(new_obj);
        else
            return BadInput;
    }
    else if (type == "rectangle")
    {
        std::vector<std::string> output;
        std::string value;
        while (ss >> value)
            output.push_back(value);
        if (output.size() != 5)
            return NotEnoughData;
        if (stringToEnum(output[4]) == ColorError)
            return NonExistColor;
        FlatFigure* new_obj = new Rectangle(output[0], output[1], output[2], output[3], output[4]);
        if (new_obj->getIsValid())
            figures->addList(new_obj);

        else
            return BadInput;
    }
    else if (type == "triangle")
    {
        std::vector<std::string> output;
        std::string value;
        while (ss >> value)
            output.push_back(value);
        if (output.size() != 7)
            return NotEnoughData;
        if (stringToEnum(output[6]) == ColorError)
            return NonExistColor;
        FlatFigure* new_obj = new Triangle(output[0], output[1], output[2], output[3], output[4], output[5], output[6]);
        if (new_obj->getIsValid())
            figures->addList(new_obj);
        else
            return BadInput;
    }
    else
        return NonExistObject;

    return Ok;
}

int MainCycle::remCommand(std::string &command)
{
    std::transform(command.begin(), command.end(), command.begin(), ::tolower);
    std::stringstream ss(command);
    std::string type_rem;
    ss >> type_rem;

    if (figures->getSize() == 0)
        return NotEnoughData;

    if (type_rem == "*")
        figures->deleteList();
    else if (type_rem == "color")
    {
        int code = commandRemColor(ss);
        if (code != Ok)
            return code;
    }
    else if ((type_rem == "circle" || type_rem == "rectangle" || type_rem == "triangle") && (!ss.rdbuf()->in_avail()))
    {
        type_rem[0] = toupper(type_rem[0]);
        commandRemFigure(type_rem);
    }
    else if (type_rem == "circle" || type_rem == "rectangle" || type_rem == "triangle")
    {
        int code = commandRemFigureParams(ss, type_rem);
        if (code != Ok)
            return code;
    }
    else
        return BadRemove;


    return Ok;
}

int MainCycle::run(const std::string &path_file)
{
    std::ifstream ist(path_file);

    if (!ist.is_open())
    {
        std::wcerr << L"Файл не был открыт!" << std::endl;
        return NonExistFile;
    }

    std::string command;
    ist >> command;

    while (!ist.eof())
    {
        if (command == "add")
        {
            std::string cur_line;
            std::getline(ist, cur_line);
            int bufCheck = addCommand(cur_line);
            if (bufCheck != Ok) std::wcout <<L"Неккоректная задача" <<'\n';
        }
        else if (command == "rem")
        {
            std::string cur_line;
            std::getline(ist, cur_line);
            int bufCheck = remCommand(cur_line);
            if (bufCheck != Ok && bufCheck == NotEnoughData) std::wcout <<L"Нечего удалять" <<'\n';
            else if (bufCheck != Ok && bufCheck != NotEnoughData) std::wcout <<L"Неккоректная задача" <<'\n';
        }
        else if (command == "print")
        {
            figures->printList();
            std::wcout << "*************\n";
        }
        else
            std::wcout <<L"Неккоректная задача" <<'\n';
            //return NonExistCommand;

        ist >> command;
        if (ist.eof())
            return Ok;
    }

    delete figures;
    return Ok;
}
