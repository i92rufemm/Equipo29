#include "sendero.h"

using namespace std;
//para poder hacer el commit
Sendero::Sendero(string codigo,string dificultad,string disponibilidad,float longitud)
{
    codigo_ = codigo;
    //parque_ = parque;
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