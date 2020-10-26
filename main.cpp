#include "interface.hpp"

int main(){
  Tablero hola(6, 6);
  hola.set_inicial(5, 5);
  hola.mostrartablero();
  ArbolD chao(&hola);
  chao.crear_caminos();
  return 0;
}
