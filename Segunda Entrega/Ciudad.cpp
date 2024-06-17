#include <iostream>
#include "Ciudad.h"
#include "constante.h"

using namespace std;

//----------------------------Tipo de edificios-------------------------------------------------

Ciudad::Ciudad(){
    
    cant_tipo_edificios = NULO;

    crear_vector_tipo_edificios();
    
    cant_edificios = NULO;
    crear_vector_edificios();;
    
}

void Ciudad::obtener_ciudad_tipo_edificios(Tipo_edificio * &tipo_edificios, int &cant_tipo_edificios){
    
    tipo_edificios = this-> tipo_edificios;
    cant_tipo_edificios = this-> cant_tipo_edificios;
}

int Ciudad::devolver_posicion_tipo_edificio(std::string tipo_edificio){
    
    int posicion = -1;
    for( int i = 0; i < cant_tipo_edificios; i++){
        if(tipo_edificios[i].devolver_nombre_tipo_edificio() == tipo_edificio){
            posicion = i;
        }
    }
    
    return posicion;
}

int Ciudad::devolver_cant_tipo_edificios(){

    return cant_tipo_edificios;
}

void Ciudad::crear_vector_tipo_edificios(){

    tipo_edificios = new Tipo_edificio[cant_tipo_edificios + 1];
}

void Ciudad::aumentar_cant_tipo_edificios(){

    cant_tipo_edificios++;
}

void Ciudad::agregar_tipo_edificio(string nombre_edificio, int cant_max, int piedra, int madera, int metal){

    Material materiales_requeridos[CANT_MAX_MATERIALES];

    materiales_requeridos[0].obtener_materiales(PIEDRA, piedra);
    materiales_requeridos[1].obtener_materiales(MADERA, madera);
    materiales_requeridos[2].obtener_materiales(METAL, metal);
    
    tipo_edificios[cant_tipo_edificios].obtener_tipo_edificio(nombre_edificio, cant_max, materiales_requeridos);

    aumentar_cant_tipo_edificios();
    nuevo_vector_tipo_edificio();
}

void Ciudad::igualar_vectores_tipo_edificios(Tipo_edificio *nuevo_vector_tipo){

    crear_vector_tipo_edificios();

    for(int i = 0; i < cant_tipo_edificios; i++){
        tipo_edificios[i].obtener_tipo_edificio(nuevo_vector_tipo[i].devolver_nombre_tipo_edificio(), nuevo_vector_tipo[i].devolver_cant_maxima(), nuevo_vector_tipo[i].devolver_materiales());
    }

}

void Ciudad::nuevo_vector_tipo_edificio(){

    Tipo_edificio *nuevo_vector_tipo;
    nuevo_vector_tipo = new Tipo_edificio[cant_tipo_edificios];

    for(int i = 0; i < cant_tipo_edificios; i++){
        nuevo_vector_tipo[i].obtener_tipo_edificio(tipo_edificios[i].devolver_nombre_tipo_edificio(), tipo_edificios[i].devolver_cant_maxima(), tipo_edificios[i].devolver_materiales());
    }

    delete[] tipo_edificios;
    tipo_edificios = nullptr;

    igualar_vectores_tipo_edificios(nuevo_vector_tipo);
    
    delete[] nuevo_vector_tipo;
    nuevo_vector_tipo = nullptr;

}

void Ciudad::mostrar_tipo_edificios(){

   int edificios_construidos = 0;

    for(int i = 0; i < cant_tipo_edificios; i++){
        
        cout << "     " << TXT_UNDERLINE << TXT_LIGHT_PURPLE_135 <<tipo_edificios[i].devolver_nombre_tipo_edificio() << END_COLOR << endl;
        cout << TXT_LIGHT_PURPLE_135 << endl;
        cout << "Costo construccion: " << endl;
        cout << "Piedra: " << tipo_edificios[i].devolver_material(0).devolver_cantidad() << "." << endl;
        cout << "Madera: " << tipo_edificios[i].devolver_material(1).devolver_cantidad() <<  "." << endl;
        cout << "Metal: " << tipo_edificios[i].devolver_material(2).devolver_cantidad() <<  "." << endl;
        for(int j = 0; j < cant_edificios; j++){
            
            if(edificios[j].obtener_nombre() == tipo_edificios[i].devolver_nombre_tipo_edificio()){
                edificios_construidos ++;
            }
        }
            
        cout << "Cantidad actual: " << edificios_construidos << "." << endl;
        cout << "Puede construir: " << tipo_edificios[i].devolver_cant_maxima() - edificios_construidos << "." << endl;
        if(tipo_edificios[i].devolver_produce_materiales()){
            cout << "Este tipo de edificio produce materiales." << endl;
        }
        else{
            cout << "No produce materiales." << endl;;
        } 
        edificios_construidos = 0;
        cout << endl;

    }
}

