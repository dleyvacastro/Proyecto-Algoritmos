#include "interface.hpp"

void Tablero::inicializar_casillas(){

}

Tablero::Tablero(int n, int m){
  largo = n;
  ancho = m;
  inicio = new casilla[largo * ancho];
  inicializar_casillas();
}

Tablero::~Tablero(){
  cout << "no me quiero ir señor stark";
  delete[] inicio;
}
