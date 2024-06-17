#ifndef CONSTRUCCION_H_INCLUDED
#define CONSTRUCCION_H_INCLUDED
#include <iostream>
#include "Material.h"
#include "Inventario.h"
#include "Ciudad.h"
#include "Mapa.h"
#include "Coordenada.h"
#include "Vector_template.h"

#ifdef __linux__
#define CLR_SCREEN "clear"
#endif // __linux__

#ifdef __MINGW32__
#define CLR_SCREEN "CLS"
#endif // __MINGW32__


// Pre: -
// Post: Muestra por pantalla el menu.
void generar_menu();

// Pre: -
// Post: Imprime por pantalla la opcion para volver al menu, y vuelve a mostrar el menu.
void volver_menu();

// Pre: La opcion es valida.
// Post: Muestra por pantalla los detalles de la opcion.
void mostrar_detalles(int opcion);

// Pre: -
// Post: Genera las opciones.
void generar_opciones(Inventario &inventario, Ciudad &ciudad, Mapa &mapa);

// Pre: Se debe cargar la variable inventario con la clase correspondiente.
// Post: Carga todos los datos del invnetario.
void cargar_inventario(Inventario &inventario);

// Pre: Se debe cargar la variable ciudad con la clase correspondiente.
// Post: Carga todos los datos de la ciudad.
void cargar_ciudad(Ciudad &ciudad);

// Pre: el PATH_MAPA debe apuntar a un archivo mapa con el formato adecuado
// Post: devuelve ERROR si no se pudo abrir el archivo y FUNCIONO de poder hacerlo, cargando al mapa
//       sus datos
int cargar_mapa(Mapa &mapa);

// Pre: El inventario esta cargado correctamente.
// Post: Modifica el archivo de materiales.
void modificar_archivo_materiales(Inventario inventario);

// Pre: La ciudad esta cargada correctamente.
// Post: Modifica el archvio de ubicaciones.
void modificar_archivo_ubicaciones(Ciudad ciudad);

// Pre: La ciudad esta cargada correctamente.
// Post: Lista los tipos de edificios dispoibles para las opciones.
void listar_tipo_edificios(Ciudad ciudad);

// Pre: La ciudad esta cargada correctamnete.
// Post: Le consulta al usuario que edificio desea construir, y devuelve su nombre.
std::string consultar_nombre_edificio(Ciudad ciudad);

// Pre: La ciudad y el invnetario estan cargados correctamente.
// Post: Devuelve true si hay materiales, false en caso contrario.
bool hay_materiales_suficientes(std::string edificio_a_construir, Ciudad ciudad, Inventario inventario);

// Pre: EL mapa esta cargado correctamente.
// Post: Devuelve las coordenadas de la cailla del mapa, dadas por el usuario.
Coordenada usuario_ingresa_coordenada(Mapa mapa);

// Pre:
// Post: en caso de: existir en PATH_EDIFICIOS, haya materiales disponibles y que la coordenada se encuentre libre
//       y sea construible se construira el edificio realizando los cambios necesarios.
void construir_edificio(Ciudad &ciudad, Mapa &mapa, Inventario &inventario);

// Pre: La ciudad debe estar cargada correctamente.
// Post: Imprime por pantalla los edificios de la ciudad.
void listar_edificios(Ciudad ciudad);

// Pre: La ciudad esta cargada correctamente.
// Post: Muestra por pantalla los edificios construidos.
void listar_edificios_construidos(Ciudad ciudad);

// Pre: La ciudad, el mapa y el inventario estan cargados correctamente.
// Post: Elimina un edificio de la ciudad y del mapa, agrega la mitad de los costros de construccion del invnetario.
void demoler_edificio(Ciudad &ciudad, Mapa &mapa, Inventario &inventario);

// Pre: El mapa debe estar cargado correctamente.
// Post: Imprime por pantalla el mapa.
void mostrar_mapa(Mapa mapa);

// Pre: El mapa debe estar cargado correctamente.
// Post: Indica que hay en el casillero, dada las coordenadas.
void consultar_coordenadas(Mapa mapa);

// Pre: El inventario debe estar cargado correctamente.
// Post: Imprime por pantalla los materiales y sus cantidades.
void listar_materiales(Inventario inventario);

// Pre: La ciudad y el inventario estan cargados correctamente.
// Post: Recolecta los recursos producios por los edificios.
void recolectar_recursos(Ciudad ciudad, Inventario &inventario);

// Pre: El mapa esta cargado correctamente.
// Post: Genera recursos de forma aleatoria en los casilleros transitables del mapa.
void lluvia_recursos(Mapa mapa, int &contador_casilleros_transitables);

// Pre: La ciudad, el mapa y el inventario estan cargado correctamente.
// Post: LLama a las funciones de moficiar archivos, y guarda los cambios.
void guardar_cambios(Ciudad ciudad, Mapa mapa, Inventario inventario);

// Pre: -
// Post: Limpia toda las memoria dinamicaa del programa.
void limpiar_programa(Ciudad ciudad, Inventario inventario, Mapa mapa);

// Pre: -
// Post: Empieza la ejecucion del programa.
void empezar_programa();

#endif // CONSTRUCCION_H_INCLUDED