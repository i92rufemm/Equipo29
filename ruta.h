#ifndef RUTA_H
#define RUTA_H

#include <iostream>
#include <fstream>
#include <cstring> //prototipos de strcpy y strncpy
#include <cstdlib>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include "ruta.h"
#include "sendero.h"
#include "Monitor.h"
#include "Cliente.h"


using namespace std;



class Ruta{

    private:
        int numeroDeRuta_;
        float longitud_;
        struct Fecha fecha_;
        struct Hora hora_;
        Monitor monitor_;
        int aforo_;
        int duracion_; //1 media jornada, 2 jornada completa
        vector <Cliente> clientes_;
        list <Sendero> senderos_;

    public:

        Ruta( int numeroDeRuta, Monitor monitor, float longitud=0, int dia=0, int mes=0, int anio=0, int horas=0, 
              int minutos=0, int aforo=0, int duracion=0);

        inline int getNumero()const{ return numeroDeRuta_ ; }
        inline float getLongitud()const{ return longitud_ ; }
        inline struct Fecha getFecha()const{ return fecha_ ; }
        inline struct Hora getHora()const{ return hora_ ; }
        inline Monitor getMonitor()const{ return monitor_ ; }
        inline int getAforo()const{ return aforo_ ; }
        inline int getDuracion()const{ return duracion_ ; }
        inline vector <Cliente> getClientes()const{ return clientes_ ; }
        inline list <Sendero> getSenderos()const{ return senderos_ ; }


        bool setLongitud();
        bool setFecha(const int dia, const int mes, const int anio); // setFecha(5,2,2020, parque.getFechas() );
        bool setHora( const int hora, const int minuto);
        bool setMonitor(Monitor monitor);
        bool setAforo( const int aforo);
        bool setDuracion(const int duracion);
        bool setNumero(int numeroruta);
        bool sortByApellidos(const Cliente &lhs, const Cliente &rhs) { return lhs.getApellidos() < rhs.getApellidos(); }
        void imprimirClientes();

        /* Introduce un cliente en la lista de clientes recibiendolo 
        como argumento. Devuelve 1 si se ha podido introducir el cliente,
        -1 si la lista de clientes para esta ruta esta llena y -2 si el 
        cliente ya estaba apuntado en la lista*/
        int addCliente( const Cliente client);

        /*Borra un cliente de la lista de cliente recibiendo su DNI 
	  como argumento. Devuelve 1 si se ha podido borrar el cliente, 
	  -1 si la lista de clientes esta vacia y -2 si no se ha 
	  encontrado al cliente en la lista*/
        int deleteCliente(const string dni);

        /*Borra un cliente de la lista de cliente recibiendolo 
	  como argumento. Devuelve 1 si se ha podido borrar el cliente, 
	  -1 si la lista de clientes esta vacia y -2 si no se ha 
	  encontrado al cliente en la lista*/
        int deleteCliente(const Cliente client);


        /* Introduce un sendero en el vector de senderos recibiendolo 
        como argumento. Devuelve 1 si se ha podido introducir el sendero,
        -1 si el sendero no esta disponible y -2 si el sendero ya estaba 
        apuntado en el vector*/
        int addSendero( const Sendero sendero );

          /*Borra un sendero de la lista de sendero recibiendo su codigo 
	  como argumento. Devuelve 1 si se ha podido borrar el sendero, 
	  -1 si la lista de senderos esta vacia y -2 si no se ha 
	  encontrado al sendero en la lista*/
        int deleteSendero(const string codigo);

        /*Borra un sendero de la lista de sendero recibiendolo 
	  como argumento. Devuelve 1 si se ha podido borrar el sendero, 
	  -1 si la lista de senderos esta vacia y -2 si no se ha 
	  encontrado al sendero en la lista*/
        int deleteSendero(const Sendero sendero);

        bool escribir_clientes_rutas();
        bool lee_clientes_rutas();

};


#endif