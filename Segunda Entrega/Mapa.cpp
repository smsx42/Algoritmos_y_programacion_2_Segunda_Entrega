#include "Mapa.h"
#include "constante.h"

using namespace std;

Mapa::Mapa(){
    
    filas = NO_EXISTE;
    columnas = NO_EXISTE;
    mapa = nullptr;
    cant_casilleros_transitables = 0;
}

void Mapa::inicializar_mapa(int filas, int columnas) {
    
    this-> filas = filas;
    this-> columnas = columnas;
    mapa = new Casillero**[filas];
    
    for( int i = 0; i < filas; i++ ){
        mapa[i] = new Casillero*[columnas];
    }

    for( int i = 0; i < filas; i ++ ){
        for( int j = 0; j < columnas; j++ ){
            mapa[i][j] = nullptr;
        }
    }
}

void Mapa::cargar_casillero_mapa(char tipo_terreno, Coordenada coordenada){
    
    if(tipo_terreno == LAGO){
        mapa[coordenada.coordenada_x()][coordenada.coordenada_y()] = new Casillero_inaccesible(coordenada);
    }
    else if(tipo_terreno == TERRENO){
        mapa[coordenada.coordenada_x()][coordenada.coordenada_y()] = new Casillero_construible(coordenada);
    }
    else if(tipo_terreno == CAMINO){
        mapa[coordenada.coordenada_x()][coordenada.coordenada_y()] = new Casillero_transitable(coordenada);
        cant_casilleros_transitables ++;
    }
}

void Mapa::cargar_edificios_mapa(Ciudad ciudad){
    
    Edificio * edificios;
    int cantidad_edificios;
    ciudad.obtener_ciudad_edificios(edificios, cantidad_edificios);

    Coordenada coordenada;
    
    for(int i = 0; i < cantidad_edificios; i++){
        coordenada = edificios[i].obtener_coordenada();
        mapa[coordenada.coordenada_x()][coordenada.coordenada_y()]->construir_edificio(edificios[i]);
    }
}

void Mapa::mostrar_mapa(){
    
    
    cout <<  TXT_LIGHT_PURPLE_135 << endl;
    cout << "Representacion de los casilleros: " << endl;
    cout << "╔════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗" << endl;
    cout << "║ Casilleros generales: " << "Camino: " << IMAGEN_CAMINO << "  " << "Terreno: " << IMAGEN_CONSTRUIBLE << "  " << "Lago: " << IMAGEN_LAGO << "                                                         ║" << endl;
    cout << "║ Casilleros construibles: " << "Aserradero: " << IMAGEN_ASERRADERO << "  " << "Mina: " << IMAGEN_MINA << "  " << "Fabrica: " << IMAGEN_FABRICA << "  " << "Planta electica: " << IMAGEN_PLANTA_ELECTRICA << "  " << "Obelisco: " << IMAGEN_OBELISCO << "  " << "Escuela: " << IMAGEN_ESCUELA << "  ║" << endl;
    cout << "║ Casilleros transitable: " << "Piedra: " << IMAGEN_PIEDRA << "  " << "Madera: " << IMAGEN_MADERA << "  " << "Metal: " << IMAGEN_METAL << "                                                       ║" << endl;
    cout << "╚════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝" << endl;
    cout << endl;
    cout << endl;
    
    cout << "                           ------MAPA DE TERRENO------" << std::endl;
    cout << endl;

    for( int i = 0; i < filas; i ++ ){
        cout << "              ";
        
        for( int j = 0; j < columnas; j++ ){
            mapa[i][j]->imprimir_representacion();
            cout << " ";
        }
        cout << endl;
    }
    cout << RESET;


}

void Mapa::consultar_casillero(Coordenada coordenada){
    
    mapa[coordenada.coordenada_x()][coordenada.coordenada_y()]->mostrar_informacion();
}

int Mapa::obtener_cantidad_filas(){
    
    return filas;
}

int Mapa::obtener_cantidad_columnas(){
    
    return columnas;
}

bool Mapa::construir_edificio(Edificio edificio){
    
    Coordenada coordenada = edificio.obtener_coordenada();
    return mapa[coordenada.coordenada_x()][coordenada.coordenada_y()]->construir_edificio(edificio);
}

bool Mapa::demoler_edificio(Edificio edificio){
    
    Coordenada coordenada = edificio.obtener_coordenada();
    return mapa[coordenada.coordenada_x()][coordenada.coordenada_y()]->demoler_edificio();
}

