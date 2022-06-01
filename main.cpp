#include "Sculptor.h"
#include <iostream> 

/**
 * @file main.cpp
 * @brief Função main onde é chamada a Class Sculptor
 * @authors André Luiz/Lucas Gabriel
 * @version 1.0.0
 * @since 31-05-2022
 */

int main() {
  
  Sculptor olaf(30,30,30); 
  // corpo
  olaf.setColor(1.0,1.0,1.0,1.0); // branco
  olaf.putSphere(15,15,6,7); // 1 bola de neve (maior)
  olaf.cutBox(7,23,7,23,10,14); // corte
  olaf.putSphere(15,15,13,6); // 2 bola de neve (menor)
  olaf.cutVoxel(15,11,22);
  olaf.cutVoxel(15,9,13);
  olaf.cutVoxel(15,8,6);

  olaf.cutVoxel(15,20,22);
  olaf.cutVoxel(15,21,13);
  olaf.cutVoxel(15,22,6);
  olaf.cutVoxel(8,15,6);
  olaf.cutVoxel(9,15,13);
  olaf.cutVoxel(10,15,22);

  // cachecol
  olaf.setColor(1.0,0,0,0);
  olaf.putSphere(15,15,17,5);
  olaf.cutBox(10,20,10,20,19,22);
  olaf.cutBox(10,20,10,20,16,15);
  olaf.putVoxel(19,12,16);
  olaf.putVoxel(19,12,15);
  olaf.putVoxel(19,11,15);
  olaf.putVoxel(19,11,14);
  olaf.putVoxel(18,10,14);


  // cabeça 
  olaf.setColor(1.0,1.0,1.0,1.0); // branco
  olaf.putEllipsoid(15,15,22,5,5,8);

  // olhos
  olaf.setColor(0,0,0,0); // preto
  olaf.putVoxel(19,14,24);
  olaf.putVoxel(19,16,24);

  // botões
  olaf.putVoxel(22,15,6); // botao 1
  olaf.putVoxel(21,15,13); // botao 2

  // nariz
  olaf.setColor(1.0,0.5,0,0); // laranja
  olaf.putVoxel(20,15,23); 
  olaf.putVoxel(21,15,23);
  olaf.putVoxel(22,15,23);
  olaf.cutVoxel(20,15,22);
  // olaf.putBox(20,22,14,16,22,22);

  // boca
  olaf.setColor(0.6,1.0,1.0,0); // azul claro
  olaf.putVoxel(19,15,19);
  olaf.putVoxel(19,15,20);
  olaf.putVoxel(19,14,20);
  olaf.putVoxel(19,16,20);
  olaf.putVoxel(19,13,21);
  olaf.putVoxel(19,17,21);
  olaf.putVoxel(19,14,21);
  olaf.putVoxel(19,15,21);
  olaf.putVoxel(19,16,21);

  // braços
  olaf.setColor(0.2,0.1,0,0); // preto
  olaf.putVoxel(15,9,14);
  olaf.putVoxel(15,8,14);
  olaf.putVoxel(15,7,14);
  olaf.putVoxel(15,6,14);
  olaf.putVoxel(15,5,14);
  olaf.putVoxel(15,5,15);
  olaf.putVoxel(15,5,16);
  olaf.putVoxel(15,5,17);
  olaf.putVoxel(15,4,18);
  olaf.putVoxel(15,6,18);

  
  olaf.putVoxel(15,21,14);
  olaf.putVoxel(15,22,14);
  olaf.putVoxel(15,23,14);
  olaf.putVoxel(15,24,14);
  olaf.putVoxel(15,25,14);
  olaf.putVoxel(15,25,15);
  olaf.putVoxel(15,25,16);
  olaf.putVoxel(15,25,17);
  olaf.putVoxel(15,26,18);
  olaf.putVoxel(15,24,18);
  
  // grava a escultura digital no arquivo "olaf.off"
  olaf.writeOFF("olaf.off");

}