#include "Triangle.h"

#pragma once

#include <iostream>

using namespace std;

class FilledTriangle: public Triangle {
public:
    FilledTriangle(int c, int x, int y, int length, int alfa, int f);
    ~FilledTriangle();
    // Изменяет цвет заполнения.
    void setFillColor(int f);
    /// Изменение цвет аграницы.
    virtual void setBorderColor(int c);
private:
    // Цвет заполнения фигуры.
    int f;
protected:
    virtual void draw() const;
};