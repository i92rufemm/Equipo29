#include <iostream>
#include "ruta.h"


Ruta::Ruta( int numeroDeRuta, Monitor monitor ){.

 numeroDeRuta_ = numeroDeRuta;
 longitud_ = 0;
 fecha_ = '\0';
 hora_ = '\0';
 monitor_ = monitor;
 aforo_ = 0;
 duracion_ = '\0';

}


bool Ruta::setLongitud(){

    float aux = 0;

    if( senderos_.empty() ){
			return false;
	}

   ( std::vector<Sendero>::iterator i = senderos_.begin(); i != senderos_.end(); i++ ){

       aux = aux + (*i).getLongitud();
   }

   longitud_ = aux;

   return true;
}

bool Ruta::setFecha(const string fecha){

    if( Buscar_Fecha() ){

        return false;
    }
    else{

        fecha_= fecha;
    }

}