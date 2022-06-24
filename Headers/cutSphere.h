#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "FiguraGeometrica.h"
#include "Sculptor.h"

/**
 * @brief PutShere
 * 
 * @param _xcenter
 * @param _ycenter
 * @param _zcenter
 * @param _radius
 */

class CutSphere : public FiguraGeometrica{
  int xcenter,  ycenter,  zcenter,  radius;
public:
  CutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius){
     xcenter = _xcenter,  ycenter =  _ycenter,  zcenter = _zcenter,  radius = _radius;
  }
  void draw(Sculptor &s){
    s.cutSphere(xcenter,  ycenter,  zcenter,  radius);
  }

};

#endif // CUTSPHERE_H