Tipo_edificio * Ciudad::devolver_tipo_edificios(){
   
    return tipo_edificios;
}

bool Ciudad::existe_tipo_edificio(std::string nombre_edificio) {
   
    bool existe_tipo_edificio = FALSO;
    int i = 0;
    while((!existe_tipo_edificio) && (i < cant_tipo_edificios)){
       
        if( tipo_edificios[i].devolver_nombre_tipo_edificio() == nombre_edificio )
            existe_tipo_edificio = VERDADERO;
        i++;
    }
    return existe_tipo_edificio;
}

int Ciudad::costo_material_tipo_edificio(std::string nombre_edificio, std::string material){
   
    bool existe_tipo_edificio = FALSO;
    int i = 0;
    int posicion;
    while((!existe_tipo_edificio) && (i < cant_tipo_edificios)){
       
        if( tipo_edificios[i].devolver_nombre_tipo_edificio() == nombre_edificio ) {
            existe_tipo_edificio = VERDADERO;
            posicion = i;
        }
        i++;
    }
    if(!existe_tipo_edificio) return -1;

    return tipo_edificios[posicion].costo_material_construccion(material);
}

void Ciudad::limpiar_tipo_edificio(){
    
    delete[] tipo_edificios;
    tipo_edificios = nullptr;
}

//---------------------------------Edificios-----------------------------------------

void Ciudad::obtener_ciudad_edificios(Edificio * &edificios, int &cant_edificios){
    
    edificios = this->edificios;
    cant_edificios = this->cant_edificios;
    
}

Edificio Ciudad::devolver_edificio(int posicion){
    
    return edificios[posicion];
}

int Ciudad::devolver_cant_edificios(){
   
    return cant_edificios;
}

void Ciudad::crear_vector_edificios(){
    
    edificios = new Edificio[cant_edificios + 1];
}


void Ciudad::aumentar_cant_edificios(){
    
    cant_edificios ++;
}


void Ciudad::agregar_edificio(Edificio nuevo_edificio){
   
    Edificio * auxiliar = new Edificio[cant_edificios + 1];
    for( int i = 0; i < cant_edificios; i++ ){
        auxiliar[i] = edificios[i];
    }
    delete []edificios;
    edificios = nullptr;

    auxiliar[cant_edificios]= nuevo_edificio;
    cant_edificios++;
    edificios = auxiliar;
}

void Ciudad::eliminar_edificio(Edificio edificio_a_eliminar){
    
    Edificio auxiliar;
    Coordenada coordenada_actual;
    Coordenada coordenada_edificio_a_eliminar = edificio_a_eliminar.obtener_coordenada();
    
    for( int i = 0; i < (cant_edificios-1); i++ ){
        coordenada_actual = edificios[i].obtener_coordenada();
        
        if( (edificios[i].obtener_nombre() == edificio_a_eliminar.obtener_nombre()) &&
            (coordenada_actual.coordenada_x() == coordenada_edificio_a_eliminar.coordenada_x()) &&
            (coordenada_actual.coordenada_y() == coordenada_edificio_a_eliminar.coordenada_y())){

            auxiliar = edificios[i];
            edificios[i] = edificios[i+1];
            edificios[i+1] = auxiliar;
        }
    }
    cant_edificios--;
}

void Ciudad::igualar_vectores_edificios(Edificio * nuevo_edificios){
    
    crear_vector_edificios();

    for(int i = 0; i < cant_edificios; i++){
        this-> edificios[i] = nuevo_edificios[i];
    }
}

Edificio * Ciudad::devolver_edificios(){
    
    return edificios;
}

