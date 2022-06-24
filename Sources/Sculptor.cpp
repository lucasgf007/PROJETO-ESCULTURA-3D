#include "../Headers/Sculptor.h"
#include "cmath"
#include "fstream"
#include "iostream"
#include "iomanip"

/**
 * @file Sculptor.cpp
 * @brief Class Sculptor
 * @authors André Luiz e Lucas Gabriel
 * @version 1.0.0
 * @since 31/05/2022
 */

/**
 * @brief Construir um novo Sculptor::Sculptor object e alocar matriz 3D
 * 
 * @param _nx 
 * @param _ny 
 * @param _nz 
 */

Sculptor::Sculptor(int _nx, int _ny,int _nz) { 
  nx = _nx;
  ny = _ny;
  nz = _nz;
  r=0, g=0, b =0,a=0;

  v = new Voxel **[nx];// do primeiro plano.
  v[0] = new Voxel *[nx*ny];// da primeira linha.
  for (int i = 1; i < nx; i++) {
    v[i] = v[i - 1] + ny;
  }
  v[0][0] = new Voxel [nx*ny*nz];//endereço da primeira coluna.
  for (int i = 1; i < nx*ny; i++) {
      v[0][i] = v[0][i - 1] + nz;
  }

  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      for (int k = 0; k < nz; k++) {
          v[i][j][k].isOn = false;
          v[i][j][k].r = 0;
          v[i][j][k].g = 0;
          v[i][j][k].b = 0;
          v[i][j][k].a = 0;
      }
    }
  }
};

Sculptor::~Sculptor(){
  delete[] v[0][0];
  delete[] v[0];
  delete[] v;
};

/**
 * @brief Setar uma cor para os elementos da matriz
 * 
 * @param r 
 * @param g 
 * @param b 
 * @param alpha 
 */

void Sculptor::setColor(float r, float g, float b, float alpha) {
  this->r = r;
  this->g = g;
  this->b = b;
  this->a = alpha;
};

/**
 * @brief Isere um elemento na matriz com uma determinada cor
 * 
 * @param x 
 * @param y 
 * @param z 
 */

void Sculptor::putVoxel(int x, int y, int z) {
  if (x >= 0 && y >= 0 && z >= 0 && x < nx && y < ny && z < nz) {
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
    v[x][y][z].isOn = true;
  }
};

/**
 * @brief "remove um elemento na matriz" deixa transparente
 * 
 * @param x 
 * @param y 
 * @param z 
 */

void Sculptor::cutVoxel(int x, int y, int z) {
  if (x >= 0 && y >= 0 && z >= 0 && x < nx && y < ny && z < nz) {
    v[x][y][z].isOn = false;
  }
};

/**
 * @brief Cria uma caixa com N dimensões em x, y e z
 * 
 * @param x0 
 * @param x1 
 * @param y0 
 * @param y1 
 * @param z0 
 * @param z1 
 */

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1) {
  for (int i = x0; i <= x1; i++) {
    for (int j = y0; j <= y1; j++) {
      for (int k = z0; k <= z1; k++) {
        if (i >= 0 && j >= 0 && k >= 0 && i < nx && j < ny && k < nz) {
          v[i][j][k].r = r;
          v[i][j][k].g = g;
          v[i][j][k].b = b;
          v[i][j][k].a = a;
          v[i][j][k].isOn = true;
        }
      }
    }
  }
};

/**
 * @brief Cria uma caixa com N dimensões em x, y e z da tranparente
 * 
 * @param x0 
 * @param x1 
 * @param y0 
 * @param y1 
 * @param z0 
 * @param z1 
 */

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1) {
  for (int i = x0; i <= x1; i++) {
    for (int j = y0; j <= y1; j++) {
      for (int k = z0; k <= z1; k++) {
        if (i >= 0 && j >= 0 && k >= 0 && i < nx && j < ny && k < nz) {
          v[i][j][k].isOn = false;
        }
      }
    }
  }
};

