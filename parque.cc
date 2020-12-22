
#include "parque.h"
using namespace std;

Parque::Parque(string nombreparque,float superficie,float ubicacion,string localizacion)
{
    nombreparque_=nombreparque;
    superficie_ = superficie;
    ubicacion_ = ubicacion;
    localizacion_ = localizacion;
}
bool Parque::setSuperficie(float superficie){
    if(superficie > 0){
        superficie_ = superficie;
        return true;
    }
    return false;
}
bool Parque::addPremios(string premios){
    int tamanio = (int)premios_.size();
    premios_.push_back(premios);
    if (tamanio < (int)premios_.size())
    {
        cout << "Se ha añadido el premio con exito " << endl;
        return true;
    }
    return false;
}
bool Parque::addSendero(Sendero sendero){
    for(vector<Sendero>::iterator it = senderos_.begin(); it != senderos_.end(); it++){
        if(it->getCodigo() == sendero.getCodigo()){
            cout << "El sendero ya esta registrado" << endl;
            return false;
        }
    }
    senderos_.push_back(sendero);
    cout << "El sendero ha sido registrado" << endl;
    return true;
}
bool Parque::deleteSendero(Sendero sendero){
       for(vector<Sendero>::iterator it = senderos_.begin(); it != senderos_.end(); it++){
        if(it->getCodigo() == sendero.getCodigo()){
            senderos_.erase(it);
            cout << "El sendero ha sido eliminado" << endl;
            return true;
        }
    }
    cout << "El sendero no ha sido encontrado" << endl;
    return false;
}
bool Parque::Cancelar_ruta(Ruta ruta){
    
    for(vector<Ruta>::iterator it = rutas_.begin(); it != rutas_.end();it++){
        if(it->getNumero() == ruta.getNumero()){
            rutas_.erase(it);
            cout << "La ruta ha sido cancelada con exito" << endl;
            return true;
        }
    }
    cout << "No se ha encontrado la ruta que se querias borrar" << endl;
    return false;
}
bool Parque::comprobarDNI(string DNI){
      for (vector<Monitor>:: iterator it = monitores_.begin(); it != monitores_.end(); it++){
        if(it->getDNI() == DNI){
            return true;
        }
    } 
    return false;
}

bool Parque::comprobarCodigo(string codigo){
    for (vector<Sendero>:: iterator it = senderos_.begin(); it != senderos_.end(); it++){
        if(it->getCodigo() == codigo){
            return true;
        }
    } 
    return false;
}


Ruta Parque::Seleccionar_ruta(int numrut){
    for (vector<Ruta>:: iterator it = rutas_.begin(); it != rutas_.end(); it++){
        if(it->getNumero() == numrut){
            return *it;
        }
    }    

}

Sendero Parque::Seleccionar_sendero(string codigo){
    for (vector<Sendero>::iterator it = senderos_.begin(); it != senderos_.end(); it++)
    {
        if(it->getCodigo() == codigo){
            return *it;
        }
    }    
}
bool Parque::AddRuta(Ruta ruta){
      for( std::vector<Ruta>::iterator i = rutas_.begin(); i != rutas_.end(); i++ ){

        if(ruta.getNumero() == i-> getNumero() ){
            
            return false;
        }

    }

    rutas_.push_back(ruta);

    return true;
}
bool Parque::DeleteRuta(Ruta ruta){
      for( std::vector<Ruta>::iterator i = rutas_.begin(); i != rutas_.end(); i++ ){

        if(ruta.getNumero() == i-> getNumero() ){
            rutas_.erase(i);
            return true;
        }

      }
    return false;
}

bool Parque::escribir_datos_rutas(){

    string nombre_fichero;
    string nombre,apellidos, DNI;
    char auxiliar[100] = "\0";
    struct Fecha fecha;
    struct Hora hora;

    ofstream fichero;


    nombre_fichero = "rutas.txt";

    strcpy(auxiliar,nombre_fichero.c_str());

    remove( auxiliar );

    fichero.open(nombre_fichero, ios::out);

    if( fichero.fail() ){
		cout << "Error al abrir fichero" << endl;
		return false;
	}
for( std::vector<Ruta>::iterator i = rutas_.begin(); i != rutas_.end(); i++ ){

    hora = i->getHora();
    fecha = i->getFecha();
    

    fichero << i->getNumero() << ',';
	fichero << i->getLongitud() << ',';
	fichero << fecha.dia << '/';
	fichero << fecha.mes << '/';
	fichero << fecha.anio << ',';
	fichero << hora.horas << ':';
	fichero << hora.minutos << ',';
    fichero << i -> getMonitor().getNombre() << ',';
    fichero << i -> getMonitor().getApellidos() << ',';
	fichero << i->getMonitor().getDNI() << ',';
	fichero << i->getAforo() << ',';
    fichero << i->getDuracion() << '\n';
}
    
    fichero.close();

    return true;
}


