#pragma once

#include <iostream>

using namespace std;

class Figure{
  int c; // цвет
  bool visible;
protected:
  int x,y; // базоваяя точка
  virtual void draw() const;
public:
  Figure(int c, int x, int y);
  ~Figure();
  void move(int dx, int dy); // сместить фигуру на (dx,dy) – только видимую
  void setBorderColor(int c); // Установить цвет фигуры – только видимой.
  int getBorderColor() const; // Получить цвет.
  void setVisible(bool isVisible = true); // Показать/спрятать фигуру.
  void isVisible() const; // Признак видимости.
  virtual void clacParms(float& perimeter, float& area) const;
                  // Вычислить параметр и площадь фигуры.
};