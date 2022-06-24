#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "FiguraGeometrica.h"
#include "Sculptor.h"

/**
 * @brief PutShere
 * 
 * @param _xcenter
 * @param _ycenter
 * @param _zcenter
 * @param  _radius
 * @param _r
 * @param _g
 * @param _b
 * @param _a
 */

class PutSphere : public FiguraGeometrica{
  int xcenter,  ycenter,  zcenter,  radius;
public:
  PutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius,float _r, float _g,float _b,float _a){
     xcenter = _xcenter;  ycenter =  _ycenter;  zcenter = _zcenter;  radius = _radius;r = _r; g = _g; b = _b; a = _a;
  }
  void draw(Sculptor &s){
    s.setColor(r,g,b,a);
    s.putSphere(xcenter,  ycenter,  zcenter,  radius);
  }

};

#endif // PUTSPHERE_H