#include "interface.hpp"


Tablero::Tablero(int n, int m){
  columnas = n;
  filas = m;
  size = n * m;
  inicio = new casilla[size];
  inicializar_casillas();
}

Tablero::~Tablero(){
  cout << "no me quiero ir señor stark";
  delete[] inicio;
}

void Tablero::inicializar_casillas(){
  //for que incializa las casillas y las mete en el arreglo
  for(int i = 0; i < size; i++){
    casilla c;
    c.indice = i;
    c.x = i % columnas;
    c.y = i / columnas;
    c.turno = -1;
    c.ai = nullptr;
    c.ad = nullptr;
    c.bi = nullptr;
    c.bd = nullptr;
    c.ci = nullptr;
    c.cd = nullptr;
    c.di = nullptr;
    c.dd = nullptr;
    inicio[i] = c;
  }

  //for que inicializa los punteros de cada casilla
  for(int i = 0; i < size - columnas; i++){
    //if que inicializa el puntero de la casilla del cuadrante d derecha y su espejo
    if((inicio[i].x + 2) >= 0 && (inicio[i].x + 2) < columnas && (inicio[i].y + 1) >= 0 && (inicio[i].y + 1) < filas ){
      int j = (columnas * (inicio[i].y+1)) + inicio[i].x + 2;
      inicio[i].dd = &inicio[j];
      inicio[j].ai = &inicio[i];
    }
    //if que inicializa el puntero de la casilla del cuadrante d izquierda y su espejo
    if((inicio[i].x + 1) >= 0 && (inicio[i].x + 1) < columnas && (inicio[i].y + 2) >= 0 && (inicio[i].y + 2) < filas ){
      int j = (columnas * (inicio[i].y+2)) + inicio[i].x + 1;
      inicio[i].di = &inicio[j];
      inicio[j].ad = &inicio[i];
    }
    //if que inicializa el puntero de la casilla del cuadrante c derecha y su espejo
    if((inicio[i].x - 1) >= 0 && (inicio[i].x - 1) < columnas && (inicio[i].y + 2) >= 0 && (inicio[i].y + 2) < filas ){
      int j = (columnas * (inicio[i].y+2)) + inicio[i].x - 1;
      inicio[i].cd = &inicio[j];
      inicio[j].bi = &inicio[i];
    }
    //if que inicializa el puntero de la casilla del cuadrante c izquierda y su espejo
    if((inicio[i].x - 2) >= 0 && (inicio[i].x - 2) < columnas && (inicio[i].y + 1) >= 0 && (inicio[i].y + 1) < filas ){
      int j = (columnas * (inicio[i].y+1)) + inicio[i].x - 2;
      inicio[i].ci = &inicio[j];
      inicio[j].bd = &inicio[i];
    }
  }
}

void Tablero::mostrartablero(){
  //este for imprime el tablero con indices y coordenadas
  for(int i = 0; i < size; i++){
    if(i % columnas == 0 ){
      cout << endl;
    }
    cout << " [" << i << ": " << inicio[i].x << ", " << inicio[i].y << "] ";
  }
  cout << endl;

  // este for imprime los apuntadores a los cuadros aledaños
  for(int i = 0; i < size; i++){
    cout << "indice: "<< i << endl;
    if(inicio[i].ai != nullptr){
      cout << " [ai: " << (inicio[i].ai)->x << ", " << (inicio[i].ai)->y << "] ,";
    }

    if(inicio[i].ad != nullptr){
      cout << " [ad: " << (inicio[i].ad)->x << ", " << (inicio[i].ad)->y << "] ,";
    }

    if(inicio[i].bi != nullptr){
      cout << " [bi: " << (inicio[i].bi)->x << ", " << (inicio[i].bi)->y << "] ,";
    }

    if(inicio[i].bd != nullptr){
      cout << " [bd: " << (inicio[i].bd)->x << ", " << (inicio[i].bd)->y << "] ,";
    }

    if(inicio[i].ci != nullptr){
      cout << " [ci: " << (inicio[i].ci)->x << ", " << (inicio[i].ci)->y << "] ,";
    }

    if(inicio[i].cd != nullptr){
      cout << " [cd: " << (inicio[i].cd)->x << ", " << (inicio[i].cd)->y << "] ,";
    }

    if(inicio[i].di != nullptr){
      cout << " [di: " << (inicio[i].di)->x << ", " << (inicio[i].di)->y << "] ,";
    }

    if(inicio[i].dd != nullptr){
      cout << " [dd: " << (inicio[i].dd)->x << ", " << (inicio[i].dd)->y << "] ,";
    }
    cout << endl;
  }
  cout << endl;
}