void Mapa::limpiar_mapa(){
    
    for(int i = 0; i < filas; i++){
        
        for(int j = 0; j < columnas; j++){
            delete mapa[i][j];
        }
    }

    for(int i = 0; i < filas; i++){
        
        delete[] mapa[i];
        mapa[i] = nullptr;
    }

    delete[] mapa;
    mapa = nullptr;
}

void Mapa::realizar_iteraciones_materiales(int fila_aleatoria, int columna_aleatoria,int cant_aleatoria, int elemento_aleatorio, Material materiales[CANT_MAX_MATERIALES], int &contador_casilleros_transitables){

    int anulador = NULO;
    
    if(cant_aleatoria != NULO && (cant_casilleros_transitables - contador_casilleros_transitables) >= cant_aleatoria){
        anulador ++;
        cout << "Se genero " << cant_aleatoria << " de " << materiales[elemento_aleatorio].devolver_tipo() << " en: " << endl;
        cout << endl;
        contador_casilleros_transitables += cant_aleatoria;
        for(int i = 0; i < cant_aleatoria; i++){
            mapa[fila_aleatoria][columna_aleatoria]->agregar_material(materiales[elemento_aleatorio]);
            cout << "--- (" << fila_aleatoria << ", " << columna_aleatoria << ")" << endl;
            cout << endl;
            fila_aleatoria = (rand()% filas);
            columna_aleatoria = (rand()% columnas);                
            
            while(mapa[fila_aleatoria][columna_aleatoria]->obtener_representacion() != CAMINO && cant_casilleros_transitables != contador_casilleros_transitables){
                fila_aleatoria = (rand()% filas);
                columna_aleatoria = (rand()% columnas);
            }
        }
        if(contador_casilleros_transitables != cant_casilleros_transitables){
            cout << "Ahora quedan " << cant_casilleros_transitables - contador_casilleros_transitables << " de casilleros en los que se pueden generar materiales." << endl;
            cout << endl;
        }
        
    }
    if(cant_aleatoria == NULO || anulador == NULO){
        cout << "No se genero ningun material." << endl;
    }
}

void Mapa::generar_materiales(int &contador_casilleros_transitables){
    
    Material materiales[3];
    materiales[0].obtener_materiales(PIEDRA, 1);
    materiales[1].obtener_materiales(MADERA, 1);
    materiales[2].obtener_materiales(METAL, 1);

    bool se_agrego = FALSO;
    int fila_aleatoria;
    int columna_aleatoria;
    int elemento_aleatorio;
    int cant_aleatoria;

    srand(static_cast<unsigned int>(time(NULL)));
    
    cout << TXT_LIGHT_PURPLE_135 << endl;
    cout << "Actualmente hay " << cant_casilleros_transitables << " casilleros transitables."<< endl;
    cout << endl;

    while(!se_agrego){
        
        fila_aleatoria = (rand()% filas);
        columna_aleatoria = (rand()% columnas);
        
        if(mapa[fila_aleatoria][columna_aleatoria]->obtener_representacion() == CAMINO){
            
            elemento_aleatorio = (rand()% 3);
            
            if(materiales[elemento_aleatorio].devolver_tipo() == PIEDRA){
                cant_aleatoria = (rand() % 1 + 1);
                realizar_iteraciones_materiales(fila_aleatoria, columna_aleatoria, cant_aleatoria, elemento_aleatorio, materiales, contador_casilleros_transitables);   
            }
            else if(materiales[elemento_aleatorio].devolver_tipo() == MADERA){
                cant_aleatoria = (rand()% 2);
                realizar_iteraciones_materiales(fila_aleatoria, columna_aleatoria, cant_aleatoria, elemento_aleatorio, materiales, contador_casilleros_transitables);
            }
            else if(materiales[elemento_aleatorio].devolver_tipo() == METAL){
                cant_aleatoria = (rand()% 3 + 2);
                realizar_iteraciones_materiales(fila_aleatoria, columna_aleatoria, cant_aleatoria, elemento_aleatorio, materiales, contador_casilleros_transitables);
            }
            se_agrego = VERDADERO;
            
        }
        if(contador_casilleros_transitables == cant_casilleros_transitables){
            cout << "Ya no quedan casilleros transitables para generar materiales, no se pueden generar mas materiales." << endl;
            se_agrego = VERDADERO;
        }
    }

}
