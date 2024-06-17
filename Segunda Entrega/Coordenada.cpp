#include "Coordenada.h"
#include "constante.h"

Coordenada::Coordenada(int x, int y){
   
    this-> x = x;
    this-> y = y;
}

Coordenada::Coordenada(){
    
    x = NO_EXISTE;
    y = NO_EXISTE;
}

Coordenada::Coordenada(const Coordenada &coordenada){
    
    this-> x = coordenada.x;
    this-> y = coordenada.y;
}

void Coordenada::cargar_coordenada(int x, int y) {
    
    this-> x = x;
    this-> y = y;
}

int Coordenada::coordenada_x(){
    
    return x;
}

int Coordenada::coordenada_y(){
    
    return y;
}