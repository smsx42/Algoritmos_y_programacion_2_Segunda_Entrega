#include "Casillero_transitable.h"
#include "constante.h"

Casillero_transitable::Casillero_transitable(Coordenada coordenada){
   
    hay_material = FALSO;
    representacion = CAMINO;
    this-> coordenada = coordenada;
}

void Casillero_transitable::determinar_representacion(std::string nombre_material){
   

    if(nombre_material == PIEDRA){
        representacion = 'S';
    }
    else if(nombre_material == MADERA){
        representacion = 'W';
    }
    else if(nombre_material == METAL){
        representacion = 'I';
    }
}

Casillero_transitable::Casillero_transitable(Material material, Coordenada coordenada){
    
    this-> material = material;
    hay_material = VERDADERO;
    this-> coordenada = coordenada;
    
    determinar_representacion(material.devolver_tipo());
}

void Casillero_transitable::agregar_material(Material material){
   
    hay_material = VERDADERO;
    this-> material = material;
    
    determinar_representacion(material.devolver_tipo());
}
void Casillero_transitable::mostrar_informacion(){
    
    std::cout << "Soy un casillero transitable y ";

    if(!this-> hay_material){
        std::cout << "me encuentro vacio" << std::endl;
    }
    else{
        std::cout << "no me encuentro vacio, en este luagar hay un/una " << material.devolver_tipo() << std::endl;
    }

}

void Casillero_transitable::imprimir_representacion(){
    
    if(representacion == CAMINO){
        std::cout << IMAGEN_CAMINO << "  ";
        std::cout << RESET;
    }
    else if(representacion == CARACTER_PIEDRA){
        std::cout << IMAGEN_PIEDRA << "  ";
        std::cout << RESET;
    }
    else if(representacion == CARACTER_MADERA){
        std::cout << IMAGEN_MADERA << "  ";
        std::cout << RESET;
    }
    else if(representacion == CARACTER_METAL){
        std::cout << IMAGEN_METAL << "  ";
        std::cout << RESET;
    }
}

bool Casillero_transitable::construir_edificio(Edificio edificio){
    
    std::cout << std::endl << "     No es posible construir un edificio en un camino" << std::endl;
    return FALSO;
}

bool Casillero_transitable::demoler_edificio(){
    
    std::cout << std::endl << "     No hay edificios en un camino" << std::endl;
    return FALSO;
}