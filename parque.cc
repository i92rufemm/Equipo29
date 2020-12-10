
#include "parque.h"
using namespace std;

Parque::Parque(string nombreparque,float superficie,float ubicacion,string localizacion)
{
    setNombre(nombreparque);
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
    for (vector<Ruta>iterator::it = rutas_.begin();it != rutas_.end();it++){
        if(it->getNumero() == numrut){
            return it;
        }
    }    
}
Sendero Parque::Seleccionar_sendero(){
    string codigo;
    cout << "Dime el codigo del sendero que quieres seleccionar" << endl;
    getline(cin,codigo);
    for (vector<Sendero>iterator::it = senderos_.begin(); it != senderos_.end(); it++)
    {
        if(it->getCodigo == codigo){
            return it;
        }
    }    
}
