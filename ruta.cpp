#include <iostream>
#include "ruta.h"

using namespace std;

Ruta::Ruta( int numeroDeRuta, Monitor monitor, float longitud, int dia, int mes, int anio, int horas, int minutos, int aforo, int duracion){

 numeroDeRuta_ = numeroDeRuta;
 longitud_ = longitud;
 fecha_.dia = dia;
 fecha_.mes = mes;
 fecha_.anio = anio;
 hora_.horas = horas;
 hora_.minutos = minutos;
 monitor_ = monitor;
 aforo_ = aforo;
 duracion_ = duracion;

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

bool Ruta::setFecha(const int dia, const int mes, const int anio){ // setFecha(5,2,2020, parque.getFechas() );

    struct Fecha aux;

    aux.dia= dia;
    aux.mes= mes;
    aux.anio= anio;

        fecha_ = aux;

        
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

bool Ruta::setNumero(int numeroruta){
    numeroDeRuta_ = numeroruta;   
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



bool Ruta::escribir_clientes_rutas(){

    string nombre_fichero;
    char auxiliar[100] = "\0";

    struct Fecha fecha;
    

    ofstream fichero;

    nombre_fichero = getNumero()+".txt";

    strcpy(auxiliar,nombre_fichero.c_str());

    remove( auxiliar );

    fichero.open(nombre_fichero, ios::out);

    if( fichero.fail() ){
		cout << "Error al abrir fichero" << endl;
		return false;
	}

for( std::vector<Cliente>::iterator i = clientes_.begin(); i != clientes_.end(); i++ ){

    fecha = i->getFecha();

    fichero << i->getNombre() << ',';
	fichero << i->getApellidos() << ',';
	fichero << fecha.dia << '/';
	fichero << fecha.mes << '/';
	fichero << fecha.anio << ',';
	fichero << i->getDNI() << ',';
	fichero << i->getCorreo() << ',';
    fichero << i->getDiscapacidad() << '\n';
}
    
    fichero.close();

    return true;
}


bool Ruta::lee_clientes_rutas(){

    string nombre_fichero, nombre, apellidos, dia, mes, anio, DNI, correo, discapacidad;


    ifstream fichero;

    nombre_fichero = getNumero()+".txt";

	fichero.open( nombre_fichero , ios::in );

	if( fichero.fail() ){
		cout << "Error al abrir fichero" << endl;
		return false;
	}

    while( getline( fichero, nombre, ',' ) ){

		getline( fichero, apellidos, ',' );
		getline( fichero, dia, '/' );
		getline( fichero, mes, '/' );
		getline( fichero, anio, ',' );
        getline( fichero, DNI, ',' );
        getline( fichero, correo, ',' );
		getline( fichero, discapacidad, '\n' );

        Cliente cliente(nombre, apellidos,stoi(dia),stoi(mes), stoi(anio), DNI,correo, discapacidad );

		clientes_.push_back(cliente);
	}

	fichero.close();

    return true;
}
