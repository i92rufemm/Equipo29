
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
    int tamanio = premios_.size();
    premios_.push_back(premios);
    if (tamanio < premios_.size())
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
Ruta Parque::Seleccionar_ruta(){
    int numrut;
    cout << "¿Cual es la ruta que quieres buscar?\n Dime el numero" << endl;
    cin >> numrut;
    for (vector<Ruta>:: iterator it = rutas_.begin(); it != rutas_.end(); it++){
        if(it->getNumero() == numrut){
            return *it;
        }
    }    
}
Sendero Parque::Seleccionar_sendero(){
    string codigo;
    cout << "Dime el codigo del sendero que quieres seleccionar" << endl;
    getline(cin,codigo);
    for (vector<Sendero>::iterator it = senderos_.begin(); it != senderos_.end(); it++)
    {
        if(it->getCodigo() == codigo){
            return *it;
        }
    }    
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
		exit(1);
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

    fecha = i->getFechaN();

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

    fecha = i->getFechaN();

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
    float longitud;
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