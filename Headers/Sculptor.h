#ifndef SCULPTOR_H
#define SCULPTOR_H
/**
 * @file Sculptor.h
 * @brief Class Sculptor
 * @authors André Luiz e Lucas Gabriel
 * @version 1.0.0
 * @since 31/05/2022
 */

struct Voxel {
  float r,g,b; // Colors
  float a;
// Transparency
  bool isOn; // Included or not
};

/**
 * @brief Sculptor
 * 
 * @param _nx
 * @param _ny
 * @param _nz
 */

class Sculptor {
protected:
  // 3D matrix
  Voxel ***v;
  int nx, ny, nz;   // Dimensions
  float r, g, b, a; // Current drawing color

public:
  Sculptor(int _nx, int _ny, int _nz); // contrutor
  ~Sculptor();                         // des
  void setColor(float r, float g, float b, float alpha);
  void putVoxel(int x, int y, int z);
  void cutVoxel(int x, int y, int z);
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry,int rz);
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry,int rz);
  void writeOFF(const char *filename);
};

#endif