bool Parque::lee_rutas(){

    string numeroDeRuta, aforo, duracion;
    string longitud;
    string dia, mes, anio;
    string  horas,minutos;
    string nombre, apellidos, DNI;

    Monitor monitor;

    ifstream fichero;

	fichero.open("rutas.txt", ios::in );

	if( fichero.fail() ){
		cout << "Error al abrir fichero" << endl;
		return false;
	}

    while( getline( fichero, numeroDeRuta, ',' ) ){

		getline( fichero, longitud, ',' );
		getline( fichero, dia, '/' );
		getline( fichero, mes, '/' );
		getline( fichero, anio, ',' );
		getline( fichero, horas, ':' );
		getline( fichero, minutos, ',' );
        getline( fichero, nombre, ',' );
        getline( fichero, apellidos, ',' );
		getline( fichero, DNI, ',' );
		getline( fichero, aforo, ',' );
        getline( fichero, duracion, '\n' );

        Monitor monitor(nombre, apellidos, DNI);

		Ruta ruta(stoi(numeroDeRuta), monitor, stof(longitud), stoi(dia), stoi(mes), stoi(anio), stoi(horas), stoi(minutos),
               stoi(aforo), stoi(duracion) );

		rutas_.push_back(ruta);
	}

	fichero.close();

    return true;
}

//

