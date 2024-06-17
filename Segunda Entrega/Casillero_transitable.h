#ifndef _CASILLERO_TRANSITABLE_H_
#define _CASILLERO_TRANSITABLE_H_
#include "Casillero.h"
#include "Material.h"

class Casillero_transitable: public Casillero{

    private:

    Material material;
    bool hay_material;

    // Pre: -
    // Post: Determina la representacion del material.
    void determinar_representacion(std::string nombre_material);

    public:
    
    // Constructor con parametro.
    Casillero_transitable(Coordenada coordenada);

    //C onstructor con dos parametros.
    Casillero_transitable(Material material, Coordenada coordenada);

    // Pre: -
    // Post: se cargara el material al casillero transitable
    void agregar_material(Material material);

    // Pre: -
    // Post: Muestra la informacion del casillero.
    void mostrar_informacion();

    // Pre: -
    // Post: Imprime la representacion del casillero.
    void imprimir_representacion();

    // Pre: El edificip es valido.
    // Post: Se carga un edificio al casillero construible.
    bool construir_edificio(Edificio edificio);

    // Pre: -
    // Post: Devuelve true si se demolio el edificio, false en caso contrario.
    bool demoler_edificio();
};

#endif // _CASILLERO_TRANSITABLE_H_