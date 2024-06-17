#include "Edificio.h"
#include "constante.h"

using namespace std;

Edificio::Edificio(){
    
    nombre_edificio = CADENA_VACIA;
    Coordenada coordenada;
    this-> coordenada = coordenada;
    material_generado.obtener_materiales(CADENA_VACIA, NULO);
}

Edificio::Edificio(const Edificio &edificio){
    
    this-> nombre_edificio = edificio.nombre_edificio;
    this-> coordenada = edificio.coordenada;
    obtener_recursos();
}

string Edificio::obtener_nombre(){
    
    return nombre_edificio;
}

Coordenada Edificio::obtener_coordenada( ){
    
    return coordenada;
}

void Edificio::modificar_edificio( std::string nombre_edificio, Coordenada coordenada){
    
    this-> nombre_edificio = nombre_edificio;
    this-> coordenada = coordenada;
}

void Edificio::obtener_recursos(){

    if(nombre_edificio == ASERRADERO){
        material_generado.obtener_materiales(MADERA, 25);
    }
    else if(nombre_edificio == MINA){
        material_generado.obtener_materiales(PIEDRA, 15);
    }
    else if(nombre_edificio == FABRICA){
        material_generado.obtener_materiales(METAL, 40);
    }
    else if(nombre_edificio == PLANTA_ELECTRICA){
        material_generado.obtener_materiales(CADENA_VACIA, 0);
    }
    else if(nombre_edificio == OBELISCO){
        material_generado.obtener_materiales(CADENA_VACIA, 0);
    }
    else if(nombre_edificio == ESCUELA){
        material_generado.obtener_materiales(CADENA_VACIA, 0);
    }

}

Material Edificio::devolver_recursos_edificios(){
    
    return material_generado;
}