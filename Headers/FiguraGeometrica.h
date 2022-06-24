#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "Sculptor.h"

/**
 * @brief FiguraGeometrica
 * 
 * @param r
 * @param g
 * @param b
 * @param a
 */

// classe abstrata pois contem PELO MENOS uma funcao virtual pura.
class FiguraGeometrica{
protected:
  float r,g,b,a;
public:  
  virtual ~FiguraGeometrica();
  // funcao virtual pura
  virtual void draw()=0;

};

#endif // FIGURAGEOMETRICA_H