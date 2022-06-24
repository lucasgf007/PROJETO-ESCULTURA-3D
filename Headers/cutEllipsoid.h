#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
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
 */

class CutSphere : public FiguraGeometrica{
  int xcenter,  ycenter,  zcenter, rx, ry, rz;
public:
  CutSphere(int _xcenter, int _ycenter, int _zcenter,int _rx,int _ry,int _rz){
    xcenter = _xcenter;  ycenter =  _ycenter;  zcenter = _zcenter; rx = _rx; ry = _ry; rz= _rz;
  }
  void draw(Sculptor &s){
    s.cutEllipsoid(xcenter,  ycenter,  zcenter, rx, ry, rz);
  }

};

#endif // CUTELLIPSOID_H