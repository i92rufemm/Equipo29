#include <iostream>
#include "ruta.h"

using namespace std;

Ruta::Ruta( int numeroDeRuta, Monitor monitor){

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

   for( std::list<Sendero>::iterator i = senderos_.begin(); i != senderos_.end(); i++ ){

       aux = aux + (*i).getLongitud();
   }

   longitud_ = aux;

   return true;
}

bool Ruta::setFecha(const int dia, const int mes, const int anio, list<Fecha> fechas ){ // setFecha(5,2,2020, parque.getFechas() );

    struct Fecha aux;

    aux.dia= dia;
    aux.mes= mes;
    aux.anio= anio;

    for( std:: list<Fecha>::iterator i = fechas.begin(); i != fechas.end(); i++ ){

        if( (*i).dia == aux.dia &&  (*i).mes == aux.mes && (*i).anio == aux.anio ){

            return false;
        }

    }

        fecha_ = aux;

        fechas.push_back(fecha_);
        
        return true;

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


bool Ruta::setMonitor(  Monitor monitor){

    struct Fecha aux;

    vector <Fecha> ocupacion;

    ocupacion = monitor.getFechas();

    aux = getFecha();

    for( std:: vector<Fecha>::iterator i = ocupacion.begin(); i != ocupacion.end(); i++ ){

        if( (*i).dia == aux.dia &&  (*i).mes == aux.mes && (*i).anio == aux.anio ){

            return false;
        }

    }

        monitor_ = monitor;
        
        return true;

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

    for( std:: vector<Cliente>::iterator i = clientes_.begin(); i != clientes_.end(); i++){
        
        if( i->getDNI() == client.getDNI() )
			return -2;
    }

    clientes_.push_back(client);

    return 1;
}

int Ruta::deleteCliente(const string dni){

    if( clientes_.empty() ){
        return -1;
    }

    for( std:: vector<Cliente>:: iterator i = clientes_.begin(); i!= clientes_.end(); i++){
        
        if( (*i).getDNI() == dni ){
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

	for( std::vector<Cliente>::iterator i = clientes_.begin(); i != clientes_.end(); i++ ){

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

    senderos_.push_back(sendero);

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

int Ruta::deleteSendero(const Sendero sendero){

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


void Ruta::imprimirClientes(){

    sort(clientes_.begin(), clientes_.end(), sortByApellidos);

    for (Cliente &n : clientes_)
        cout << n.getDNI() << endl;



}