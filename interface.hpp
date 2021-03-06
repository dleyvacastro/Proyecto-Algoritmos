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

  //Numero de movimientos posibles en esa casilla
  int posibles;

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
  void Aumentar_posibilidades(int x, int y) {inicio[x].posibles++; inicio[y].posibles++;}
public:
  Tablero(int n, int m);
  ~Tablero();
  void mostrartablero();
  void set_inicial(int x, int y);
  casilla * get_inicial();
  casilla * get_inicio();
  int get_size();
  void print_sol();
};

struct Nodo{
  //indice en el arreglo
  int indice;
  //apuntadores a la siguiente casilla del camino
  vector<Nodo*> next;
};

class ListaD{
private:
  Nodo *raiz;
  Tablero *T;
  void podarrama(Nodo* &n);
  bool crea_camino(casilla *c, Nodo* &n, int t);
  void asignar_vecs(casilla *a, Nodo *nextn, vector<casilla*> &cas, vector<int> &pos, Nodo* &n);
public:
  ListaD(Tablero *k);
  ~ListaD();
  void crear_caminos();
};

Nodo * inicia_nodo(casilla *c);
void selectionSort(vector<int>& vec,  vector<Nodo*>& node, vector<casilla*>& cas);
void swap(int i, int j, vector<int>& vec);
void swap(int i, int j, vector<Nodo*>& vec);
void swap(int i, int j, vector<casilla*>& vec);
#endif
