#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "FiguraGeometrica.h"
#include "Sculptor.h"

/**
 * @brief PutShere
 * 
 * @param _x
 * @param _y
 * @param _z
 */

class CutVoxel : public FiguraGeometrica{
  int x,y,z;
public:
  CutVoxel(int _x,int _y,int _z){
    x = _x; y = _y; z = _z;
  }
  void draw(Sculptor &s){
    s.cutVoxel(x,y,z);
  }

};


#endif // CUTVOXEL_H