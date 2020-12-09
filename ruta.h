#ifndef RUTA_H
#define RUTA_H

#include <string>
#include <vector>
#include <list>
#include "parque.h"
#include "monitor.h"
#include "cliente.h"
#include "sendero.h"

using namespace std;

class Ruta{

    private:
        int numeroDeRuta_;
        float longitud_;
        string fecha_;
        string hora_;
        Monitor monitor_;
        int aforo_;
        string duracion_;
        list <Cliente> clientes_;
        vector <Sendero> senderos_;

    public:

        Ruta( int numeroDeRuta, Monitor monitor);

        inline int getNumero()const{ return numeroDeRuta_ ; }
        inline float getLongitud()const{ return longitud_ ; }
        inline string getFecha()const{ return fecha_ ; }
        inline string getHora()const{ return hora_ ; }
        inline Monitor getMonitor()const{ return Monitor_ ; }
        inline int getAforo()const{ return aforo_ ; }
        inline string getDuracion()const{ return duracion_ ; }
        inline list <Cliente> getClientes()const{ return clientes_ ; }
        inline vector <Sendero> getSenderos()const{ return senderos_ ; }


        bool setLongitud();
        bool setFecha(const string fecha);







};


#endif