bool Ciudad::hay_capacidad_edifcio(std::string edificio){
    
    bool hay_capacidad_edificio = FALSO;
    if(existe_tipo_edificio(edificio)){
        int cantidad_construidos = 0;
        
        for(int i = 0; i < cant_edificios; i++){
            
            if(edificios[i].obtener_nombre() == edificio){
                cantidad_construidos++;
            }
        }
        int posicion = devolver_posicion_tipo_edificio( edificio );
        if(cantidad_construidos < tipo_edificios[posicion].devolver_cant_maxima()){
            hay_capacidad_edificio = VERDADERO;
        }
    }
    return hay_capacidad_edificio;
}

bool Ciudad::buscar_edificio_por_coordenada(Coordenada coordenada, Edificio &edificio){
   
    bool se_encontro_edificio = FALSO;
    int i = 0;
    Coordenada coordenada_actual;
    
    while((!se_encontro_edificio) && (i < cant_edificios)){
        coordenada_actual = edificios[i].obtener_coordenada();
        
        if((coordenada_actual.coordenada_x() == coordenada.coordenada_x()) &&
            (coordenada_actual.coordenada_y() == coordenada.coordenada_y())){
            se_encontro_edificio = VERDADERO;
            edificio = edificios[i];
        }
        i++;
    }
    return se_encontro_edificio;
}

void Ciudad::obtener_recursos_edificios(Inventario &inventario){

    int madera_obtenida = 0;
    int piedra_obtenida = 0;
    int metal_obtenido = 0;
    int contador_minas = 0; 
    int contador_aserraderos = 0; 
    int contador_fabricas = 0;

    for(int i = 0; i < cant_edificios; i++){
        if(edificios[i].obtener_nombre() == ASERRADERO){
            madera_obtenida += edificios[i].devolver_recursos_edificios().devolver_cantidad();
            contador_aserraderos ++;
        }
        else if(edificios[i].obtener_nombre() == MINA){
            piedra_obtenida += edificios[i].devolver_recursos_edificios().devolver_cantidad();
            contador_minas ++;
        }
        else if(edificios[i].obtener_nombre() == FABRICA){
            metal_obtenido += edificios[i].devolver_recursos_edificios().devolver_cantidad();
            contador_fabricas ++;
        }
    }

    mostrar_recursos_generados(piedra_obtenida, madera_obtenida, metal_obtenido, contador_aserraderos, contador_minas, contador_fabricas);


    for(int i = 0; i < inventario.devolver_cantidad_tipo_materiales(); i++){
        if(inventario.devolver_materiales(i).devolver_tipo() == MADERA){
            inventario.agregar_cantidad_material(MADERA, madera_obtenida);
        }
        if(inventario.devolver_materiales(i).devolver_tipo() == PIEDRA){
            inventario.agregar_cantidad_material(PIEDRA, piedra_obtenida);
        }
        if(inventario.devolver_materiales(i).devolver_tipo() == METAL){
            inventario.agregar_cantidad_material(METAL, metal_obtenido);
        }
    }
}

void Ciudad::mostrar_recursos_generados(int piedra_obtenida, int madera_obtenida, int metal_obtenido, int contador_aserraderos, int contador_minas, int contador_fabricas){

    cout << TXT_LIGHT_PURPLE_135 << endl;
    cout << "Informacion de la recoleccion de materiales: " << endl;
    cout << endl;
    cout << "Los aserradeors producen 25 de madera cada uno, actualmente hay " << contador_aserraderos << " aserradero/aserraderos." << endl;
    cout << "Las minas producen 15 de piedra cada una, actualmente hay " << contador_minas << " mina/minas." << endl;
    cout << "Las fabricas producen 40 de metal cada una, actualmente hay " << contador_fabricas << " fabrica/fabricas." << endl;
    cout << endl;
    if((madera_obtenida + piedra_obtenida + metal_obtenido) == 0){
        cout << "No hay edificios que generen materiales." << endl;
        cout << endl;
    }
    if(madera_obtenida != 0){
        cout << "Se acaba de agregar " << madera_obtenida << " de madera a su inventario." << endl;
        cout << endl;
    }
    if(piedra_obtenida != 0){
       
       cout << "Se acaba de agregar " << piedra_obtenida << " de piedra a su invnetario." << endl;
       cout << endl;
    }
    if(metal_obtenido != 0){
        
        cout << "Se acaba de agregar " << metal_obtenido << " de metal a su inventario." << endl;
        cout << endl;
    }

}



