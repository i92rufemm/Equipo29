#include <iostream>
#include "ruta.h"


Ruta::Ruta( int numeroDeRuta, Monitor monitor ){.

 numeroDeRuta_ = numeroDeRuta;
 longitud_ = 0;
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

bool Ruta::setFecha(const int dia, const int mes, const int año){

    if( Buscar_Fecha(dia,mes,año) ){

        return false;
    }
    else{

        fecha_.dia= dia;
        fecha_.mes= mes;
        fecha_.año= año;
        
        return true;
    }

}

bool Ruta::setHora( const int hora, const int minuto){

    if( hora < 7 || hora > 18 || minuto < 0 || minuto >59){
        return false;
    }
    else{

        hora_.horas = hora;
        hora_.minutos = minuto;
        return true;

    }

}


bool Ruta::setMonitor( const Monitor monitor){

    vector <struct Fecha> ocupacion;

    ocupacion = monitor.getFechas() 


}

bool Ruta::setAforo( const int aforo){

    if( getClientes().size() > aforo ){

        return false;
    }
    else{

        return true;
    }
}

bool Ruta::setDuracion(const int duracion){

    if( duracion != 1 || duracion != 2 ){
        return false;
    }

    else{
        
        duracion_ = duracion;
        return true;
    }
}


int Ruta::addCliente(const Cliente client){

    if( clientes_.size() >= getAforo() ){

        return -1;
    }

    for( std:: list<Cliente>::iterator i = clientes_.begin(); i != clientes_.end(); i++){
        
        if( i -> getDNI() == client.getDNI() )
			return -2;
    }

    clientes_.push_back(client);

    return 1;
}

int Ruta::deleteCliente(const string dni){

    if( clientes_.empty() ){
        return -1;
    }

    for( std:: list<Cliente>:: iterator i = clientes_.begin(); i!= clientes_.end(); i++){
        
        if( i -> getDNI() == dni() ){
            clientes_.erase(i);
            return 1;
        }
    }

    return -2;
}

int Ruta::deleteCliente(const Cliente client){


	if( clientes_.empty() ){
			return -1;
	}

	for( std::list<Cliente>::iterator i = clientes_.begin(); i != clientes_.end(); i++ ){

		if( i -> getDNI() == client.getDNI() ){
			clientes_.erase(i);
			return 1;
		}
	
	}

	return -2;
}


int Ruta::addSendero( const Sendero sendero ){

    if( sendero.getDisponibilidad() != "abierto" ){

        return -1;
    }

    for( std:: list<Sendero>::iterator i = senderos_.begin(); i != senderos_.end(); i++){
        
        if( i -> getCodigo() == sendero.getCodigo() )
			return -2;
    }

    sendero_.push_back(client);

    return 1;
}

int Ruta::deleteSendero(const string codigo){

    if( senderos_.empty() ){
        return -1;
    }

    for( std:: list<Sendero>:: iterator i = senderos_.begin(); i!= senderos_.end(); i++){
        
        if( i -> getCodigo() == codigo ){
            senderos_.erase(i);
            return 1;
        }
    }

    return -2;
}

int deleteSendero(const Sendero sendero){

    if( senderos_.empty() ){
			return -1;
	}

	for( std::list<Sendero>::iterator i = senderos_.begin(); i != senderos_.end(); i++ ){

		if( i -> getCodigo() == sendero.getCodigo() ){
			senderos_.erase(i);
			return 1;
		}
	
	}

	return -2;
}