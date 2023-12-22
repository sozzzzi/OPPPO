#ifndef GEOMETRY_H
#define GEOMETRY_H
#include <chrono>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>


enum FigureColor
{
    Red = 0,
    Orange = 1,
    Yellow = 2,
    Green = 3,
    LightBlue = 4,
    Blue = 5,
    Purple = 6,
    ColorError = 7
};
std::wstring convertToString(FigureColor color);
FigureColor wstringToEnum(const std::wstring &color);
FigureColor stringToEnum(const std::string &color);


struct intPoint
{
    int x;
    int y;
};
struct floatPoint
{
    float x;
    float y;
};


class FlatFigure
{
protected:
    std::wstring date_edit;
    FigureColor color;
    bool isValid;
public:
    FlatFigure() = default;
    virtual ~FlatFigure() = default;


    FigureColor getColor();

    std::wstring current_date();

    virtual void print() = 0;
    bool getIsValid() const;
};

class Circle : public FlatFigure
{
private:
    intPoint center;
    int r;
public:
    Circle(std::string x, std::string y, std::string r, std::string color);

    void print() override
    {
        std::wcout << L"Круг (" << center.x << ", "<< center.y <<", " << r <<L"), цвет = " << convertToString(color) << L", дата изменения = " << date_edit << "\n";
    }

    bool checkParamsCircle(int x, int y, int r);
};

class Rectangle : public FlatFigure
{
private:
    floatPoint l, r;
public:
    Rectangle(std::string lx, std::string ly, std::string rx, std::string ry, std::string color);

    void print() override
    {
        std::wcout << L"Прямоугольник ((" << l.x << ", " << l.y <<"), (" << r.x << ", " << r.y << L")), цвет = " << convertToString(color) << L", дата изменения = " << date_edit <<"\n";
    }

    bool checkParamsRectangle(float lx, float ly, float rx, float ry);
};

class Triangle : public FlatFigure
{
private:
    floatPoint first, second, third;
public:
    Triangle(std::string x1, std::string x2, std::string x3, std::string y1, std::string y2, std::string y3, std::string color);

    void print() override
    {
        std::wcout << L"Треугольник ((" << first.x << ", " << first.y <<"), (" << second.x << ", " << second.y  <<"), (" << third.x  <<", " << third.y << L")), цвет = " << convertToString(color) << L", дата изменения = " << date_edit <<"\n";
    }

    bool checkParamsTriangle(float x1, float x2, float x3, float y1, float y2, float y3);
};

#endif // GEOMETRY_H
