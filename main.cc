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


            break;
            case 3:

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