/*
    Este fichero incluye algunas de las funciones que mostraria la interfaz del programa.

    Al igual que solo hemos hecho el test de alguna de ellas, solo hemos implementado algunas en la interfaz
    a modo de muestra, para no prolongar mas la tarea.


*/

#include <iostream>
#include <ctime>
#include <vector>

#include "parque.h"
#include "estructuras.h"
#include "sendero.h"
#include "Monitor.h"
#include "Cliente.h"
#include "ruta.h"




int main(){

    struct FechaTiempo local;

    Parque parque("por_defecto");
    Monitor monitor;
    Cliente cliente;
    Sendero sendero("122");
    Ruta ruta(122,monitor);
    
    int op;
    string key;
    int aux;
    //variables sendero
    string codigo;
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
    //variables ruta
    int numeroruta;
    int dia;
    int mes;
    int anio;
    int horas;
    int minutos;
    int aforo;
    int duracion;


    if ( !parque.lee_senderos_parque() )
        exit(-1);

    if( !parque.lee_rutas() )
        exit(-1);

    if( !parque.lee_monitores_parque() )
        exit(-1);

    if( !parque.lee_clientes_parque() )
        exit(-1);
    


    cout << "Bienvenid@ a la aplicacion de los parques naturales de Cordoba\n ¿que quieres hacer?" << endl;
    
    do{
        do{
            cout << "(1)Registrar nuevo sendero" << endl;                
            cout << "(2)Registrar nuevo monitor" << endl;
            cout << "(3)Registrar nuevo cliente" << endl;
            cout << "(4)Registrar nuevo parque" << endl;
            cout << "(5)Cancelar ruta" << endl;
            cout << "(6)Imprimir senderistas" << endl;
            cout << "(7)Registrar nueva ruta" << endl;
            cout << "(8)Modificar disponibilidad sendero" << endl;
            cout << "(9)Aniadir cliente a ruta" << endl;
            cout << "(10)salir del programa" << endl;

        if( parque.getNombre() != "por_defecto" && !parque.getSenderos().empty() )
            cin >> op;


        else if(parque.getNombre() == "por_defecto"){

            cout << "Debe crear el parque, ya que no existe ninguno";
            op = 4;
        }

        else if(parque.getSenderos().empty() ){

            cout << "Debe crear senderos, ya que no existe ninguno";
            op = 1;
        }

    

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
                parque.addSendero(sendero);

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

                parque.AddMonitor(monitor);


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
                
                parque.AddCliente(cliente);

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

                cout << "Selecciona la ruta,dime el numero de la ruta" << endl;
                cin >> numeroruta;
                ruta = parque.Seleccionar_ruta(numeroruta);


                if( !parque.ComprobarTiempo(ruta) ){

                    cout << "demasiado tarde para modificar la ruta\n";
                    break;
                }


                if(parque.Cancelar_ruta(ruta)){
                    cout << "La ruta se ha cancelado con exito" << endl;
                }
                else{
                    cout << "La ruta no se ha podido cancelar" << endl;
                }
            break;

            case 6:

                cout << "SELECCIONA LA RUTA" << endl;
                ruta = parque.Seleccionar_ruta(numeroruta);
                cout << "Imprimiendo senderistas de la ruta"<<endl;
                ruta.imprimirClientes();
            break;

            case 7:
                aux = (parque.getRutas().size()+1);
                cout << "Dime el dni del monitor que va a realizar esta ruta" << endl;
                getline(cin,DNIMonitor);
                if(parque.getMonitores().empty()){
                    cout << "No hay monitores registrados"<< endl;
                    break;
                }
                if (!parque.comprobarDNI(DNIMonitor))
                {
                    cout << "El monitor no esta registrado" << endl;
                    break;
                }
                
                monitor = parque.Seleccionar_Monitor(DNIMonitor);
                
                if(!ruta.setFecha(dia,mes,anio)){
                    cout << "La fecha no esta disponible" << endl;
                    break;
                }
                if(parque.getSenderos().empty()){
                    cout << "No existen senderos registrados" << endl;
                    break;
                }
                do{

                    cout << "Codigo del sendero que quieres anadir a ruta" << endl;
                    getline(cin,codigo);
                    
                    if(parque.comprobarCodigo(codigo)){
                        sendero = parque.Seleccionar_sendero(codigo);
                        aux = ruta.addSendero(sendero);
                        if(aux == -1){
                            cout << "Sendero no disponible"<< endl;

                        }
                
                        if(aux == -2){
                            cout << "Sendero ya anadido"<< endl;

                        }
                        if(aux == 1)   
                            cout << "Sendero anadido" << endl;            
                
                    }
                    else{
                        cout << "Sendero no encontrado" << endl;
                    }
                    cout << "Quiere anadir otro sendero(Si/No)" << endl;
                    
                    getline(cin,key);

                }while(key == "Si");
                ruta.setMonitor(monitor);
                ruta.setNumero(aux);
                ruta.setHora(horas,minutos);
                cout << "Aforo: ";
                cin >> aforo;
                ruta.setAforo(aforo);
                ruta.setDuracion(duracion);
                ruta.setLongitud();
                if(parque.AddRuta(ruta)){
                    cout << "Ruta anadida con exito" << endl;
                }
                else{
                    cout << "Error al anadir la ruta" << endl;
                }

            break;

            case 8:

                cout << "Introduzca el codigo del sendero \n";
                cin >> codigo;

                cout << "Introduzca la disponibilidad del sendero (abierto/cerrado/en mantenimineto)\n";
                cin >> disponibilidad;

                if( disponibilidad == "cerrado" || disponibilidad == "en mantenimiento"){

                    parque.Cancelar_ruta_por_sendero(codigo);

                }
                sendero = parque.Seleccionar_sendero(codigo);

                sendero.setDisponibilidad( disponibilidad );

                cout << "la nueva disponibilidad del sendero es:   "<< disponibilidad << endl;

            break;
            

            case 9:

                cout << "Introduzca DNI del cliente.\n";
                cin >> DNICliente;

                cliente = parque.Seleccionar_cliente(DNICliente);

                cout << "Introduzca el numero de ruta.\n";
                cin >> numeroruta;

                ruta = parque.Seleccionar_ruta(numeroruta);

                if( !parque.ComprobarTiempo(ruta) ){

                    cout << "demasiado tarde para aniadir el cliente\n";
                    break;
                }

               aux = ruta.addCliente(cliente);

               if( aux == -1 )
                cout <<"la ruta esta completa.\n";

               if( aux == -2 )
                cout <<"el cliente ya esta apuntado a la ruta.\n";

               if ( aux == 1 )
                cout <<"el cliente ha sido añadido a la ruta con exito.\n";  
            

            break;



        }

      
    }while( op != 10 );

    

    if( parque.escribir_datos_rutas() || parque.escribir_clientes_parque() || parque.escribir_monitores_parque() || parque.escribir_senderos_parque() )
        cout << "Datos guardados con exito \n";

    else
        cout << "Error al guardar datos \n";


    return 0;


}