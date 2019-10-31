#pragma once

#include <iostream>

using namespace std;

#include "Figure.h"

class Triangle: public Figure {
// Реализовать метод draw
public:
  Triangle(int c, int x, int y, int length, int alfa);
  virtual ~Triangle();
  // Вычислить периметр и площадь фигуры.
  virtual void clacParms(float& perimeter, float& area) const;
  // Изменение размеров.
  void setSizes(int length, int alfa);
  // Получить угол.
  int getAlfa() const;
  // Получить длину стороны.
  int getLength() const;
private:
  /// Длина стороны;
  int length;
  /// Угол поворота.
  int alfa;
  /// Проверка корректности параметров.
  bool correctParametr(int length, int alfa);
protected:
  virtual void draw() const;
};