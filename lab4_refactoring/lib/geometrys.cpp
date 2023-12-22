#include "geometrys.h"


FigureColor wstringToEnum(const std::wstring &color)
{
    if (color == L"red")
        return Red;
    else if (color == L"orange")
        return Orange;
    else if (color == L"yellow")
        return Yellow;
    else if (color == L"green")
        return Green;
    else if (color == L"light_blue")
        return LightBlue;
    else if (color == L"blue")
        return Blue;
    else if (color == L"purple")
        return Purple;
    else
        return ColorError;

}

FigureColor FlatFigure::getColor() { return color; }

std::wstring FlatFigure::current_date()
{
    char buffer[80];
    auto now = std::chrono::system_clock::now();
    time_t nowt = std::chrono::system_clock::to_time_t(now);
    std::strftime(buffer, 80, "%d-%m-%Y-%H:%M:%S", localtime(&nowt));
    std::string tmp(buffer);
    std::wstring res(tmp.begin(), tmp.end());
    return res;
}

bool FlatFigure::getIsValid() const
{
    return isValid;
}

std::wstring convertToString(FigureColor color)
{
    switch(color)
    {
    case Red:
        return L"красный";
    case Orange:
        return L"оранжевый";
    case Yellow:
        return L"желтый";
    case Green:
        return L"зеленый";
    case LightBlue:
        return L"голубой";
    case Blue:
        return L"синий";
    case Purple:
        return L"фиолетовый";
    default:
        return L"ошибка";
    }
}

FigureColor stringToEnum(const std::string &color) {
    std::wstring tmp(color.begin(), color.end());
    return wstringToEnum(tmp);
}

Circle::Circle(std::string xval, std::string yval, std::string rval, std::string colorval)
{
    int new_x = 0, new_y = 0, new_r = 0;
    try
    {
        new_x = std::stoi(xval);
        new_y = std::stoi(yval);
        new_r = std::stoi(rval);
        this->center = {new_x, new_y};
        this->r = new_r;
        this->color = stringToEnum(colorval);
        this->date_edit = current_date();
        this->isValid = true;
    }
    catch(std::exception& e)
    {
        std::wcerr << L"Ошибка конвертирования при создании круга!" << '\n';
        this->isValid = false;
        return;
    }
}

bool Circle::checkParamsCircle(int x, int y, int r)
{
    return (this->center.x == x && this->center.y == y && this->r == r);
}

Rectangle::Rectangle(std::string lx, std::string ly, std::string rx, std::string ry, std::string color)
{
    float new_lx = 0, new_ly = 0, new_rx = 0, new_ry = 0;
    try {
        new_lx = std::stof(lx);
        new_ly = std::stof(ly);
        new_rx = std::stof(rx);
        new_ry = std::stof(ry);

        this->l = {new_lx, new_ly};
        this->r = {new_rx, new_ry};
        this->color = stringToEnum(color);
        this->date_edit = current_date();
        this->isValid = true;
    }
    catch(std::exception& e)
    {
        std::wcerr << L"Ошибка конвертирования при создании прямоугольника!" << '\n';
        this->isValid = false;
        return;
    }

}

bool Rectangle::checkParamsRectangle(float lx, float ly, float rx, float ry)
{
    float epsilon = 0.0001f;
    bool forlx = fabs(l.x - lx) < epsilon;
    bool forly = fabs(l.y - ly) < epsilon;
    bool forrx = fabs(r.x - rx) < epsilon;
    bool forry = fabs(r.y - ry) < epsilon;
    return (forlx && forly && forrx && forry);
}

Triangle::Triangle(std::string x1, std::string x2, std::string x3, std::string y1, std::string y2, std::string y3, std::string color)
{
    float new_x1 = 0, new_x2 = 0, new_x3 = 0, new_y1 = 0, new_y2 = 0, new_y3 = 0;
    try
    {
        new_x1 = std::stof(x1);
        new_x2 = std::stof(x2);
        new_x3 = std::stof(x3);
        new_y1 = std::stof(y1);
        new_y2 = std::stof(y2);
        new_y3 = std::stof(y3);

        this->first = {new_x1, new_y1};
        this->second = {new_x2, new_y2};
        this->third = {new_x3, new_y3};
        this->color = stringToEnum(color);
        this->date_edit = current_date();
        this->isValid = true;
    }
    catch(std::exception& e)
    {
        std::wcerr << L"Ошибка конвертирования при создании треугольника!" << '\n';
        this->isValid = false;
        return;
    }

}

bool Triangle::checkParamsTriangle(float x1, float x2, float x3, float y1, float y2, float y3)
{
    float epsilon = 0.0001f;
    return (fabs(this->first.x - x1) < epsilon && fabs(this->first.y - y1) < epsilon && fabs(this->second.x - x2) < epsilon && fabs(this->second.y - y2) < epsilon && fabs(this->third.x - x3) < epsilon && fabs(this->third.y - y3) < epsilon);
}
