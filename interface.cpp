#include "interface.hpp"

//Tablero
//##############################################################################################
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

//Establece la casilla inicial del camino
void Tablero::set_inicial(int x, int y){
  int i = columnas * y + x;
  inicial = &inicio[i];
  inicio[i].turno = 0;
}

//Retorna la casilla inicial
casilla * Tablero::get_inicial(){
  return inicial;
}

//Retorna apuntador al inicio del Tablero
casilla * Tablero::get_inicio(){
  return inicio;
}

//Retorna el tamaño del tablero
int Tablero::get_size(){
  return size;
}

//Mostrar el tablero
void Tablero::mostrartablero(){
  //este for imprime el tablero con indices y coordenadas
  for(int i = 0; i < size; i++){
    if(i % columnas == 0 ){
      cout << endl;
    }
    cout << " [" << i << ": " << inicio[i].x << ", " << inicio[i].y << ", " << inicio[i].turno << "] ";
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

//##############################################################################################


//ArbolD
//##############################################################################################

//Constructor, recibe un tablero hecho para trabajar
ArbolD::ArbolD(Tablero *k){
  T = k;
  raiz = inicia_nodo(T->get_inicial());
}
//Destructor
ArbolD::~ArbolD(){
  podarrama(raiz);
  cout << "*c muere*\n";
}

//Poda una rama desde un nodo, recursivamente
void ArbolD::podarrama(Nodo* &n){
  if(n != nullptr){
    cout << "borrando " <<  n->x << ", " << n->y << endl;
    podarrama(n->ai);
    podarrama(n->ad);
    podarrama(n->bi);
    podarrama(n->bd);
    podarrama(n->ci);
    podarrama(n->cd);
    podarrama(n->di);
    podarrama(n->dd);
    delete n;
    n = nullptr;
  }
}

//Crea un camino a partir de un nodo, recibe la casilla correspondiente a ese nodo, el nodo desde que se crea y el turno
bool ArbolD::crea_camino(casilla *c, Nodo* &n, int t){
  cout << n->x << ", " << n->y << ", " << t << endl;
  n->turno = t;
  c->turno = t;
  //Si llega al final tiene una solucion
  bool solucion = (t == T->get_size() - 1);
  //Revisa si se puede mover a las casillas
  //Hacia la ai
  if (c->ai != nullptr && c->ai->turno == -1){
    n->ai = inicia_nodo(c->ai);
    //crea el camino a partir del siguiente paso
    if(crea_camino(c->ai, n->ai, t+1))
      //si ese camino era solucion este nodo es olucion
      solucion = true;
  }
  //Hacia ad
  if (c->ad != nullptr && c->ad->turno == -1){
    n->ad = inicia_nodo(c->ad);
    if(crea_camino(c->ad, n->ad, t+1))
      solucion = true;
  }
  //Hacia bi
  if (c->bi != nullptr && c->bi->turno == -1){
    n->bi = inicia_nodo(c->bi);
    if(crea_camino(c->bi, n->bi, t+1))
      solucion = true;
  }
  //Hacia bd
  if (c->bd != nullptr && c->bd->turno == -1){
    n->bd = inicia_nodo(c->bd);
    if(crea_camino(c->bd, n->bd, t+1))
      solucion = true;
  }
  //Hacia ci
  if (c->ci != nullptr && c->ci->turno == -1){
    n->ci = inicia_nodo(c->ci);
    if(crea_camino(c->ci, n->ci, t+1))
      solucion = true;
  }
  //Hacia cd
  if (c->cd != nullptr && c->cd->turno == -1){
    n->cd = inicia_nodo(c->cd);
    if(crea_camino(c->cd, n->cd, t+1))
      solucion = true;
  }
  //Hacia di
  if (c->di != nullptr && c->di->turno == -1){
    n->di = inicia_nodo(c->di);
    if(crea_camino(c->di, n->di, t+1))
      solucion = true;
  }
  //Hacia dd
  if (c->dd != nullptr && c->dd->turno == -1){
    n->dd = inicia_nodo(c->dd);
    if(crea_camino(c->dd, n->dd, t+1))
      solucion = true;
  }
  //Si por ese nodo no se llega a una solucion, lo borra
  if(!solucion){
    podarrama(n);
  }
  //Reestablece la casilla para poder volver a usarla en otras ramas
  c->turno = -1;
  //Retorna si llega a una solucion o no
  return solucion;
}

//Wrapper para crear todos los caminos del arbol
void ArbolD::crear_caminos(){
  casilla *c = &(T->get_inicio()[raiz->indice]);
  crea_camino(c, raiz, 0);
  cout << "arbol hecho\n";
}
//##############################################################################################

//Externos a clases
//##############################################################################################
Nodo * inicia_nodo(casilla *c){
  Nodo *n = new Nodo;
  n->indice = c->indice;
  n->x = c->x;
  n->y = c->y;
  n->ai = nullptr;
  n->ad = nullptr;
  n->bi = nullptr;
  n->bd = nullptr;
  n->ci = nullptr;
  n->cd = nullptr;
  n->di = nullptr;
  n->dd = nullptr;
  return n;
}
//##############################################################################################