bool Parque::escribir_clientes_parque(){

    string nombre_fichero;
    char auxiliar[100] = "\0";

    struct Fecha fecha;
    

    ofstream fichero;

    nombre_fichero = getNombre()+"_clientes.txt";

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


bool Parque::lee_clientes_parque(){

    string nombre_fichero, nombre, apellidos, dia, mes, anio, DNI, correo, discapacidad;


    ifstream fichero;

    nombre_fichero = getNombre()+"_clientes.txt";

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



bool Parque::escribir_monitores_parque(){

    string nombre_fichero;
    char auxiliar[100] = "\0";

    struct Fecha fecha;
    

    ofstream fichero;

    nombre_fichero = getNombre()+"_monitores.txt";

    strcpy(auxiliar,nombre_fichero.c_str());

    remove( auxiliar );

    fichero.open(nombre_fichero, ios::out);

    if( fichero.fail() ){
		cout << "Error al abrir fichero" << endl;
		return false;
	}

for( std::vector<Monitor>::iterator i = monitores_.begin(); i != monitores_.end(); i++ ){

    fecha = i->getFecha();

    fichero << i->getNombre() << ',';
	fichero << i->getApellidos() << ',';
	fichero << fecha.dia << '/';
	fichero << fecha.mes << '/';
	fichero << fecha.anio << ',';
	fichero << i->getDNI() << ',';
	fichero << i->getCorreo() << ',';
    fichero << i->getTelefono() << '\n';
}
    
    fichero.close();

    return true;
}


bool Parque::lee_monitores_parque(){

    string nombre_fichero, nombre, apellidos, dia, mes, anio, DNI, correo, telefono;


    ifstream fichero;

    nombre_fichero = getNombre()+"_monitores.txt";

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
		getline( fichero, telefono, '\n' );

        Monitor monitor(nombre, apellidos, DNI, stoi(dia),stoi(mes), stoi(anio),correo, stoi(telefono) );

		monitores_.push_back(monitor);
	}

	fichero.close();

    return true;
}

bool Parque::escribir_senderos_parque(){
    string nombre_fichero;
    string codigo,dificultad,disponibilidad;
    
    char auxiliar[100] = "\0";

    ofstream fichero;
    
    nombre_fichero = "senderos.txt";

    strcpy(auxiliar,nombre_fichero.c_str());

    remove( auxiliar );

    fichero.open(nombre_fichero, ios::out);

    if( fichero.fail() ){
		cout << "Error al abrir fichero" << endl;
		return false;
	} 
    for(std::vector<Sendero>::iterator i = senderos_.begin(); i != senderos_.end(); i++){
        fichero << i->getCodigo()<< ",";
        fichero << i->getDificultad() << ",";
        fichero << i->getDisponibilidad() << ",";
        fichero << i->getLongitud() << "\n";
    }
    fichero.close();
    return true;
}
bool Parque::lee_senderos_parque(){
    
    string codigo,dificultad,disponibilidad,longitud;
    string nombreparque,superficie,ubicacion,localizacion;
    ifstream fichero;

    fichero.open("senderos.txt",ios::in);

    if( fichero.fail() ){
		cout << "Error al abrir fichero" << endl;
		return false;
	}

    while(getline(fichero,codigo, ',')){
        
        
        getline(fichero,dificultad,',');
        getline(fichero,disponibilidad,',');
        getline(fichero,longitud,'\n');
      
        Sendero sendero(codigo,dificultad,disponibilidad,stof(longitud));//codigo es un parametro obligatorio

        senderos_.push_back(sendero);
    }
    fichero.close();
    return true;
}


bool Parque::AddCliente(Cliente cliente){

    for( std::vector<Cliente>::iterator i = clientes_.begin(); i != clientes_.end(); i++ ){

        if( cliente.getDNI() == i-> getDNI() ){
            
            return false;
        }

    }

    clientes_.push_back(cliente);

    return true;

}

bool Parque::DeleteCliente( Cliente cliente){

    for( std::vector<Cliente>::iterator i = clientes_.begin(); i != clientes_.end(); i++ ){

        if( cliente.getDNI() == i-> getDNI() ){
            
            clientes_.erase(i);
            return true;
        }

    }

    return false;
}


Cliente Parque::Seleccionar_cliente(string DNI){

    for( std::vector<Cliente>::iterator i = clientes_.begin(); i != clientes_.end(); i++ ){

        if( DNI == i-> getDNI() ){
            
            return *i;
        }

    }

    cout<< "cliente no encontrado \n";
}


bool Parque::AddMonitor(Monitor monitor){

    for( std::vector<Monitor>::iterator i = monitores_.begin(); i != monitores_.end(); i++ ){

        if( monitor.getDNI() == i-> getDNI() ){
            
            return false;
        }

    }

    monitores_.push_back(monitor);

    return true;

}

bool Parque::DeleteMonitor( Monitor monitor){

    for( std::vector<Monitor>::iterator i = monitores_.begin(); i != monitores_.end(); i++ ){

        if( monitor.getDNI() == i-> getDNI() ){
            
            monitores_.erase(i);
            return true;
        }

    }

    return false;
}


Monitor Parque::Seleccionar_Monitor(string DNI){

    for( std::vector<Monitor>::iterator i = monitores_.begin(); i != monitores_.end(); i++ ){

        if( DNI == i-> getDNI() ){
            
            return *i;
        }

    }

    cout<< "Monitor no encontrado \n";
}

 void Parque::Cancelar_ruta_por_sendero( string codigo){

     for( std::vector<Ruta>::iterator i = rutas_.begin(); i != rutas_.end(); i++ ){

         for( std::list<Sendero>::iterator it = i->getSenderos().begin(); it != i->getSenderos().end(); i++ ){

            if( it -> getCodigo() == codigo ){

                rutas_.erase(i);
            }

         }

     }


 }



 struct FechaTiempo Parque:: TiempoReal(){


    /*
    struct tm {
      int tm_sec;   // seconds of minutes from 0 to 61
      int tm_min;   // minutes of hour from 0 to 59
      int tm_hour;  // hours of day from 0 to 24
      int tm_mday;  // day of month from 1 to 31
      int tm_mon;   // month of year from 0 to 11
      int tm_year;  // year since 1900
      int tm_wday;  // days since sunday
      int tm_yday;  // days since January 1st
      int tm_isdst; // hours of daylight savings time
    }
    */

    struct FechaTiempo local;


    /* fecha/hora actual basado en el sistema actual */
    time_t now = time(0);

    /* Objeto de una estructura tm con fecha/hora local */
    tm * time = localtime(&now);



    local.anio = 1900 + time->tm_year;

    local.dia = time->tm_mday;

    local.mes = (time->tm_mon) +1;

    local.horas = time->tm_hour;

    local.minutos = time->tm_min;

    return local;

 }

 bool Parque::ComprobarTiempo(Ruta ruta){
    
     struct FechaTiempo local;

     local = TiempoReal();

    if( ruta.getFecha().anio == local.anio  && ruta.getFecha().mes == local.mes
        && ruta.getFecha().dia == local.dia ){

        if( ruta.getHora().horas - local.horas   < 0 ){

            return false;
        }

        if( ruta.getHora().horas - local.horas  == 0  ){

            if( (ruta.getHora().minutos - local.minutos ) < 15 ){
                
           return false;

            }
        }

        if( ruta.getHora().horas - local.horas == 1 ){

            if( ( (ruta.getHora().minutos - local.minutos) + 60 ) < 15 ){
                
            return false;

            }

        }


    }

    return true;

 }