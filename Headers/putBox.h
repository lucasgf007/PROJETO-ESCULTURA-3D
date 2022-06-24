#ifndef PUTBOX_H
#define PUTBOX_H
#include "FiguraGeometrica.h"
#include "Sculptor.h"

/**
 * @brief PutBox
 * 
 * @param _x0
 * @param _x1
 * @param _y0
 * @param _y1
 * @param _z0
 * @param _z1
 * @param _r
 * @param _g
 * @param _b
 * @param _a
 */

class PutBox : public FiguraGeometrica{
  int x0,x1,y1,y0,z1,z0;
public:
  PutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1,float _r, float _g,float _b,float _a){
    x0 = _x0; x1 = _x1; y0 = _y0; z0 = _z0; z1 = _z1;r = _r; g = _g; b = _b; a = _a;
  }
  void draw(Sculptor &s){
    s.setColor(r,g,b,a);
    s.putBox(x0,x1,y1,y0,z1,z0);
  }

};
#endif // PUTBOX_H