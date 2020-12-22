#ifndef SENDERO_H
#define SENDERO_H
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
    float longitud_;
public:
    Sendero(string codigo="",string dificultad = "", string disponibilidad = "",float longitud = 0.0);
    inline string getCodigo()const{return codigo_;}
    inline string getDificultad()const{return dificultad_;}
    inline float getLongitud()const{return longitud_;}
    inline string getDisponibilidad()const{return disponibilidad_;}
    inline void setCodigo(string codigo){codigo_ = codigo;}
    inline void setDificultad(string dificultad){dificultad_ = dificultad;}
    inline bool setLongitud(float longitud);
    inline void setDisponibilidad(string disponibilidad){disponibilidad_ = disponibilidad;}
   
};




#endif
