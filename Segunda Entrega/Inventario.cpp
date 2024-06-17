#include <iostream>
#include "Inventario.h"
#include "constante.h"

using namespace std;

//Constructor por defecto

Inventario::Inventario(){
    
    cantidad_tipo_materiales = NULO;
    materiales = new Material[cantidad_tipo_materiales + 1];
    inicializar_vector();
}

void Inventario::crear_vector(){
    
    materiales = new Material[cantidad_tipo_materiales + 1];
    inicializar_vector();
}

void Inventario::inicializar_vector(){
    
    for(int i = 0; i < cantidad_tipo_materiales; i++){
        materiales[i].obtener_materiales(CADENA_VACIA, NULO);
    }
}

void Inventario::aumentar_tipo_materiales(){
    
    cantidad_tipo_materiales ++;
}



void Inventario::agregar_material(string material, int cantidad){

    materiales[cantidad_tipo_materiales].obtener_materiales(material, cantidad);
    aumentar_tipo_materiales();
}

void Inventario::mostrar_inventario(){

    for(int i = 0; i < cantidad_tipo_materiales; i++){
        cout << TXT_LIGHT_PURPLE_135 << endl;
        cout << "Material: " << materiales[i].devolver_tipo() <<  "." <<endl;
        cout << "Cantdidad: " << materiales[i].devolver_cantidad() << "." << endl;
        cout << endl;
    }
}

void Inventario::crear_nuevo_vector(){
    
    Material * nuevo_vector;
    nuevo_vector = new Material[cantidad_tipo_materiales];

    for(int i = 0; i < cantidad_tipo_materiales; i++){
        nuevo_vector[i].obtener_materiales(materiales[i].devolver_tipo(), materiales[i].devolver_cantidad());
    }
    delete[] materiales;
    materiales = nullptr;

    igualar_vectores(nuevo_vector, cantidad_tipo_materiales);

    delete[] nuevo_vector;
    nuevo_vector = nullptr;
}

void Inventario::igualar_vectores(Material * nuevo_vector, int cantidad_tipo_materiales){
    
    crear_vector();
    inicializar_vector();

    for(int i = 0; i < cantidad_tipo_materiales; i++){
        materiales[i].obtener_materiales(nuevo_vector[i].devolver_tipo(), nuevo_vector[i].devolver_cantidad());
    }
}

int Inventario::devolver_cantidad_tipo_materiales(){
    
    return cantidad_tipo_materiales;
}

int Inventario::cantidad_material(std::string material){
    
    bool existe_material = FALSO;
    int cantidad_material = NULO;
    int i = 0;
    
    while((!existe_material) && (i < cantidad_tipo_materiales)){
        
        if(materiales[i].devolver_tipo() == material){
            existe_material = VERDADERO;
            cantidad_material = materiales[i].devolver_cantidad();
        }
        i++;
    }
    return cantidad_material;
}

void Inventario::descontar_material(std::string material, int cantidad){
    
    bool existe_material = FALSO;
    int i = 0;
    
    while((!existe_material) && (i < cantidad_tipo_materiales)){
        
        if(materiales[i].devolver_tipo() == material){
            existe_material = VERDADERO;
            materiales[i].descontar_cantidad(cantidad);
        }
        i++;
    }
}

void Inventario::agregar_cantidad_material(std::string material, int cantidad){
    
    bool existe_material = FALSO;
    int i = 0;
    
    while((!existe_material) && (i < cantidad_tipo_materiales)){
        
        if(materiales[i].devolver_tipo() == material){
            existe_material = VERDADERO;
            materiales[i].agregar_cantidad((cantidad));
        }
        i++;
    }
}

Material Inventario::devolver_materiales(int posicion){
    
    return materiales[posicion];
}

void Inventario::limpiar_inventario(){
   
   delete[] materiales;
   materiales = nullptr;
}