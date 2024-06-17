#ifndef TIPO_EDIFICIO_H_INCLUDED
#define TIPO_EDIFICIO_H_INCLUDED
#include <string>
#include "Material.h"

const int CANT_MAX_MATERIALES = 3;

class Tipo_edificio{

    private:

    std::string nombre_edificio;
    Material materiales_requeridos[CANT_MAX_MATERIALES];
    int cant_maxima;
    bool produce_materiales;
    Material material_generado;

    public:
    
    // Pre: -
    // Post: Inicializa en 0 los atributos del tipo de edificio.
    Tipo_edificio();

    // Pre: -
    // Post: Inicializa el vector de materiales requeridos con 0.
    void inicializar_vector_materiales();
    
    // Pre: -
    // Post: Se obtienen los atributos del tipo de edificio.
    void obtener_tipo_edificio(std::string nombre_edificio, int cant_maxima, Material materiales_requeridos[CANT_MAX_MATERIALES]);
    
    // Pre: -
    // Post: Devuelve el nombre del tipo de edificio.
    std::string devolver_nombre_tipo_edificio();

    // Pre: -
    // Post: Devuelve la cantidad maxima de tipo de edificios
    int devolver_cant_maxima();

    // Pre: -
    // Post: Devuelve todos los materiales requeridos del tipo de edificio.
    Material * devolver_materiales();
    
    // Pre: Posicion entre 0 y 2 inclusive.
    // Post: Devuelve un material por posicion.
    Material devolver_material(int posicion);

    // Pre: -
    // Post: devuelve la cantidad de material necesario para la construccion del edificio,
    //       de no existir devuelve -1
    int costo_material_construccion(std::string material);

    // Pre: -
    // Post: Se obtienen los recursos porducidos por el tipo de edificio.
    void obtener_recursos();
    
    // Pre: -
    // Post: Devuelve true si el edificio produce materiales, false en caso contrario.
    bool devolver_produce_materiales();
    
};


#endif // TIPO_EDIFICIO_H_INCLUDED