/**
 * @brief Cria uma esfera na matriz, com N raio
 * 
 * @param xcenter 
 * @param ycenter 
 * @param zcenter 
 * @param radius 
 */

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius) {
  for (int i = xcenter - radius; i <= xcenter + radius; i++) {
    for (int j = ycenter - radius; j <= ycenter + radius; j++) {
      for (int k = zcenter - radius; k <= zcenter + radius; k++) {
        if ((pow((i - xcenter), 2) + pow((j - ycenter), 2) +
             pow((k - zcenter), 2)) <= pow(radius, 2)) {
          if (i >= 0 && j >= 0 && k >= 0 && i < nx && j < ny && k < nz) {
            v[i][j][k].r = r;
            v[i][j][k].g = g;
            v[i][j][k].b = b;
            v[i][j][k].a = a;
            v[i][j][k].isOn = true;
          }
        }
      }
    }
  }
};

/**
 * @brief 
 * 
 * @param xcenter 
 * @param ycenter 
 * @param zcenter 
 * @param radius 
 */

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius) {
  for (int i = xcenter - radius; i <= xcenter + radius; i++) {
    for (int j = ycenter - radius; j <= ycenter + radius; j++) {
      for (int k = zcenter - radius; k <= zcenter + radius; k++) {
        if ((pow((i - xcenter), 2) + pow((j - ycenter), 2) +
             pow((k - zcenter), 2)) <= pow(radius, 2))
          if (i >= 0 && j >= 0 && k >= 0 && i < nx && j < ny && k < nz) {
            v[i][j][k].r = r;
            v[i][j][k].g = g;
            v[i][j][k].b = b;
            v[i][j][k].a = a;
            v[i][j][k].isOn = false;
          }
      }
    }
  }
};

/**
 * @brief Cria uma Elipisoide 3D na matriz, com N dimensões para x, y e z
 * 
 * @param xcenter 
 * @param ycenter 
 * @param zcenter 
 * @param rx 
 * @param ry 
 * @param rz 
 */

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx,
                            int ry, int rz) {
  for (int i = xcenter - rx; i <= xcenter + rx; i++) {
    for (int j = ycenter - ry; j <= ycenter + ry; j++) {
      for (int k = zcenter - rz; k <= zcenter + rz; k++) {
        if (i >= 0 && j >= 0 && k >= 0 && i < nx && j < ny && k < nz) {
          if ((((float)pow((i - xcenter), 2) / (float)pow(rx, 2)) +
               ((float)pow((j - ycenter), 2) / (float)pow(ry, 2)) +
               ((float)pow((k - zcenter), 2) / (float)pow(rz, 2))) <= 1.0) {
            v[i][j][k].r = r;
            v[i][j][k].g = g;
            v[i][j][k].b = b;
            v[i][j][k].a = a;
            v[i][j][k].isOn = true;
            ;
          }
        }
      }
    }
  }
};

/**
 * @brief 
 * 
 * @param xcenter 
 * @param ycenter 
 * @param zcenter 
 * @param rx 
 * @param ry 
 * @param rz 
 */

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx,
                            int ry, int rz) {
  for (int i = xcenter - rx; i <= xcenter + rx; i++) {
    for (int j = ycenter - ry; j <= ycenter + ry; j++) {
      for (int k = zcenter - rz; k <= zcenter + rz; k++) {
        if (i >= 0 && j >= 0 && k >= 0 && i < nx && j < ny && k < nz) {
          if ((((float)pow((i - xcenter), 2) / (float)pow(rx, 2)) +
               ((float)pow((j - ycenter), 2) / (float)pow(ry, 2)) +
               ((float)pow((k - zcenter), 2) / (float)pow(rz, 2))) <= 1.0) {
            v[i][j][k].r = r;
            v[i][j][k].g = g;
            v[i][j][k].b = b;
            v[i][j][k].a = a;
            v[i][j][k].isOn = false;
            ;
          }
        }
      }
    }
  }
};

