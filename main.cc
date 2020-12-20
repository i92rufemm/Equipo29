#include "parque.h"
#include "estructuras.h"
#include "sendero.h"
#include "Monitor.h"
#include "Cliente.h"
#include "ruta.h"


int main(){
    Parque parque;
    Monitor monitor;
    Cliente cliente;
    Sendero sendero("122",parque);
    Ruta ruta(122,monitor);
    
    int op;
    string key;
    //variables sendero
    string dificultad;
    string disponibilidad;
    float longitud;
    //variables parque
    string nombreparque;
    float superficie;
    float ubicacion;
    string localizacion;
    //variables monitor
    string NombreMonitor; 
    string ApellidosMonitor; 
    string DNIMonitor; 
    string CorreoMonitor;
    int diaMonitor;
    int mesMonitor; 
    int anioMonitor; 
    int TelefonoMonitor;
    //variables cliente
    string NombreCliente;
    string ApellidosCliente;
    string DNICliente; 
    string CorreoCliente;
    string DiscapacidadCliente;
    int diaCliente;
    int mesCliente;
    int anioCliente;


    if(parque.lee_senderos_parque() == false){
        cout << "Error al leer los datos del fichero sendero" << endl;
        exit(-1);
    }
    if(parque.lee_rutas() == false){
        cout << "Error al leer los datos del fichero rutas" << endl;
        exit(-1);
    }
    if(parque.lee_monitores_parque() == false){
        cout << "Error al leer los datos de los monitores" << endl;
        exit(-1);
    }
    if(parque.lee_clientes_parque() == false){
        cout << "Error al leer los datos de los clientes del parque" << endl;
        exit(-1);
    }


    cout << "Bienvenid@ a la aplicacion de los parques naturales de Cordoba\n ¿que quieres hacer?" << endl;
    
    do{
        do{
            cout << "(1)Registrar nuevo sendero" << endl;                
            cout << "(2)Registrar nuevo cliente" << endl;
            cout << "(3)Registrar nuevo monitor" << endl;
            cout << "(4)Registrar nuevo parque" << endl;
            cout << "(5)Cancelar ruta" << endl;
            cout << "(6)" << endl;
            cout << "(7)" << endl;
            cout << "(8)" << endl;
            cout << "(9)" << endl;

            cin >> op;

        }while(op < 1 || op > 9 );

        switch(op){
            case 1:
                cout << "Dificultad(): ";
                getline(cin,dificultad);
                sendero.setDificultad(dificultad);
                cout << "Disponibilidad(): ";
                getline(cin,disponibilidad);
                sendero.setDisponibilidad(disponibilidad);
                cout << "Longitud(metros): ";
                cin >> longitud;
                sendero.setLongitud(longitud);
                sendero.setParque(parque);

            break;
            case 2:
	            cout<<"Nombre(): ";
            	getline(cin, NombreMonitor);
            	monitor.setNombre(NombreMonitor);
            	cout<<"Apellidos(): ";
            	getline(cin, ApellidosMonitor);
	            monitor.setApellidos(ApellidosMonitor);
	            cout<<"DNI(): ";
                getline(cin, DNIMonitor);
                monitor.setDNI(DNIMonitor);
                cout<<"Correo(): ";
                getline(cin, CorreoMonitor);
                monitor.setCorreo(CorreoMonitor);
                cout<<"Telefono(): ";
                cin>>TelefonoMonitor;
                monitor.setTelefono(TelefonoMonitor);
                cout<<"Fecha de nacimiento():\n";
                cout<<"Dia(): ";
                cin>>diaMonitor;
                cout<<"Mes(numero): ";
                cin>>mesMonitor;
                cout<<"Anio(): ";
                cin>>anioMonitor;
	            monitor.setFecha(diaMonitor, mesMonitor, anioMonitor);


            break;
            case 3:
                cout<<"Nombre(): ";
                getline(cin, NombreCliente);
                cliente.setNombre(NombreCliente);
                cout<<"Apellidos(): ";
                getline(cin, ApellidosCliente);
                cliente.setApellidos(ApellidosCliente);
                cout<<"DNI(): ";
                getline(cin, DNICliente);
                cliente.setDNI(DNICliente);
                cout<<"Correo(): ";
                getline(cin, CorreoCliente);
                cliente.setCorreo(CorreoCliente);
                cout<<"Discapacidad(): ";
                getline(cin, DiscapacidadCliente);
                cliente.setDiscapacidad(DiscapacidadCliente);
                cout<<"Fecha de nacimiento():\n";
                cout<<"Dia(): ";
                cin>>diaCliente;
                cout<<"Mes(numero): ";
                cin>>mesCliente;
                cout<<"Anio(): ";
                cin>>anioCliente;
                cliente.setFecha(diaCliente, mesCliente, anioCliente);

            break;
            case 4:
            cout << "Nombre del parque: ";
            getline(cin,nombreparque);
            parque.setNombre(nombreparque);
            cout << "Superficie(m²): ";
            cin >> superficie;
            parque.setSuperficie(superficie);
            cout << "Ubicacion: ";
            cin >> ubicacion;
            parque.setUbicacion(ubicacion);
            cout << "Localizacion(ciudad provincia): ";
            getline(cin,localizacion);
            parque.setLocalizacion(localizacion);
            break;
            case 5:
            if(parque.Cancelar_ruta(ruta)){
                cout << "La ruta se ha cancelado con exito" << endl;
            }
            else{
                cout << "La ruta no se ha podido cancelar" << endl;
            }
            break;
        }
      
    }while(key == "si" || key == "Si");

    








}