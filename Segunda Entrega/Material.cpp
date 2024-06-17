#include "Material.h"
#include "constante.h"


Material::Material(const Material &material){
    
    this-> tipo = material.tipo;
    this-> cantidad = material.cantidad;
}

Material::Material(){
    
    tipo = CADENA_VACIA;
    cantidad = NULO;
}

void Material::obtener_materiales(std::string tipo, int cantidad){
    this-> tipo = tipo;
    this-> cantidad = cantidad;
}

std::string Material::devolver_tipo(){
    return tipo;
}

int Material::devolver_cantidad(){
    return cantidad;
}

void Material::descontar_cantidad(int cantidad){
    this-> cantidad -= cantidad;
}

void Material::agregar_cantidad(int cantidad){
    this->cantidad += cantidad;
}