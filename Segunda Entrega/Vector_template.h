#ifndef _VECTOR_TEMPLATE_
#define _VECTOR_TEMPLATE_

template < typename Tipo >
class Vector{

public:

    // Pre: el tope debe ser el correcto
    // Post: agrega el nuevo elemento al vector dinamicamente, aumentando en 1 al tope
    void agregar_elemento( Tipo * &vector, int &tope, Tipo nuevo_elemento );

};

template < typename Tipo >
void Vector< Tipo >::agregar_elemento(Tipo * &vector, int &tope, Tipo nuevo_elemento) {
    Tipo * auxiliar = new Tipo[ tope + 1 ];
    for( int i = 0; i < tope; i++ ){
        auxiliar[i] = vector[i];
    }
    delete []vector;

    auxiliar[tope] = nuevo_elemento;
    tope++;
    vector = auxiliar;
}

#endif //_VECTOR_TEMPLATE_