#include "interface.hpp"

int main(){
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      Tablero tablero(8, 8);
      cout << "/-------------------------/" << endl;
      cout << "inicial: " << i << ", " << j << endl;
      tablero.set_inicial(i, j);
      ListaD arbol(&tablero);
      arbol.crear_caminos();
      tablero.print_sol();
    }
  }

  //Peor caso
  // Tablero tablero(7,7);
  // tablero.set_inicial(0,1);
  // ListaD lista(&tablero);
  // lista.crear_caminos();
  // tablero.print_sol();
  return 0;
}
