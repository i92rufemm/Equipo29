#ifndef _PARQUE.h_
#define _PARQUE.h_


#include <iostream>
#include <list>
#include <vector>
#include "ruta.h"
#include "sendero.h"
#include "Monitor.h"
using namespace std;


class Parque
{
private:
    /* datos privados*/
    string nombreparque_;
    float superficie_;
    float ubicacion_;
    string localizacion_;
    list<string>premios_;
    vector<Sendero>senderos_;
    vector<Ruta>rutas_;

public:
    Parque(string nombreparque="",float superficie = 0.0,float ubicacion = 0.0,string localizacion = "");
    inline string getNombre()const{return nombreparque_;}
    inline float getSuperficie()const{return superficie_;}
    inline float getUbicacion()const{return ubicacion_;}
    inline list<string> getPremios()const{return premios_;}
    inline vector<Sendero> getSenderos()const{return senderos_;}
    inline vector<Ruta> getRutas()const{return rutas_;}
    inline void setNombre(string nombreparque){nombreparque_ = nombreparque;}
    inline bool setSuperficie(float superficie);
    inline void setUbicacion(float ubicacion){ubicacion_ = ubicacion;}
    inline void setLocalizacion(string localizacion){localizacion_ = localizacion;}
    bool addPremios(string premios);
    bool addSendero(Sendero senderos);//deberia ser bool por si mete un sendero que ya esta dentro
    Ruta Seleccionar_ruta();//hablar de esta funcion
    Sendero Seleccionar_sendero();//hablar de esta funcion
    bool Cancelar_ruta(Ruta rutas);
};



#endif