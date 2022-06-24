#include <iostream>
#include <vector>
#include "../Headers/Sculptor.h"
#include "../Headers/FiguraGeometrica.h"
#include "../Headers/putVoxel.h"
#include "../Headers/cutVoxel.h"
#include "../Headers/putBox.h"
#include "../Headers/cutBox.h"
#include "../Headers/putSphere.h"
#include "../Headers/cutSphere.h"
#include "../Headers/putEllipsoid.h"
#include "../Headers/cutEllipsoid.h"
#include "../Headers/interpretador.h"

using namespace std;

/**
 * @file main.cpp
 * @brief Função main onde é chamada a Class Sculptor
 * @authors André Luiz/Lucas Gabriel
 * @version 1.0.0
 * @since 24-06-2022
 */

int main(){
    Sculptor *s1;

    Interpretador parser;

    vector<FiguraGeometrica*> figs;

    figs = parser.parse("D:/escultura.txt");

    s1 = new Sculptor(parser.getDimX(), parser.getDimY(), parser.getDimZ());

    for(size_t i = 0; i < figs.size(); i++){
        cout << "draw\n";
        figs[i]->draw(*s1);
    }

    //s1->limpaVoxels();

    s1->writeOFF((char*)"D:/saida.off");
    for(size_t i = 0; i < figs.size(); i++){
        delete figs[i];
    }
    delete s1;
    return 0;
}