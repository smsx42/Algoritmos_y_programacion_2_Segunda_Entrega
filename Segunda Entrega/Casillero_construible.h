#ifndef _CASILLERO_CONSTRUIBLE_H_
#define _CASILLERO_CONSTRUIBLE_H_
#include "Casillero.h"

class Casillero_construible: public Casillero{

    private:

    Edificio edificio;
    bool hay_edificio;

    void determinar_representacion(std::string nombre_edificio);

    public:
    
    // Constructor con un paramtero.
    
    // Pre: -
    // Post: Inicializa el casillero construible.
    Casillero_construible(Coordenada coordenada);

    // Constructor con dos parametros.
    
    // Pre: -
    // Post: Inicializa el casillero construible.
    Casillero_construible(Edificio edificio, Coordenada coordenada);

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


#endif // _CASILLERO_CONSTRUIBLE_H_