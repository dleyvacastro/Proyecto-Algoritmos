#ifndef _INTERFACE_HPP_
#define _INTERFACE_HPP_
#include <iostream>
#include <stdexcept>

using namespace std;

struct casilla{
  //indice en el arreglo
  int indice;
  //coordenada (x,y)
  int x;
  int y;
  //turno en que el caballo esta en la casilla
  int turno;

  //adyacencia
  //cuadrante arriba a la izquierda
  casilla *ai;
  casilla *ad;
  //cuadrante arriba a la derecha
  casilla *bi;
  casilla *bd;
  //cuadrante abajo a la izquierda
  casilla *ci;
  casilla *cd;
  //cuadrante abajo a la derecha
  casilla *di;
  casilla *dd;
};

class Tablero{
private:
  casilla *inicio;
  int columnas;
  int filas;
  int size;
  void inicializar_casillas();
public:
  Tablero(int n, int m);
  ~Tablero();
  void mostrartablero();
};


#endif
