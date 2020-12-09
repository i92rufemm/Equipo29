#include "sendero.h"

using namespace std;

Sendero::Sendero(string codigo,Parque parque,string dificultad,string disponibilidad,string longitud)
{
    setCodigo(codigo);
    setParque(parque);
    dificultad_ = dificultad;
    disponibilidad_ = disponibilidad;
    longitud_ = longitud;
}
