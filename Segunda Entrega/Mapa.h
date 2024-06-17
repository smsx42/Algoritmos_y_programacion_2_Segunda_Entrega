#ifndef _MAPA_H_
#define _MAPA_H_
#include "Ciudad.h"
#include "Casillero.h"
#include "Casillero_inaccesible.h"
#include "Casillero_transitable.h"
#include "Casillero_construible.h"
#include "Vector_template.h"

class Mapa{

    private:

    int filas, columnas;
    Casillero *** mapa;
    
    int cant_casilleros_transitables;

    public:
    
    //constructor por defecto
    // Pre: -
    // Post: Crea al mapa con -1 filas y -1 columas, con mapa apuntando a nullptr.
    Mapa();

    // Pre: -
    // Post: Inicializa una matriz mapa de dimension filas x columnas.
    void inicializar_mapa(int filas, int columnas);

    // Pre: La matriz debe estar inicializada y la coordenada valida.
    // Post: Se cargara a la matriz con un casillero construible, transitable o inaccesible segun corresponda y
    //       en la coordenada pasada.
    void cargar_casillero_mapa(char tipo_terreno, Coordenada coordenada);

    // Pre: El mapa debe estar inicializado.
    // Post: Se construiran los edificios que se encuentren en la ciudad en los casilleros correspondientes.
    void cargar_edificios_mapa(Ciudad ciudad);

    // Pre: El mapa debe estar inicializado.
    // Post: Se imprimira el mapa por pantalla.
    void mostrar_mapa();

    // Pre: El mapa debe estar inicializado.
    // Post: Se mostrara la informacion del casillero si la coordenada es valida.
    void consultar_casillero(Coordenada);

    // Pre: -
    // Post: devuelve la cantidad de filas
    int obtener_cantidad_filas();

    // Pre: -
    // Post: Devuelve la cantidad de columnas.
    int obtener_cantidad_columnas();

    // Pre: El mapa debe estar inicializado.
    // Post: Devolvera true si se pudo construir el edificio y false en caso contrario.
    bool construir_edificio(Edificio edificio);

    // Pre: El mapa debe estar inicializado.
    // Post: Devolvera true si pudo demoler el edificio y false en caso contrario.
    bool demoler_edificio(Edificio edificio);

    // Pre: -
    // Post: Libera la memoria utilizada por el mapa.
    void limpiar_mapa();


    // Pre: Recibe una cantidad aleatoria dependiendo del tipo de material, la cantidad de filas y columnas y un vector de materiales.
    // Post: Realiza las iteraciones y reemplaza los casilleros del mapa con materiales, se impirma las posiciones de los casilleros.
    void realizar_iteraciones_materiales(int fila, int columna, int cant_aleatoria, int elemento_aleatorio, Material materiales[CANT_MAX_MATERIALES], int &contador_casilleros_transitables);

    // Pre: -
    // Post: Genera aleatoriamente los materiales en el mapa.
    void generar_materiales(int &contador_casilleros_transitables);


};

#endif // _MAPA_H_