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
  casilla * get_inicio();
  int get_size();
};

struct Nodo{
  //indice en el arreglo
  int indice;
  //coordenada (x,y)
  int x;
  int y;
  //turno en que el caballo esta en la casilla
  int turno;

  //apuntadores a las casillas
  //cuadrante arriba a la izquierda
  Nodo *ai;
  Nodo *ad;
  //cuadrante arriba a la derecha
  Nodo *bi;
  Nodo *bd;
  //cuadrante abajo a la izquierda
  Nodo *ci;
  Nodo *cd;
  //cuadrante abajo a la derecha
  Nodo *di;
  Nodo *dd;
};

class ArbolD{
private:
  Nodo *raiz;
  Tablero *T;
  void podarrama(Nodo* &n);
  bool crea_camino(casilla *c, Nodo* &n, int t);
public:
  ArbolD(Tablero *k);
  ~ArbolD();
  void crear_caminos();
};

Nodo * inicia_nodo(casilla *c);

#endif
