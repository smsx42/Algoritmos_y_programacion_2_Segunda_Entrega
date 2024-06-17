#ifndef CIUDAD_H_INCLUDED
#define CIUDAD_H_INCLUDED
#include "Tipo_edificio.h"
#include "Edificio.h"
#include "Inventario.h"

class Ciudad{

    private:
    
    // Tipo de edificio:

    Tipo_edificio * tipo_edificios;
    int cant_tipo_edificios;

    // Edificio:

    Edificio * edificios;
    int cant_edificios;

    public:

    //-----------------------------------Tipo de edificio-----------------------------------------

    // Constructor por defecto.

    // Pre: -
    // Post: Inicializa en 0 todos los atributos de la ciudad.
    Ciudad();

    // Pre: -
    // Post: Se obtienen los atributos de los tipos de edificios de la ciudad.
    void obtener_ciudad_tipo_edificios(Tipo_edificio * &edificios, int &cant_tipo_edificios);
    
    // Pre: -
    // Post: Devuelve la posicion del tipo de edificio o -1 de no existir
    //       Tipo_edificio devolver_tipo_edificio(int posicion);
    int devolver_posicion_tipo_edificio(std::string tipo_edificio);

    // Pre: -
    // Post: Devuelve la cantidad de tipos de edificios.
    int devolver_cant_tipo_edificios();
    
    // Pre: -
    // Post: Crea un vector dinamico del tipo de edificios·
    void crear_vector_tipo_edificios();

    // Pre: -
    // Post: Aumenta en una unidad la cantidad de tipo de edificios en la ciudad.
    void aumentar_cant_tipo_edificios();

    // Pre: -
    // Post: Agrega las componentes del tipo de edificio al vector.
    void agregar_tipo_edificio(std::string nombre_tipo_edificio, int cant_maxima, int piedra, int madera, int metal);
    
    // Pre: -
    // Post: Iguala los dos vectores de tipo de edificios.
    void igualar_vectores_tipo_edificios(Tipo_edificio * nuevo_vector_tipo);

    // Pre: -
    // Post: Crea un nuevo vector de tipo de edificios.
    void nuevo_vector_tipo_edificio();
    
    // Pre: -
    // Post: Muestra por pantalla todos los tipos de edificios, sus requisitos y las cantidad maximas.
    void mostrar_tipo_edificios();

    // Pre: -
    // Post: Devuelve todos los tipos de edificios.
    Tipo_edificio * devolver_tipo_edificios();

    // Pre: -
    // Post: Devuelve true si existe un edificio con el nombre pasado, false en caso contrario.
    bool existe_tipo_edificio(std::string nombre_edificio);

    // Pre: -
    // Post: de existir el edificio y se necesite del material para su construccion, se devolvera la cantidad
    //       requerida o -1 en caso contrario
    int costo_material_tipo_edificio( std::string nombre_edificio, std::string material);

    // Pre: -
    // Post: Limpia la memoria dinamica del vector de tipo de edificios.
    void limpiar_tipo_edificio();

    //----------------------------------Edificio-----------------------------------------
    
    // Pre: -
    // Post: Se obtienen los atributos de los edificios de la ciudad.
    void obtener_ciudad_edificios(Edificio * &edificios, int &cant_edificios);
    
    // Pre: La posicion es mayor o igual a 0.
    // Post: Devuelve un edificio por posicion
    Edificio devolver_edificio(int posicion);
    
    // Pre: -
    // Post: Devuelve la cantidad de edificios.
    int devolver_cant_edificios();
    
    // Pre: -
    // Post: Crea un vector de edificios.
    void crear_vector_edificios();
 
    // Pre: -
    // Post: Aumenta en una unidad la cantidad de edificios.
    void aumentar_cant_edificios();
    
    // Pre: -
    // Post: Agrega un edificio al vector de edificios.
    void agregar_edificio( Edificio edificio );

    // Pre: -
    // Post: De encontrarse en el vector de edificios, se elimiara manteniendo el orden del vector y modificando
    //       el tope acordemente
    void eliminar_edificio( Edificio edificio_a_eliminar );
    
    // Pre: El vector de edificios esta bien cargado.
    // Post: Iguala los vectores de edificios.
    void igualar_vectores_edificios(Edificio * nuevo_edificios);

    // Pre: -
    // Post: Devuelve todos los edificios de la ciudad.
    Edificio * devolver_edificios();

    // Pre: La ciudad debe estar inicializada.
    // Post: Devolvera true si es posible construir el edificio, false si ya se alcanzo la cantidad maxima.
    bool hay_capacidad_edifcio(std::string edificio);

    // Pre: La ciudad debe estar inicializada.
    // Post: Se devolvera true si se encontro un edificio en la coordenada dada, guardandolo en edificio
    //       en caso contrario se devolvera false.
    bool buscar_edificio_por_coordenada( Coordenada coordenada, Edificio &edificio );

    // Pre: -
    // Post: Recolecta todos los recuros de los edificios.
    void obtener_recursos_edificios(Inventario &inventario);

    // Pre: Todos los valores son mayores o iguales a 0.
    // Post: Muestra los recursos generados por los edficios.
    void mostrar_recursos_generados(int piedra_obtenida, int madera_obtenida, int metal_obtenido, int contador_aserraderos, int contador_minas, int contador_fabricas);

    // Pre: El tope_edificios debe ser el correcto.
    // Post: se devolvera true si el edificio_a_incluir ya se encuentra en el vector de edificios y
    //       false en caso contrario.
    bool edificio_esta_incluido(std::string * edificios, int tope_edificios, std::string edificio_a_incluir);

    // Pre: La cant_edificios debe ser la correcta.
    // Post: se creara dinamicamente un vector de strings con los nombres de los edificios construidos sin repetir
    //       se devolvera un puntero a la primer posicion del vector y carga la cantidad de elementos.
    std::string * cargar_tipos_edificios_construidos(Edificio * &edificios, int cant_edificios, int &cant_tipos_construidos);

    // Pre: tope_edificios debe ser el correcto
    // Post: se devolvera la cantidad de veces que se encuentra repetido el edificio de interes en el vector de edificios
    //       se cargara el vector de coordenadas con aquellas que pertenezcan a los edificios de interes, modificando el tope_coordenadas acordemente
    int cargar_coordenadas(Edificio * edificios, int tope_edificios, std::string edificio_de_interes, Coordenada * &coordenadas, int &tope_coordenadas);

    // Pre: El tope debe ser el correcto.
    // Post: Se imprimiran todas las coordenadas.
    void imprimir_coordenadas(Coordenada * coordenadas, int tope_coordenadas);

    // Pre: -
    // Post: Muestra por pantallas los edificios construidos.
    void listar_edificios_construidos();
   

    // Pre: -
    // Post: Limpia la memoria dinamica del vector edificios.
    void limpiar_edificios();
};

#endif // CIUDAD_H_INCLUDED