/*
 * Monitor.h
 *
 *  Created on: 8 dic. 2020
 *      Author: Victor Rojas Munoz
 */

#ifndef MONITOR_H_
#define MONITOR_H_
#include <iostream>
#include <string>
#include "estructuras.h"
using namespace std;

class Monitor{
private:
	string Nombre_;
	string Apellidos_;
	Fecha Fecha_;
	string DNI_;
	string Correo_;
	int Telefono_;

public:
	Monitor(string Nombre_="\0",
            string Apellidos="\0",
            Fecha Fecha_,
            string DNI_="\0",
            string Correo_="\0",
            int Telefono = 0);
	void setNombre(string Nombre){Nombre_=Nombre;}
	string getNombre()const{return Nombre_;}
	void setApellidos(string Apellidos){Apellidos_=Apellidos;}
	string getApellidos()const{return Apellidos_;}
	void setFechaN(Fecha);//Ahora cuando averigue como funciona la pongo
	Fecha getFechaN()const{return Fecha_;}
	void setDNI(string DNI){DNI_=DNI;}
	string getDNI()const{return DNI_;}
	void setCorreo(string Correo){Correo_=Correo;}
	string getCorreo()const{return Correo_;}
	void setTelefono(int Telefono){Telefono_=Telefono;}
	int getTelefono()const{return Telefono_ ;}
    void setFechas();
    vector <Fecha> getFechas();
};




#endif /* MONITOR_H_ */
