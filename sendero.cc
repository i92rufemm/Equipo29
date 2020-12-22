#include "sendero.h"

using namespace std;

Sendero::Sendero(string codigo,string dificultad,string disponibilidad,float longitud)
{
    codigo_ = codigo;
    dificultad_ = dificultad;
    disponibilidad_ = disponibilidad;
    longitud_ = longitud;
}
bool Sendero::setLongitud(float longitud){
    if(longitud >= 0){
        longitud_ = longitud;
        return true;
    }
    return false;
}