#ifndef _INTERFACE_HPP_
#define _INTERFACE_HPP_
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

struct casilla{
  //indice en el arreglo
  int indice;
  //coordenada (x,y)
  int x;
  int y;
  //turno en que el caballo esta en la casilla
  int turno;

  //Vector que guarda los apuntadores a las casillas a las que se puede mover
  vector<casilla *> ady;

  //apuntadores a las casillas
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
  casilla *inicial;
  int columnas;
  int filas;
  int size;
  void inicializar_casillas();
public:
  Tablero(int n, int m);
  ~Tablero();
  void mostrartablero();
  void set_inicial(int x, int y);
  casilla * get_inicial();
};

class ArbolD{
private:
  casilla *raiz;
  Tablero *T;
  void podarrama();
  bool crea_camino(casilla *c, int t);
public:
  ArbolD(Tablero k);
  ~ArbolD() {}
  bool crear_caminos();
};


#endif
