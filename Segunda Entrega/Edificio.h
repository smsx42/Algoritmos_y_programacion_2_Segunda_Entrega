#ifndef EDIFICIO_H_INCLUDED
#define EDIFICIO_H_INCLUDED
#include <string>
#include "Coordenada.h"
#include "Material.h"

class Edificio{

    private:
    
    std::string nombre_edificio;
    Coordenada coordenada;
    Material material_generado;

    public:
    
    //Constructor por defecto.

    // Pre: -
    // Post: Inicializa el edificio.
    Edificio();

    //Constructor de copia.

    // Pre: -
    // Post: Inicializa el edificio.
    Edificio(const Edificio &edificio);

    // Pre: -
    // Post: Devuelve el nombre del edificio.
    std::string obtener_nombre();

    // Pre: -
    // Post: Devuelve la coordenada del edificio.
    Coordenada obtener_coordenada();

    // Pre: -
    // Post: Se cargara el edificio con los parametros dados.
    void modificar_edificio(std::string nombre_edificio, Coordenada coordenada);
    
    // Pre: -
    // Post: Se obtienen la cantidad de recursos que genera un ediificio.
    void obtener_recursos();

    // Pre: -
    // Post: Devuelve los recursos del edificio segun posicion.
    Material devolver_recursos_edificios();
};

#endif // EDIFICIO_H_INCLUDED