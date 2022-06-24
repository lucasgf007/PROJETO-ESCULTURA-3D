#ifndef CUTBOX_H
#define CUTBOX_H
#include "FiguraGeometrica.h"
#include "Sculptor.h"

/**
 * @brief PutShere
 * 
 * @param _x0
 * @param _x1
 * @param _y0
 * @param _y1
 * @param _z0
 * @param _z1
 */

class CutBox : public FiguraGeometrica{
  int x0,x1,y1,y0,z1,z0;
public:
  CutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1){
    x0 = _x0; x1 = _x1; y0 = _y0; z0 = _z0; z1 = _z1;
  }
  void draw(Sculptor &s){
    s.cutBox(x0,x1,y1,y0,z1,z0);
  }

};

#endif // CUTBOX_H