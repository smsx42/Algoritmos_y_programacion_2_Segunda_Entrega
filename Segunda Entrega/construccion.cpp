#include "construccion.h"
#include <fstream>
#include "constante.h"


using namespace std;

void generar_menu(){
    
    cout << TXT_LIGHT_BLUE_33 << endl;
    cout << "╔════════════════════════════════════════════════════════════════════════╗" << endl;
    cout << "║ Gestor de construccion de Andypolis, seleccione alguna de las opciones:║ " << endl;
    cout << "╚════════════════════════════════════════════════════════════════════════╝" << endl;

    cout << "\t" << "╔════════════════════════════════════════╗" << endl;
    cout << "\t" << "║ 1)- Construir edificio por nombre.     ║" << endl;
    cout << "\t" << "║                                        ║" << endl;
    cout << "\t" << "║ 2)- Listar edificios construidos.      ║" << endl;
    cout << "\t" << "║                                        ║" << endl;
    cout << "\t" << "║ 3)- Listar todos los edificios.        ║" << endl;
    cout << "\t" << "║                                        ║" << endl;
    cout << "\t" << "║ 4)- Demoler edificio por coordenada.   ║" << endl;
    cout << "\t" << "║                                        ║" << endl;
    cout << "\t" << "║ 5)- Mostrar mapa.                      ║" << endl;
    cout << "\t" << "║                                        ║" << endl;
    cout << "\t" << "║ 6)- Consultar coordenada.              ║" << endl;
    cout << "\t" << "║                                        ║" << endl;
    cout << "\t" << "║ 7)- Mostrar inventario.                ║" << endl;
    cout << "\t" << "║                                        ║" << endl;
    cout << "\t" << "║ 8)- Recolectar recursos producidos.    ║" << endl;
    cout << "\t" << "║                                        ║" << endl;
    cout << "\t" << "║ 9)- Lluvia de recursos.                ║" << endl;
    cout << "\t" << "║                                        ║" << endl;
    cout << "\t" << "║ 10)- Guardar y salir.                  ║" << endl;
    cout << "\t" << "╚════════════════════════════════════════╝" << endl;
}

void volver_menu(){
    
    cout << TXT_LIGHT_BLUE_33 << endl;
    cout << endl;
    cout << "        " << "╔══════════════════════════════╗" << endl;
    cout << "        " << "║Oprima 0 para volver al menu: ║" << endl;
    cout << "        " << "╚══════════════════════════════╝" << endl;

    string numero = "1";
    cin >> numero;

    while (numero != "0")
    {
        cout << TXT_LIGHT_BLUE_33 << endl;
        cout << "            " << "╔══════════════════════════╗" << endl;
        cout << "            " << "║ ----CARACTER INVALIDO----║" << endl;
        cout << "            " << "╚══════════════════════════╝" << endl;

        cout << endl;
        cout << "          " << "╔══════════════════════════════╗" << endl;
        cout << "          " << "║Oprima 0 para volver al menu: ║" << endl;
        cout << "          " << "╚══════════════════════════════╝" << endl;

        cin >> numero;
    }
}

