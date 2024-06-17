#ifndef INVENTARIO_H_INCLUDED
#define INVENTARIO_H_INCLUDED
#include "Material.h"
#include "Vector_template.h"

class Inventario{

    private:
    
    Material * materiales;
    int cantidad_tipo_materiales;

    public:

    // Constructor por defecto
    
    // Pre: -
    // Post: crea un inventario sin ningun material y reserva memoria dinamicamente.
    Inventario();
    
    // Pre: La cantiad_tipo_materiales es un entero positivo.
    // Post: Crea el vector dinamico.
    void crear_vector();

    // Pre: -
    // Post: Inicializa las componentes del vector con 0.
    void inicializar_vector();

    // Pre: -
    // Post: Aumenta en una unidad la cantidad_tipo_materiales.
    void aumentar_tipo_materiales();

    // Pre: -
    // Post: Agrega un elemteto al vector.
    void agregar_material(std::string material, int cantidad);
    
    // Pre: -
    // Post: Imprime por panatalla el inventario.
    void mostrar_inventario();

    // Pre: -
    // Post: Crea un nuevo vector con los datos edl vector anterior mas, el dato agregado.
    void crear_nuevo_vector();
    
    // Pre: -
    // Post: Iguala un vector incremetnado con el nuevo vector.
    void igualar_vectores(Material * nuevo_vector, int cantidad_tipo_materiales);

    // Pre: -
    // Post: Devuelve la cantidad_tipo_materiales.
    int devolver_cantidad_tipo_materiales();

    // Pre: -
    // Post: de existir, devuelve la cantidad disponible del material, de no existir devuelve 0.
    int cantidad_material(std::string material);

    // Pre: -
    // Post: de existir, se descontara la cantidad de material pasada.
    void descontar_material(std::string material, int cantidad);

    // Pre: -
    // Post: de existir, se agregara la mitad de la cantidad de material pasada.
    void agregar_cantidad_material(std::string material, int cantidad);

    // Pre: La posicion es mayor o igual a 0.
    // Post: Devuelve el material por posicion.
    Material devolver_materiales(int posicion);

    // Pre: -
    // Post: Limpia la memoria dinamica.
    void limpiar_inventario();
};

#endif // INVENTARIO_H_INCLUDED