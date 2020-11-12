#include "interface.hpp"

int main(){
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      Tablero tablero(8, 8);
      cout << "/-------------------------/" << endl;
      cout << "inicial: " << i << ", " << j << endl;
      tablero.set_inicial(i, j);
      ArbolD arbol(&tablero);
      arbol.crear_caminos();
      tablero.print_sol();

    }
  }
  return 0;
}
