#ifndef RUTA_H
#define RUTA_H

#include <string>
#include <list>
#include "parque.h"
#include "monitor.h"
#include "cliente.h"
#include "sendero.h"

using namespace std;

struct Hora{

    int horas;
    int minutos;

}

struct Fecha{

    int dia;
    int mes;
    int año;
}

class Ruta{

    private:
        int numeroDeRuta_;
        float longitud_;
        struct Fecha fecha_;
        struct Hora hora_;
        Monitor monitor_;
        int aforo_;
        int duracion_; //1 media jornada, 2 jornada completa
        list <Cliente> clientes_;
        list <Sendero> senderos_;

    public:

        Ruta( int numeroDeRuta, Monitor monitor);

        inline int getNumero()const{ return numeroDeRuta_ ; }
        inline float getLongitud()const{ return longitud_ ; }
        inline struct Fecha getFecha()const{ return fecha_ ; }
        inline struct Hora getHora()const{ return hora_ ; }
        inline Monitor getMonitor()const{ return Monitor_ ; }
        inline int getAforo()const{ return aforo_ ; }
        inline string getDuracion()const{ return duracion_ ; }
        inline list <Cliente> getClientes()const{ return clientes_ ; }
        inline list <Sendero> getSenderos()const{ return senderos_ ; }


        bool setLongitud();
        bool setFecha(const int dia, const int mes, const int año);
        bool setHora( const int hora, const int minuto);
        bool setMonitor( const Monitor monitor);
        bool setAforo( const int aforo);
        bool setDuracion(const int duracion);

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

};


#endif