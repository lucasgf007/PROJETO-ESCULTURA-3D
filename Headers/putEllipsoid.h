#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "FiguraGeometrica.h"
#include "Sculptor.h"

/**
 * @brief PutShere
 * 
 * @param _xcenter
 * @param _ycenter
 * @param _zcenter
 * @param _rx
 * @param _ry
 * @param _rz
 * @param _r
 * @param _g
 * @param _b
 * @param _a
 */

class PutSphere : public FiguraGeometrica{
  int xcenter,  ycenter,  zcenter, rx, ry, rz;
public:
  PutSphere(int _xcenter, int _ycenter, int _zcenter,int _rx,int _ry,int _rz,float _r, float _g,float _b,float _a){
     xcenter = _xcenter;  ycenter =  _ycenter;  zcenter = _zcenter; rx = _rx; ry = _ry; rz= _rz; r = _r; g = _g; b = _b; a = _a;
  }
  void draw(Sculptor &s){
    s.setColor(r,g,b,a);
    s.putEllipsoid(xcenter,  ycenter,  zcenter, rx, ry, rz);
  }

};

#endif // CUTBOX_H