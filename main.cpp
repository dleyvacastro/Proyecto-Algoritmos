#include "interface.hpp"

int main(){
  Tablero hola(8, 8);
  hola.set_inicial(2, 4);
  hola.mostrartablero();
  ArbolD chao(&hola);
  chao.crear_caminos();
  return 0;
}
