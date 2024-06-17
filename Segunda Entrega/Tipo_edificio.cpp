#include <iostream>
#include "Tipo_edificio.h"
#include "constante.h"

using namespace std;


Tipo_edificio::Tipo_edificio(){
    
    nombre_edificio = CADENA_VACIA;
    cant_maxima = NULO;
    produce_materiales = FALSO;
    material_generado.obtener_materiales(CADENA_VACIA, NULO);
    
    inicializar_vector_materiales();
}

void Tipo_edificio::inicializar_vector_materiales(){
    
    for(int i = 0; i < CANT_MAX_MATERIALES; i++){
       
        materiales_requeridos[i].obtener_materiales(CADENA_VACIA, NULO);
    }
}

void Tipo_edificio::obtener_tipo_edificio(string nombre_edificio, int cant_maxima, Material materiales_requeridos[CANT_MAX_MATERIALES]){
   
    this-> nombre_edificio = nombre_edificio;
    this-> cant_maxima = cant_maxima;
    obtener_recursos();

    for(int i = 0; i < CANT_MAX_MATERIALES; i++){
       
        this-> materiales_requeridos[i].obtener_materiales(materiales_requeridos[i].devolver_tipo(), materiales_requeridos[i].devolver_cantidad());
    }
}

string Tipo_edificio::devolver_nombre_tipo_edificio(){
    
    return nombre_edificio;
}

int Tipo_edificio::devolver_cant_maxima(){
    
    return  cant_maxima;
}

Material * Tipo_edificio::devolver_materiales(){
    
    return materiales_requeridos;
}

Material Tipo_edificio::devolver_material(int posicion){
    
    return materiales_requeridos[posicion];
}

int Tipo_edificio::costo_material_construccion(std::string material){
    
    bool existe_material = FALSO;
    int costo_material_construccion = -1;
    int i = 0;
    
    while((!existe_material) && ( i < CANT_MAX_MATERIALES )){
        if(materiales_requeridos[i].devolver_tipo() == material){
            existe_material = VERDADERO;
            costo_material_construccion = materiales_requeridos[i].devolver_cantidad();
        }
        i++;
    }
    return costo_material_construccion;
}

void Tipo_edificio::obtener_recursos(){

    if(nombre_edificio == ASERRADERO){
        produce_materiales = VERDADERO;
        material_generado.obtener_materiales(MADERA, 25);
    }
    else if(nombre_edificio == MINA){
        produce_materiales = VERDADERO;
        material_generado.obtener_materiales(PIEDRA, 15);
    }
    else if(nombre_edificio == FABRICA){
        produce_materiales = VERDADERO;
        material_generado.obtener_materiales(METAL, 45);
    }
    else if(nombre_edificio == PLANTA_ELECTRICA){
        produce_materiales = FALSO;
        material_generado.obtener_materiales(PLANTA_ELECTRICA, 0);
    }
    else if(nombre_edificio == OBELISCO){
        produce_materiales = FALSO;
        material_generado.obtener_materiales(OBELISCO, 0);
    }
    else if(nombre_edificio == ESCUELA){
        produce_materiales = FALSO;
        material_generado.obtener_materiales(ESCUELA, 0);
    }

}

bool Tipo_edificio::devolver_produce_materiales(){

    return produce_materiales;
}