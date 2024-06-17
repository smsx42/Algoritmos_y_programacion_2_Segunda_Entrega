#ifndef MATERIAL_H_INCLUDED
#define MATERIAL_H_INCLUDED
#include <string>


class Material{

    private:

    std::string tipo;
    int cantidad;

    public:

    //Construcor de copia
    // Pre: -
    // Post: Inicializa el material.
    Material(const Material &material);

    //Constructor inicial.

    // Pre: -
    // Post: Se inicializan los atributos de los materiales en 0.
    Material();
    
    // Pre: -
    // Post: Se obtienen el tipo y cantidad de materiales.
    void obtener_materiales(std::string tipo, int cantidad);
    
    // Pre: -
    // Post: Devuelve el tipo de materiales.
    std::string devolver_tipo();
    
    // Pre: -
    // Post: Devuelve la cantidad de materiales.
    int devolver_cantidad();

    // Pre: -
    // Post: se restara la cantidad de material
    void descontar_cantidad(int cantidad);

    // Pre: -
    // Post: se agregara la cantidad de material
    void agregar_cantidad(int cantidad);
};

#endif // MATERIAL_H_INCLUDED