bool Ciudad::edificio_esta_incluido(string * edificios, int tope_edificios, string edificio_a_incluir){
   
    bool edificio_esta_incluido = FALSO;
    for(int i = 0; i < tope_edificios; i++){
        if(edificio_a_incluir == edificios[i]){
            edificio_esta_incluido = VERDADERO;
        }
    }
    
    return edificio_esta_incluido;
}

string * Ciudad::cargar_tipos_edificios_construidos(Edificio * &edificios, int cant_edificios, int &cant_tipos_construidos){
    string * tipos_edificios_construidos = nullptr;
    cant_tipos_construidos = 0;
    Vector< string > vector_tipos_edificios_construidos;

    for(int i = 0; i < cant_edificios; i++){
        if(!edificio_esta_incluido( tipos_edificios_construidos, cant_tipos_construidos, edificios[i].obtener_nombre())){
            vector_tipos_edificios_construidos.agregar_elemento( tipos_edificios_construidos, cant_tipos_construidos, edificios[i].obtener_nombre());
        }
    }
    return tipos_edificios_construidos;
}

int Ciudad::cargar_coordenadas(Edificio * edificios, int tope_edificios, string edificio_de_interes, Coordenada * &coordenadas, int &tope_coordenadas){
    
    int contador = 0;
    Coordenada coordenada_actual;
    Vector< Coordenada > vector_coordenadas;

    for(int i = 0; i < tope_edificios; i++){
        if(edificios[i].obtener_nombre() == edificio_de_interes){
            coordenada_actual = edificios[i].obtener_coordenada();
            vector_coordenadas.agregar_elemento( coordenadas, tope_coordenadas, coordenada_actual );
            contador++;
        }
    }
    return contador;
}

void Ciudad::imprimir_coordenadas(Coordenada * coordenadas, int tope_coordenadas){
    int x;
    int y;
    for( int i = 0; i < tope_coordenadas; i++){
        x = (int) coordenadas[i].coordenada_x();
        y = (int) coordenadas[i].coordenada_y();
        cout << "(" << x << ", " << y << ") ";
    }
    cout << endl;
}

void Ciudad::listar_edificios_construidos(){
    
    cout << TXT_LIGHT_PURPLE_135 << endl;
    Edificio * edificios = nullptr;
    int cant_edificios = 0;
    int cant_tipos_construidos = 0;

    Coordenada * coordenadas = nullptr;
    int tope_coordenadas = 0;

    obtener_ciudad_edificios(edificios, cant_edificios);
    string * tipos_edificios_construidos = cargar_tipos_edificios_construidos(edificios, cant_edificios, cant_tipos_construidos);

    
    if(cant_tipos_construidos == 0){
        cout << "No hay edificios construidos." << endl;
        cout << endl;
    }
    else{
        cout << "Listando edificios construidos:" << endl;
        cout << endl;
        for( int i = 0; i < cant_tipos_construidos; i++ ){
            tope_coordenadas = 0;
            cout << "       " << TXT_LIGHT_PURPLE_135 << TXT_UNDERLINE << tipos_edificios_construidos[i] << endl;
            cout << END_COLOR << "           " << TXT_LIGHT_PURPLE_135 << TXT_UNDERLINE << "Construidos:" << END_COLOR;
            cout << TXT_LIGHT_PURPLE_135;
            cout << " " << cargar_coordenadas( edificios, devolver_cant_edificios(), tipos_edificios_construidos[i], coordenadas, tope_coordenadas) << endl;
            cout << endl;
            cout << "           Posicion/es: ";
            imprimir_coordenadas(coordenadas, tope_coordenadas );
            cout << endl;
        }
    }
    
    delete [] coordenadas;
    coordenadas = nullptr;
    delete [] tipos_edificios_construidos;
    tipos_edificios_construidos = nullptr;
}

void Ciudad::limpiar_edificios(){
    
    delete[] edificios;
    edificios = nullptr;
}
