#include "../Headers/interpretador.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "../Headers/putVoxel.h"
#include "../Headers/cutVoxel.h"
#include "../Headers/cutBox.h"
#include "../Headers/cutBox.h"
#include "../Headers/cutSphere.h"
#include "../Headers/cutSphere.h"
#include "../Headers/cutEllipsoid.h"
#include "../Headers/cutEllipsoid.h"

Interpretador::Interpretador(){

}

vector<FiguraGeometrica *> Interpretador::parse(std::string filename){
    std::vector<FiguraGeometrica*> figs;
    std::ifstream fin;
    std::stringstream ss;
    std::string s, token;
    int x0, x1, y0, y1, z0, z1, rx, ry, rz, radius;

    fin.open(filename.c_str());
    // verifica se o fluxo foi aberto
    if(!fin.is_open()){
        std::cout << "nao abriu" << filename << std::endl;
        exit(0);
    }

    while(fin.good()){
        // fin >> s
        getline(fin, s);
        // lanca o string s no fluxo ss
        ss.clear();
        ss.str(s);
        ss >> token;
        // realiza o parsing dos tokens
        if(ss.good()){
            // dimensoes da tela
            if(token.compare("dim") == 0){
                ss >> dimx >> dimy >> dimz;
            }else{
                if(token.compare("putvoxel") == 0){
                    ss >> x0 >> y0 >> z0 >> r >> g >> b >> a;
                    figs.push_back(new PutVoxel(x0, y0, z0, r, g, b, a));
                }else if(token.compare("cutvoxel") == 0){
                    ss >> x0 >> y0 >> z0;
                    figs.push_back(new CutVoxel(x0, y0, z0));
                }else if(token.compare("putbox") == 0){
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
                    figs.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
                }else if(token.compare("cutbox") == 0){
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
                    figs.push_back(new CutBox(x0, x1, y0, y1, z0, z1));
                }else if(token.compare("putsphere") == 0){
                    ss >> x0 >> y0 >> z0 >> radius >> r >> g >> b >> a;
                    figs.push_back(new PutSphere(x0, y0, z0, radius, r, g, b, a));
                }else if(token.compare("cutsphere") == 0){
                    ss >> x0 >> y0 >> z0 >> radius;
                    figs.push_back(new CutSphere(x0, y0, z0, radius));
                }else if(token.compare("putellipsoid") == 0){
                    ss >> x0 >> y0 >> z0 >> rx >> ry >> rz >> r >> g >> b >> a;
                    figs.push_back(new PutEllipsoid(x0, y0, z0, rx, ry, rz, r, g, b, a));
                }else if(token.compare("cutellipsoid") == 0){
                    ss >> x0 >> y0 >> z0 >> rx >> ry >> rz;
                    figs.push_back(new CutEllipsoid(x0, y0, z0, rx, ry, rz));
                }
            }
        }
    }
    return(figs);
}

int Interpretador::getDimX(){
    return dimx;
}

int Interpretador::getDimY(){
    return dimy;
}

int Interpretador::getDimZ(){
    return dimz;
}