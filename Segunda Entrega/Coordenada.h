#ifndef _COORDENADA_H_
#define _COORDENADA_H_

class Coordenada{

    private:
    
    int x;
    int y;
    
    public:
    
    // Constructor con parametros.
    
    // Pre: -
    // Post: crea una coordenada (x,y)
    Coordenada(int x, int y);

    // Constructor por defecto.
    
    // Pre: -
    // Post: crea una coordenada con x e y = -1.
    Coordenada();

    //Constructor de copia
    Coordenada(const Coordenada &coordenada);

    // Pre: -
    // Post: Carga los valores de los atributos.
    void cargar_coordenada(int x, int y);

    // Pre: -
    // Post: Devuelve la coordenada x.
    int coordenada_x();

    // Pre: -
    // Post: Devuelve la coordenada y.
    int coordenada_y();

};

#endif // _COORDENADA_H_