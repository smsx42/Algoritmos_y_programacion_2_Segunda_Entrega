#ifndef _CASILLERO_H_
#define _CASILLERO_H_
#include "Edificio.h"
#include "Coordenada.h"
#include <iostream>
#include <string>

class Casillero{

    protected:
    
    Coordenada coordenada;
    char representacion;

    public:
   
    // Pre: -
    // Post: se devolvera la representacion del casillero
    char obtener_representacion();

    // Pre: -
    // Post: el casillero mostrara que tipo de casillero es y, de tenerlo, tambien su contenido
    virtual void mostrar_informacion() = 0;

    // Pre: -
    // Post: se imprimira por mantalla la representacion del casillero
    virtual void imprimir_representacion() = 0;

    // Pre: -
    // Post: se construira un edificio o se devolvera la razon por la cual no pudo ser construido
    //       devuelve true si se pudo construir, false en caso contrario
    virtual bool construir_edificio(Edificio edificio) = 0;

    // Pre: -
    // Post: de existir un edificio sera demolido, devuelve true si demolio, false en caso contrario
    virtual bool demoler_edificio() = 0;

    // Pre: -
    // Post: Agrega un material al casillero transitable.
    virtual void agregar_material(Material material) = 0;

    //destructor
    virtual ~Casillero(){};
};

#endif // _CASILLERO_H_