void mostrar_detalles(int opcion){

    system(CLR_SCREEN);
    cout << TXT_LIGHT_BLUE_33;
    if (opcion == OPCION_1){

        cout << "          " << "╔═══════════════════════════╗" << endl;
        cout << "          " << "║ Construccion de edificios ║" << endl;
        cout << "          " << "╚═══════════════════════════╝" << endl;
        cout << endl; 
    }
    else if (opcion == OPCION_2){

        cout << "          " << "╔═══════════════════════╗" << endl;
        cout << "          " << "║ Edificios construidos ║" << endl;
        cout << "          " << "╚═══════════════════════╝" << endl;
        cout << endl; 
    }
    else if (opcion == OPCION_3){

        cout << "         " << "╔═══════════════════════════════════╗" << endl;
        cout << "         " << "║ Lista de general de los edificios ║  " << endl;
        cout << "         " << "╚═══════════════════════════════════╝" << endl;
        cout << endl;
    }
    else if (opcion == OPCION_4){

        cout << "          " << "╔════════════════════════╗" << endl;
        cout << "          " << "║ Demolicion de edificio ║ " << endl;
        cout << "          " << "╚════════════════════════╝" << endl;
        cout << endl;
  
    }
    else if (opcion == OPCION_5){

        cout << "            " << "╔═══════════════════╗" << endl;
        cout << "            " << "║ Mapa de la ciudad ║" << endl;
        cout << "            " << "╚═══════════════════╝" << endl;
        cout << endl; 
    }
    else if (opcion == OPCION_6){

        cout << "            " << "╔═════════════════════════╗" << endl;
        cout << "            " << "║ Consulta de coordenadas ║" << endl;
        cout << "            " << "╚═════════════════════════╝" << endl;
        cout << endl;   
    }
    else if (opcion == OPCION_7){

        cout << "            " << "╔═════════════════════╗" << endl;
        cout << "            " << "║ Lista de materiales ║" << endl;
        cout << "            " << "╚═════════════════════╝" << endl;
        cout << endl;
    }
    else if (opcion == OPCION_7){

        cout << "            " << "╔════════════╗" << endl;
        cout << "            " << "║ Inventario ║" << endl;
        cout << "            " << "╚════════════╝" << endl;
        cout << endl;
    }
    else if (opcion == OPCION_8){

        cout << "            " << "╔═════════════════════════╗" << endl;
        cout << "            " << "║ Recoleccion de recursos ║" << endl;
        cout << "            " << "╚═════════════════════════╝" << endl;
        cout << endl;
    }
    else if (opcion == OPCION_9){

        cout << "            " << "╔═══════════════════╗" << endl;
        cout << "            " << "║ Lluvia de recurso ║" << endl;
        cout << "            " << "╚═══════════════════╝" << endl;
        cout << endl;
    }
    else if (opcion == OPCION_10){

        cout << "            " << "╔═══════════════════════════╗" << endl;
        cout << "            " << "║ Se han guardado los datos ║" << endl;
        cout << "            " << "╚═══════════════════════════╝" << endl;
        cout << endl;
    }

}

void cargar_inventario(Inventario &inventario){
    
    string nombre;
    int cantidad;
    ifstream archivo_materiales(PATH_MATERIALES);
    
    if(!archivo_materiales.fail()){
        while((archivo_materiales >> nombre)){
            (archivo_materiales >> cantidad);
            inventario.agregar_material(nombre, cantidad);
            inventario.crear_nuevo_vector();
        }
        archivo_materiales.close();
    }
    else{
        cout << "----ERROR AL LEER EL ARCHIVO " <<  PATH_MATERIALES << endl;
    }
}

void cargar_tipo_edificios(Ciudad &ciudad){
    ifstream archivo_edificios(PATH_EDIFICIOS);

    if(!archivo_edificios.fail()){
        string nombre;
        int cantidad_piedra, cantidad_madera, cantidad_metal;
        int cant_maxima;

        while((archivo_edificios >> nombre)){
            (archivo_edificios >> cantidad_piedra);
            (archivo_edificios >> cantidad_madera);
            (archivo_edificios >> cantidad_metal);
            (archivo_edificios >> cant_maxima);

            ciudad.agregar_tipo_edificio(nombre, cant_maxima, cantidad_piedra, cantidad_madera, cantidad_metal);
        }
        archivo_edificios.close();
    }
    else{
        cout << "----ERROR AL LEER EL ARCHIVO " <<  PATH_EDIFICIOS << endl;
    }
}

void cargar_edificios(Ciudad &ciudad){
    ifstream archivo_ubicaciones(PATH_UBICACIONES);

    if(!archivo_ubicaciones.fail()){
        string nombre_edificio, parentesis;
        string coordenada_1, coordenada_2;
        Edificio nuevo_edificio;
        Coordenada nueva_coordenada;
        while(getline(archivo_ubicaciones, nombre_edificio, ' ') ){
            getline(archivo_ubicaciones, parentesis, '(');
            getline(archivo_ubicaciones, coordenada_1, ',');
            getline(archivo_ubicaciones, coordenada_2, ')');
            getline(archivo_ubicaciones, parentesis, '\n');
            nueva_coordenada.cargar_coordenada( stoi(coordenada_1), stoi(coordenada_2) );
            nuevo_edificio.modificar_edificio( nombre_edificio, nueva_coordenada );
            ciudad.agregar_edificio( nuevo_edificio );
        }
        archivo_ubicaciones.close();
    }
    else{
        cout << "----ERROR AL LEER EL ARCHIVO " <<  PATH_UBICACIONES << endl;
    }
}

void cargar_ciudad(Ciudad &ciudad){
    
    cargar_tipo_edificios(ciudad);
    cargar_edificios(ciudad);
}

