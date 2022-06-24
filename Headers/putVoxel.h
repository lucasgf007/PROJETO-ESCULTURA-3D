#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "FiguraGeometrica.h"
#include "Sculptor.h"

/**
 * @brief PutVoxel
 * 
 * @param _x
 * @param _y
 * @param _z
 * @param _r
 * @param _g 
 * @param _b
 * @param _a
 */

class PutVoxel : public FiguraGeometrica{
  int x,y,z;
public:
  PutVoxel(int _x,int _y,int _z,float _r, float _g,float _b,float _a){
    x = _x; y = _y; z = _z; r = _r; g = _g; b = _b; a = _a;
  }
  void PutVoxel::draw(Sculptor &s){
    s.setColor(r,g,b,a);
    s.putVoxel(x,y,z);
  }

};


#endif // PUTVOXEL_H