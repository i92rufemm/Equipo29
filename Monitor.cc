/*
 * Monitor.cc
 *
 *  Created on: 8 dic. 2020
 *      Author: Victor Rojas Munoz
 */

#include "Monitor.h"
using namespace std;


Monitor:: Monitor(){
	Nombre_='0';
	Apellidos_= '0';
	Fecha_= 0;
	DNI_= '0';
	Correo_= '0';
	Telefono_=0;
}

//Inicializo los valores de la estructuera monitor


string Monitor::setNombre(){
	cout<<"Nombre: ";
	cin>>Nombre_;
} //Funcion para introducir el nombre


void Monitor::getNombre(){
	cout<<"Nombre: "<<Nombre_<<"\n";
} //Funcion para obtener el nombre del Monitor seleccionado


string Monitor::setApellidos(){
	cout<<"Apellidos: ";
	cin>>Apellidos_;
} //Funcion para introducir apellidos del monitor 


void Monitor::getApellidos(){
	cout<<"Apellidos: "<<Apellidos_<<"\n";
} //Funcion para obtener los apellidos del Monitor seleccionado

float Monitor::setFecha(){
	cout<<"Fecha: ";
	cin>>Fecha_;
}

void Monitor::getFecha(){
	cout<<"Fecha :"<<Fecha_<<"\n";
}

string Monitor::setDNI(){
	cout<<"DNI: ";
	cin>>DNI_;
}

void Monitor::getDNI(){
	cout<<"DNI: "<<DNI_<<"\n";
}

string Monitor::setCorreo(){
	cout<<"Correo electronico: ";
	cin>>Correo_;
}

void Monitor::getCorreo(){
	cout<<"Correo electronico: "<<Correo_<<"\n";
}

int Monitor::setTelefono(){
	cout<<"Telefono: ";
	cin>>Telefono_;
}

void Monitor::getTelefono(){
	cout<<"Telefono: "<<Telefono_<<"\n";
}