int cargar_mapa(Mapa &mapa, Ciudad ciudad ){
    
    ifstream archivo_mapa(PATH_MAPA);
    if(!archivo_mapa){
        cout << "----ERROR AL LEER EL ARCHIVO " <<  PATH_MAPA << endl;
        return ERROR;
    }
    int filas, columnas;
    char caracter;
    Coordenada coordenada_actual;

    archivo_mapa >> filas >> columnas;
    mapa.inicializar_mapa( filas, columnas );

    for( int i = 0; i < filas; i++ ){
        for( int j = 0; j < columnas; j++ ){
            archivo_mapa >> caracter;
            coordenada_actual.cargar_coordenada( i, j);
            mapa.cargar_casillero_mapa( caracter, coordenada_actual );
        }
    }
    mapa.cargar_edificios_mapa( ciudad );
    archivo_mapa.close();
    return FUNCIONO;
}

void modificar_archivo_materiales(Inventario inventario){

    ofstream archivo_materiales(PATH_MATERIALES);

    if(!archivo_materiales.fail()){
        for(int i = 0; i < inventario.devolver_cantidad_tipo_materiales(); i++){
            archivo_materiales << inventario.devolver_materiales(i).devolver_tipo() << " ";
            archivo_materiales << inventario.devolver_materiales(i).devolver_cantidad();
            archivo_materiales << endl;
        }
    }
    else{
        cout << "----ERROR AL ESCRIBIR EL ARCHIVO " <<  PATH_MATERIALES << endl;
    }

    archivo_materiales.close();
}

void modificar_archivo_ubicaciones(Ciudad ciudad){

    ofstream archivo_ubicaciones(PATH_UBICACIONES);

    if(!archivo_ubicaciones.fail()){

        for(int i = 0; i < ciudad.devolver_cant_edificios(); i++){
            archivo_ubicaciones << ciudad.devolver_edificio(i).obtener_nombre() << " (";
            archivo_ubicaciones << ciudad.devolver_edificio(i).obtener_coordenada().coordenada_x() << ", ";
            archivo_ubicaciones << ciudad.devolver_edificio(i).obtener_coordenada().coordenada_y() << ")";
            archivo_ubicaciones << endl;
        }

    }
    else{
        cout << "----ERROR AL ESCRIBIR EL ARCHIVO " <<  PATH_UBICACIONES << endl;
    }

    archivo_ubicaciones.close();
}


void listar_tipo_edificios(Ciudad ciudad){
    Tipo_edificio * tipo_edificios;
    int cant_tipo_edificios;
    ciudad.obtener_ciudad_tipo_edificios(tipo_edificios, cant_tipo_edificios);
    for( int i = 0; i < cant_tipo_edificios; i++ ){
        cout << "       *" << tipo_edificios[i].devolver_nombre_tipo_edificio();
    }
    cout << endl << endl;
}

string consultar_nombre_edificio(Ciudad ciudad){
    string nombre_edificio;
    cout << TXT_LIGHT_PURPLE_135 << endl;
    cout << "   " << "Que edificio desea construir?" << endl << endl;
    cout << "   Edificios disponibles:" << endl;
    cout << endl;
    listar_tipo_edificios(ciudad);
    cout << "   ";
    cin >> nombre_edificio;
    while( !ciudad.existe_tipo_edificio(nombre_edificio) ){
        mostrar_detalles(OPCION_1);
        cout << TXT_LIGHT_PURPLE_135;
        cout << endl << "   No existe el edificio, vuelva a intentar." << endl << endl;
        cout << "   Edificios disponibles:" << endl;
        listar_tipo_edificios(ciudad);
        cout << "   ";
        cin >> nombre_edificio;
        cout << END_COLOR;
    }


    return nombre_edificio;
}

bool hay_materiales_suficientes(string edificio_a_construir, Ciudad ciudad, Inventario inventario){
    
    bool hay_materiales = VERDADERO;

    if((inventario.cantidad_material(PIEDRA) < ciudad.costo_material_tipo_edificio( edificio_a_construir, PIEDRA)) ||
        (inventario.cantidad_material(MADERA) < ciudad.costo_material_tipo_edificio( edificio_a_construir, MADERA)) ||
        (inventario.cantidad_material(METAL) < ciudad.costo_material_tipo_edificio( edificio_a_construir, METAL))){

        hay_materiales = FALSO;
    }

    return hay_materiales;
}

