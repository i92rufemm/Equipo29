/*
 * Cliente.cc
 *
 *  Created on: 9 dic. 2020
 *      Author: Victor Rojas Muñoz
 */

#include "Cliente.h"
using namespace std;

Cliente::Cliente(){
	Nombre_='0';
	Apellidos_= '0';
	Fecha_= 0;
	DNI_= '0';
	Correo_= '0';
	Discapacidad_='0';
}

string Cliente::setNombre(){
	cout<<"Nombre: ";
	cin>>Nombre_;
}

void Cliente::getNombre(){
	cout<<"Nombre: "<<Nombre_<<"\n";
}

string Cliente::setApellidos(){
	cout<<"Apellidos: ";
	cin>>Apellidos_;
}

void Cliente::getApellidos(){
	cout<<"Apellidos: "<<Apellidos_<<"\n";
}

float Cliente::setFecha(){
	cout<<"Fecha: ";
	cin>>Fecha_;
}

void Cliente::getFecha(){
	cout<<"Fecha :"<<Fecha_<<"\n";
}

string Cliente::setDNI(){
	cout<<"DNI: ";
	cin>>DNI_;
}

void Cliente::getDNI(){
	cout<<"DNI: "<<DNI_<<"\n";
}

string Cliente::setCorreo(){
	cout<<"Correo electronico: ";
	cin>>Correo_;
}

void Cliente::getCorreo(){
	cout<<"Correo electronico: "<<Correo_<<"\n";
}

string Cliente::setDiscapacidad(){
	cout<<"Discapacidad: ";
	cin>>Discapacidad_;
}

void Cliente::getDiscapacidad(){
	cout<<"Discapacidad: "<<Discapacidad_<<"\n";
}
