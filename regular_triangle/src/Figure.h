#pragma once

#include <iostream>

using namespace std;

class Figure{
public:
      /**
       * Creates Figure with center (x; y) and border color c
       * Figure is invisible
       * 
       * @param c Border color
       * @param x x of center
       * @param y y of center
      */
     
      Figure(int c, int x, int y);
      virtual ~Figure();
      // сместить фигуру на (dx,dy) – только видимую.
      void move(int dx, int dy); 
      // Установить цвет фигуры – только видимой.
      void setBorderColor(int c); 
      // Получить цвет.
      int getBorderColor() const; 
      // Показать/спрятать фигуру.
      void setVisible(bool isVisible = true); 
      // Признак видимости.
      bool isVisible() const; 
      // Вычислить периметр и площадь фигуры.
      virtual void clacParms(float& perimeter, float& area) const;
                  
private:
      // цвет
      int c; 
      // видимость
      bool visible; 

protected:
      // базоваяя точка
      int x,y; 

      virtual void draw() const;
};