/**
 * @brief Cria o arquivo .off
 * 
 * @param filename 
 */

void Sculptor::writeOFF(const char *filename) {
  int n_vertices = 0, n_faces = 0, n_arestas = 0, n_voxel = 0;
  std::ofstream filleout;
  filleout.open(filename); // abrindo o arquivo
  if (!filleout.is_open()) {
    exit(0);
  }
  filleout << std::fixed << std::setprecision(1) << std::endl;
  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      for (int k = 0; k < nz; k++) {
        if (v[i][j][k].isOn) {
          // n_vertices += 8;
          // n_faces += 6;
          n_voxel++;
        };
      }
    }
  }

  n_vertices = n_voxel * 8;
  n_faces = n_voxel * 6;
  filleout << "OFF" << std::endl << n_vertices << " " << n_faces << " " << 0 << std::endl;
  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      for (int k = 0; k < nz; k++) {
        if (v[i][j][k].isOn) {
          filleout << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << std::endl;
          filleout << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << std::endl;
          filleout << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << std::endl;
          filleout << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << std::endl;
          filleout << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << std::endl;
          filleout << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << std::endl;
          filleout << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << std::endl;
          filleout << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << std::endl;
        };
      }
    }
  }
  int aux = 0;
  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      for (int k = 0; k < nz; k++) {
        if (v[i][j][k].isOn) {
          filleout << std::setprecision(0) << "4 " << 0 + 8 * aux << " " << 3 + 8 * aux << " "
                   << 2 + 8 * aux << " " << 1 + 8 * aux << " " << std::setprecision(1) << v[i][j][k].r
                   << " " << v[i][j][k].g << " " << v[i][j][k].b << " "
                   << v[i][j][k].a << std::endl;
          filleout << std::setprecision(0)<< "4 " << 4 + 8 * aux << " " << 5 + 8 * aux << " "
                   << 6 + 8 * aux << " " << 7 + 8 * aux << " "<< std::setprecision(1) << v[i][j][k].r
                   << " " << v[i][j][k].g << " " << v[i][j][k].b << " "
                   << v[i][j][k].a << std::endl;
          filleout << std::setprecision(0)<< "4 " << 0 + 8 * aux << " " << 1 + 8 * aux << " "
                   << 5 + 8 * aux << " " << 4 + 8 * aux << " " << std::setprecision(1)<< v[i][j][k].r
                   << " " << v[i][j][k].g << " " << v[i][j][k].b << " "
                   << v[i][j][k].a << std::endl;
          filleout << std::setprecision(0)<< "4 " << 0 + 8 * aux << " " << 4 + 8 * aux << " "
                   << 7 + 8 * aux << " " << 3 + 8 * aux << " " << std::setprecision(1)<< v[i][j][k].r
                   << " " << v[i][j][k].g << " " << v[i][j][k].b << " "
                   << v[i][j][k].a << std::endl;
          filleout << std::setprecision(0)<< "4 " << 3 + 8 * aux << " " << 7 + 8 * aux << " "
                   << 6 + 8 * aux << " " << 2 + 8 * aux << " " << std::setprecision(1)<< v[i][j][k].r
                   << " " << v[i][j][k].g << " " << v[i][j][k].b << " "
                   << v[i][j][k].a << std::endl;
          filleout << std::setprecision(0)<< "4 " << 1 + 8 * aux << " " << 2 + 8 * aux << " "
                   << 6 + 8 * aux << " " << 5 + 8 * aux << " " << std::setprecision(1)<< v[i][j][k].r
                   << " " << v[i][j][k].g << " " << v[i][j][k].b << " "
                   << v[i][j][k].a << std::endl;
          aux++;
        }
      }
    }
  }
  filleout.close();
};