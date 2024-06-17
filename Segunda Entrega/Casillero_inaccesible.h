#ifndef _CASILLERO_INACCESIBLE_H_
#define _CASILLERO_INACCESIBLE_H_
#include "Casillero.h"

class Casillero_inaccesible: public Casillero{


    public:
    
    // Constructor con un parametro.
    Casillero_inaccesible(Coordenada coordenada);

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

#endif // _CASILLERO_INACCESIBLE_H_