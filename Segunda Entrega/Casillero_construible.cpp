#include "Casillero_construible.h"
#include "constante.h"

Casillero_construible::Casillero_construible(Coordenada coordenada){
    
    hay_edificio = FALSO;
    representacion = TERRENO;
    this-> coordenada = coordenada;
}

void Casillero_construible::determinar_representacion(std::string nombre_edificio){
    
    representacion = nombre_edificio[0];
}

Casillero_construible::Casillero_construible(Edificio edificio, Coordenada coordenada){
    
    this-> edificio = edificio;
    hay_edificio = VERDADERO;
    this-> coordenada = coordenada;
    
    determinar_representacion( edificio.obtener_nombre());
}

void Casillero_construible::agregar_material(Material material){
    
    std::cout << "No se puede agragar un material en un casillero construible. " << std::endl;
}

void Casillero_construible::mostrar_informacion() {
    
    std::cout << "Soy un casillero construible y ";

    if(!this-> hay_edificio){
        std::cout << "me encuentro vacio." << std::endl;
    }
    else{
        std::cout << "no me encuentro vacio, en esta ubicacion hay un/una  " << edificio.obtener_nombre() << "." << std::endl;
    }

}

void Casillero_construible::imprimir_representacion(){
    
    if(representacion == TERRENO){
        std::cout << IMAGEN_CONSTRUIBLE << "  ";
        std::cout << RESET;
    }
    else if(representacion == CARACTER_ASERRADERO){
        std::cout << IMAGEN_ASERRADERO << "  ";
        std::cout << RESET;
    }
    else if(representacion == CARACTER_MINA){
        std::cout << IMAGEN_MINA << "  ";
        std::cout << RESET;
    }
    else if(representacion == CARACTER_FABRICA){
        std::cout << IMAGEN_FABRICA << "  ";
        std::cout << RESET;
    }
    else if(representacion == CARACTER_PLANTA_ELECTRICA){
        std::cout << IMAGEN_PLANTA_ELECTRICA << "  ";
        std::cout << RESET;
    }
    else if(representacion == CARACTER_OBELISCO){
        std::cout << IMAGEN_OBELISCO << "  ";
        std::cout << RESET;
    }
    else if(representacion == CARACTER_ESCUELA){
        std::cout << IMAGEN_ESCUELA << "  ";
        std::cout << RESET;
    }
}

bool Casillero_construible::construir_edificio(Edificio edificio) {
    
    bool se_construyo_edificio = FALSO;
    if (!hay_edificio) {
        this->edificio = edificio;
        hay_edificio = VERDADERO;
        determinar_representacion(edificio.obtener_nombre());
        se_construyo_edificio = VERDADERO;
    }
    else std::cout << std::endl << "      Ya se encuentra construido un edificio." << std::endl;

    return se_construyo_edificio;
}

bool Casillero_construible::demoler_edificio(){
    
    bool se_destruyo_edificio = FALSO;
    if(!hay_edificio){
        std::cout << std::endl << "       No hay edificio que demoler." << std::endl;
    }
    else{
        hay_edificio = FALSO;
        se_destruyo_edificio = VERDADERO;
        representacion = TERRENO;
        std::cout << std::endl << "      El edificio fue demolido con exito." << std::endl;
    }
   
    return se_destruyo_edificio;
}