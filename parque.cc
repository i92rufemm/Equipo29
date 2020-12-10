
#include "parque.h"
using namespace std;

Parque::Parque(string nombreparque,float superficie,float ubicacion,string localizacion)
{
    setNombre(nombreparque);
    superficie_ = superficie;
    ubicacion_ = ubicacion;
    localizacion_ = localizacion;
}
void Parque::addPremios(string premios){
    
}
void Parque::addSendero(Sendero senderos){
    for(list<Sendero>::iterator it = senderos_.begin(); it != senderos_.end(); it++){
        if(it->getCodigo() == senderos.getCodigo()){
            cout << "El sendero ya esta registrado" << endl;
            exit(1);
        }
    }
    senderos_.push_back(senderos);
    cout << "El sendero ha sido registrado" << endl;
}
void Parque::Cancelar_ruta(Ruta rutas){

    for(vector<Ruta>::iterator it = rutas_.begin(); it != rutas_.end();it++){
        if(it->getNumeroruta() == rutas.getNumeroruta()){
            rutas_.erase(it);
            cout << "La ruta ha sido cancelada con exito" << endl;
        }
    }
    cout << "No se ha encontrado la ruta que se querias borrar" << endl;
}
//datos
//seleccionar_ruta
//seleccionar_sendero
