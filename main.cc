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
    
    cout << "Bienvenid@ a la aplicacion de los parques naturales de Cordoba\n ¿que quieres hacer?" << endl;
    
    do{
        do{
            cout << "(1)Registrar nuevo sendero" << endl;                
            cout << "(2)Registrar nuevo sendero" << endl;
            cout << "(3)Registrar nuevo sendero" << endl;
            cout << "(4)Registrar nuevo sendero" << endl;
            cout << "(5)Registrar nuevo sendero" << endl;
            cout << "(6)Registrar nuevo sendero" << endl;
            cout << "(7)Registrar nuevo sendero" << endl;
            cout << "(8)Registrar nuevo sendero" << endl;
            cout << "(9)Registrar nuevo sendero" << endl;

            cin >> op;

        }while(op < 1 || op > 9 );

        switch(op){
            case 1:

            break;

        }

    }while(key == "si" || key == "Si");










}