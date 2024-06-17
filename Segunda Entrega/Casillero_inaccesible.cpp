#include "Casillero_inaccesible.h"
#include "constante.h"

Casillero_inaccesible::Casillero_inaccesible(Coordenada coordenada){
    
    representacion = LAGO;
    this-> coordenada = coordenada;
}

void Casillero_inaccesible::agregar_material(Material material){
    
    std::cout << "No es posible agregar un material a un lago." << std::endl;
}

void Casillero_inaccesible::mostrar_informacion(){
    
    std::cout << "Soy un casillero inaccesible, hay un lago esnte lugar." << std::endl;
}

void Casillero_inaccesible::imprimir_representacion(){
   
    std::cout << IMAGEN_LAGO << "  ";
    std::cout << RESET;
}

bool Casillero_inaccesible::construir_edificio(Edificio edificio){
    
    std::cout << std::endl << "     No es posible construir un edificio en un lago" << std::endl;
    return FALSO;
}

bool Casillero_inaccesible::demoler_edificio(){
   
    std::cout << std::endl << "     No hay edificios en un lago" << std::endl;
    return FALSO;
}