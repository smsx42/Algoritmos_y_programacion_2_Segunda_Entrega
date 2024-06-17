#ifndef CONSTANTE_H_INCLUDED
#define CONSTANTE_H_INCLUDED
#include <string>

const int OPCION_1 = 1;
const int OPCION_2 = 2;
const int OPCION_3 = 3;
const int OPCION_4 = 4;
const int OPCION_5 = 5;
const int OPCION_6 = 6;
const int OPCION_7 = 7;
const int OPCION_8 = 8;
const int OPCION_9 = 9;
const int OPCION_10 = 10;

const int ERROR = -1;
const int FUNCIONO = 0;

const bool VERDADERO = true;
const bool FALSO = false;

const std::string PATH_MATERIALES = "materiales.txt";
const std::string PATH_EDIFICIOS = "edificios.txt";
const std::string PATH_UBICACIONES = "ubicaciones.txt";
const std::string PATH_MAPA = "mapa.txt";

const std::string PIEDRA = "piedra";
const std::string MADERA = "madera";
const std::string METAL = "metal";

const std::string ASERRADERO = "aserradero";
const std::string MINA = "mina";
const std::string FABRICA = "fabrica";
const std::string PLANTA_ELECTRICA = "planta_electrica";
const std::string OBELISCO = "obelisco";
const std::string ESCUELA = "escuela";


const int NULO = 0;
const int NO_EXISTE = -1;
const std::string CADENA_VACIA = "-";


const char LAGO = 'L';
const char TERRENO = 'T';
const char CAMINO = 'C';

const std::string IMAGEN_ESCUELA = "\U0001f3eb";
const std::string IMAGEN_FABRICA = "\U0001f3ed";
const std::string IMAGEN_MINA =	"\u26CF";
const std::string IMAGEN_PLANTA_ELECTRICA =  "\U0001f4a1";
const std::string IMAGEN_OBELISCO = "\U0001f5fc";
const std::string IMAGEN_ASERRADERO = "\U0001f3e1";

const std::string IMAGEN_PIEDRA = "\U0001f9f1";
const std::string IMAGEN_MADERA = "\U0001f332";
const std::string IMAGEN_METAL = "\u2699";

const std::string IMAGEN_CAMINO = "\U0001f6e3";
const std::string IMAGEN_CONSTRUIBLE = "\U0001f528";
const std::string IMAGEN_LAGO ="\U0001f4a7";

#define TXT_LIGHT_BLUE_33 "\033[38;5;33m"
#define TXT_LIGHT_PURPLE_135 "\033[38;5;135m"
#define TXT_UNDERLINE "\033[4m"  
#define END_COLOR "\033[0m"
#define RESET "\033[0m"

const char CARACTER_ASERRADERO = 'a';
const char CARACTER_MINA = 'm';
const char CARACTER_FABRICA = 'f';
const char CARACTER_PLANTA_ELECTRICA = 'p';
const char CARACTER_OBELISCO = 'o';
const char CARACTER_ESCUELA = 'e';

const char CARACTER_PIEDRA = 'S';
const char CARACTER_MADERA = 'W';
const char CARACTER_METAL = 'I';


#endif // CONSTANTE_H_INCLUDED