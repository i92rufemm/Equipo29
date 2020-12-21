#ifndef _PARQUE.h_
#define _PARQUE.h_


#include <iostream>
#include <fstream>
#include <cstring> //prototipos de strcpy y strncpy
#include <cstdlib>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

#include "estructuras.h"
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
    vector<Sendero> senderos_;
    vector<Ruta> rutas_;
    vector <Cliente> clientes_; // he tenido que añadir este vector para almacenar todos los clientes del parque
    vector <Monitor> monitores_; // he tenido que añadir este vector para almacenar todos los monitores del parque


public:
    Parque(string nombreparque="",float superficie = 0.0,float ubicacion = 0.0,string localizacion = "");
    inline string getNombre()const{return nombreparque_;}
    inline float getSuperficie()const{return superficie_;}
    inline string getLocalizacion()const{return localizacion_;}
    inline float getUbicacion()const{return ubicacion_;}
    inline list<string> getPremios()const{return premios_;}
    inline vector<Sendero> getSenderos()const{return senderos_;}
    inline vector<Ruta> getRutas()const{return rutas_;}
    inline void setNombre(string nombreparque){nombreparque_ = nombreparque;}
    inline bool setSuperficie(float superficie);
    inline void setUbicacion(float ubicacion){ubicacion_ = ubicacion;}
    inline void setLocalizacion(string localizacion){localizacion_ = localizacion;}
    bool addPremios(string premios);
    bool addSendero(Sendero senderos);
    Ruta Seleccionar_ruta();
    Sendero Seleccionar_sendero();
    bool Cancelar_ruta(Ruta rutas);

    Cliente Seleccionar_cliente(string DNI); 
    Monitor Seleccionar_Monitor(string DNI); //pendiente

    //2º sprint cabecera funciones para guardar y leer los datos del fichero
    bool escribir_datos_rutas();
    bool lee_rutas();

    bool escribir_clientes_parque();
    bool lee_clientes_parque();

    bool escribir_monitores_parque();
    bool lee_monitores_parque();

    bool escribir_senderos_parque();
    bool lee_senderos_parque();


   bool AddCliente(Cliente cliente);
   bool DeleteCliente(Cliente cliente);

   bool AddMonitor(Monitor monitor);
   bool DeleteMonitor(Monitor monitor);
    
};



#endif