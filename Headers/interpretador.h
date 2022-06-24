#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H
#include "FiguraGeometrica.h"
#include <vector>
#include <string>

/**
 * @brief Interpretador
 * 
 * @param dimx
 * @param dimy
 * @param dimz
 * @param r
 * @param g
 * @param b
 * @param a
 */

using namespace std;
class Interpretador{
    int dimx, dimy, dimz;
    float r, g, b, a;
public:
    Interpretador();
    vector<FiguraGeometrica*> parse(string filename);

    int getDimX();
    int getDimY();
    int getDimZ();
};

#endif // INTERPRETADOR_H