Coordenada usuario_ingresa_coordenada(Mapa mapa){
    
    cout << TXT_LIGHT_PURPLE_135;
    int x = -1, y = -1;
    Coordenada coordenada;
    cout << endl;
    cout << "   Ingrese coordenadas: " << endl;
    cout << endl;
    cout << "       Fila: ";
    cin >> x;
    cout << endl << "       Columna: ";
    cin >> y;
    cout << endl;
    while( ( x < 0 ) || ( x >= mapa.obtener_cantidad_filas() ) ||
           ( y < 0 ) || ( y >= mapa.obtener_cantidad_columnas() )){
        system(CLR_SCREEN);
        cout << TXT_LIGHT_PURPLE_135;
        cout << "   Coordenada invalida intente de nuevo: " << endl;
        cout << endl;
        cout << endl;
        cout << TXT_LIGHT_PURPLE_135 << "       Fila: ";
        cin >> x;
        cout << TXT_LIGHT_PURPLE_135 << "       Columna: ";
        cin >> y;
        cout << endl;
    }
    coordenada.cargar_coordenada(x, y);
    return coordenada;
}

void construir_edificio(Ciudad &ciudad, Mapa &mapa, Inventario &inventario){
    
    mostrar_detalles(OPCION_1);
    
    cout << TXT_LIGHT_PURPLE_135 << endl;
    Edificio edificio_a_construir;
    string nombre_edificio = consultar_nombre_edificio(ciudad);
    Coordenada coordenada;
    if(!hay_materiales_suficientes( nombre_edificio, ciudad, inventario)){
        mostrar_detalles(OPCION_1);
        cout << "   No hay materiales suficientes para construir el edificio." << endl;
    }
    else if( !ciudad.hay_capacidad_edifcio( nombre_edificio)){
        mostrar_detalles(OPCION_1);
        cout << TXT_LIGHT_PURPLE_135 << "   Ya se construyo la cantidad maxima de " << nombre_edificio << "s." << END_COLOR << endl;
    }
    else{
        mostrar_detalles(OPCION_1);
        mapa.mostrar_mapa();
        coordenada = usuario_ingresa_coordenada(mapa);
        edificio_a_construir.modificar_edificio( nombre_edificio, coordenada);
        if(mapa.construir_edificio(edificio_a_construir) ){
            cout << "Cuenta con los materiales necesarios, confirme si quiere constuir el edificio: " << endl;
            cout << "           " << "╔═══════════════╗" << endl;
            cout << "           " << "║----Si - NO----║" << endl;
            cout << "           " << "╚═══════════════╝" << endl;
            cout << endl;
            string decision;
            std::cin >> decision;
            if(decision == "si" || decision == "Si"){
                inventario.descontar_material(PIEDRA, ciudad.costo_material_tipo_edificio(nombre_edificio, PIEDRA));
                inventario.descontar_material(MADERA, ciudad.costo_material_tipo_edificio(nombre_edificio, MADERA));
                inventario.descontar_material(METAL, ciudad.costo_material_tipo_edificio(nombre_edificio, METAL));
                ciudad.agregar_edificio(edificio_a_construir);
                mostrar_detalles(OPCION_1);
                cout << "Se construyo un edificio del tipo " << nombre_edificio << " en las coordenadas (" << coordenada.coordenada_x() << ", " << coordenada.coordenada_y() << ")"<< endl;
            }
            else if(decision == "no" || decision == "No"){
                cout << "No se construyo el edificio." << endl;
            }
        }
        
    }

}

void listar_edificios(Ciudad ciudad){
    
    mostrar_detalles(OPCION_2);
    ciudad.mostrar_tipo_edificios();
}

void listar_edificios_construidos(Ciudad ciudad){
    
    mostrar_detalles(OPCION_3);
    ciudad.listar_edificios_construidos();
}

