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
            cout << "(5)" << endl;
            cout << "(6)" << endl;
            cout << "(7)" << endl;
            cout << "(8)" << endl;
            cout << "(9)" << endl;

            cin >> op;

        }while(op < 1 || op > 9 );

        switch(op){
            case 1:
                string dificultad,disponibilidad;
                cout << "Dificultad(): ";
                getline(cin,dificultad);
                sendero.setDificultad(dificultad);
                cout << "Disponibilidad(): ";
                getline(cin,disponibilidad);
                cout << endl

            break;

        }

    }while(key == "si" || key == "Si");

    








}