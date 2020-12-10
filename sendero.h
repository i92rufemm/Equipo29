#ifndef _SENDERO.h_
#define _SENDERO.h_
#include <iostream>
#include <string>
using namespace std;
class Sendero
{
private:
    //datos privados
    string codigo_;
    string dificultad_;
    string disponibilidad_;
    string longitud_;
    Parque parque_;
public:
    Sendero(string codigo,Parque parque,string dificultad = "", string disponibilidad = "",string longitud);
    inline string getCodigo()const{return codigo_;}
    inline string getDificultad()const{return dificultad_;}
    inline string getLongitud()const{return longitud_;}
    inline string getDisponibilidad()const{return disponibilidad_;}
    inline Parque getParque()const{return parque_;}
    inline void setCodigo(string codigo){codigo_ = codigo;}
    inline void setDificultad(string dificultad){dificultad_ = dificultad;}
    inline void setLongitud(string longitud){longitud_ = longitud;}
    inline void setDisponibilidad(string disponibilidad){disponibilidad_ = disponibilidad;}
    inline void setParque(Parque parque){parque_ = parque;}
};




#endif