void demoler_edificio(Ciudad &ciudad, Mapa &mapa, Inventario &inventario){
    
    mostrar_detalles(OPCION_4);
    cout << TXT_LIGHT_PURPLE_135 << endl;
    mapa.mostrar_mapa();
    cout << TXT_LIGHT_PURPLE_135 << endl;
    cout << endl << "Ingrese coordenadas del edificio que desea demoler" << endl << endl;
    Coordenada coordenada = usuario_ingresa_coordenada(mapa);
    Edificio edificio_a_demoler;
    
    if(ciudad.buscar_edificio_por_coordenada(coordenada, edificio_a_demoler)){
        mostrar_detalles(OPCION_4);
        cout << "Si elimina el edificio, se le daran la mitad de los materiales; indique si desea continuar: " << endl;
        cout << "           " << "╔═══════════════╗" << endl;
        cout << "           " << "║----Si - NO----║" << endl;
        cout << "           " << "╚═══════════════╝" << endl;
        cout << endl;
        string decision;
        std::cin >> decision;
        if(decision == "si" || decision == "Si"){
            mapa.demoler_edificio( edificio_a_demoler );
            inventario.agregar_cantidad_material(PIEDRA, ciudad.costo_material_tipo_edificio(edificio_a_demoler.obtener_nombre(), PIEDRA)/2);
            inventario.agregar_cantidad_material(MADERA, ciudad.costo_material_tipo_edificio(edificio_a_demoler.obtener_nombre(), MADERA)/2);
            inventario.agregar_cantidad_material(METAL, ciudad.costo_material_tipo_edificio(edificio_a_demoler.obtener_nombre(), METAL)/2);
            ciudad.eliminar_edificio(edificio_a_demoler);
        }
        else if(decision == "no" || decision == "No"){
            cout << "No se ah demolido el edificio." << endl;
        }
    }
    else cout << endl << "      No existe un edificio en esa coordenada." << endl;

}

void mostrar_mapa(Mapa mapa){
    
    mostrar_detalles(OPCION_5);
    mapa.mostrar_mapa();
}

void consultar_coordenadas(Mapa mapa){
    
    mostrar_detalles(OPCION_6);
    mapa.consultar_casillero( usuario_ingresa_coordenada(mapa));
}

void listar_materiales(Inventario inventario){
    
    mostrar_detalles(OPCION_7);
    inventario.mostrar_inventario();
}

void recolectar_recursos(Ciudad ciudad, Inventario &inventario){

    mostrar_detalles(OPCION_8);
    ciudad.obtener_recursos_edificios(inventario);

}

void lluvia_recursos(Mapa mapa, int &contador_casilleros_transitables){

    mostrar_detalles(OPCION_9);
    mapa.generar_materiales(contador_casilleros_transitables);

}


void generar_opciones(Inventario &inventario, Ciudad &ciudad, Mapa &mapa ){
    
    int opcion = 0;
    int contador_casilleros_transitables = 0;

    while (opcion != OPCION_10){
        system(CLR_SCREEN);
        generar_menu();
        cin >> opcion;
        system(CLR_SCREEN);
        cout << endl;
        switch( opcion ){
            case OPCION_1:
                construir_edificio(ciudad, mapa, inventario);
                break;
            case OPCION_2:
                listar_edificios_construidos(ciudad);
                break;
            case OPCION_3:
                listar_edificios(ciudad);
                break;
            case OPCION_4:
                demoler_edificio(ciudad, mapa, inventario);
                break;
            case OPCION_5:
                mostrar_mapa(mapa);
                break;
            case OPCION_6:
                consultar_coordenadas(mapa);
                break;
            case OPCION_7:
                listar_materiales(inventario);
                break;
            case OPCION_8:
                recolectar_recursos(ciudad, inventario);
                break;
            case OPCION_9:
                lluvia_recursos(mapa, contador_casilleros_transitables);
                break;
            case OPCION_10:
                break;
            default:
                cout << TXT_LIGHT_BLUE_33 << endl;
                cout << "             "     << "╔══════════════════════════╗" << endl;
                cout << "             "     << "║ ----CARACTER INVALIDO----║" << endl;
                cout << "             "     << "╚══════════════════════════╝" << endl;
        }
        if(opcion != OPCION_10){
            volver_menu();
        }
    }
}

void guardar_cambios(Ciudad ciudad, Inventario inventario){

    modificar_archivo_materiales(inventario);
    modificar_archivo_ubicaciones(ciudad);
    cout << TXT_LIGHT_BLUE_33 << "Se han guardado los datos." << endl;
}

void limpiar_programa(Ciudad ciudad, Inventario inventario, Mapa mapa){
    inventario.limpiar_inventario();
    ciudad.limpiar_tipo_edificio();
    ciudad.limpiar_edificios();
    mapa.limpiar_mapa();
}

void empezar_programa(){
   
    Inventario inventario;
    Ciudad ciudad;
    Mapa mapa;

    cargar_inventario(inventario);
    cargar_ciudad(ciudad);
    cargar_mapa(mapa, ciudad);

    generar_opciones(inventario, ciudad, mapa);

    guardar_cambios(ciudad, inventario);

    limpiar_programa(ciudad, inventario, mapa);
    
}
