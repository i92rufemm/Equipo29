/*
 * Cliente.h
 *
 *  Created on: 9 dic. 2020
 *      Author: Victor Rojas Munoz
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
#include "estructuas.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Cliente{
private:
	string Nombre_;
	string Apellidos_;
	float Fecha_;
	string DNI_;
	string Correo_;
	string Discapacidad_;

public:
	Monitor(string Nombre_="\0";
            string Apellidos="\0";
            Fecha Fecha_;
            string DNI_="\0";
            string Correo_="\0";
            string Discapacidad="\0";)
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
	void setDiscapacidad(int Discapacidad){Discapacidad_=Discapacidad;}
	string getDiscapacidad()const{return Discapacidad_;}
};




#endif /* CLIENTE_H_ */