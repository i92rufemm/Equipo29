/*
 * Monitor.cc
 *
 *  Created on: 8 dic. 2020
 *      Author: Victor Rojas Munoz
 */

#include "Monitor.h"
#include "estructuras.h"
using namespace std;

Fecha::Fecha(){
    dia=0;
    mes=0;
    año=0;
}

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
} //Funcion para introducir el nombre de un nuevo Monitor


void Monitor::getNombre(){
	cout<<"Nombre: "<<Nombre_<<"\n";
} //Funcion para obtener el nombre del Monitor seleccionado


string Monitor::setApellidos(){
	cout<<"Apellidos: ";
	cin>>Apellidos_;
} //Funcion para introducir apellidos de un nuevo Monitor 


void Monitor::getApellidos(){
	cout<<"Apellidos: "<<Apellidos_<<"\n";
} //Funcion para obtener los apellidos del Monitor seleccionado


float Monitor::setFecha(){
	cout<<"Fecha:\n";
    cout<<"Dia: ";
	cin>>dia;
    cout<<"\nMes: ";
    cin>>mes;
    cout<<"\nAño: ";
    cin>>año;
    cout"\n"
} //Funcion para introducir la fecha de nacimiento de un nuevo Monitor


void Monitor::getFecha(){
	cout<<"Fecha :"<<dia<<":"<<mes<<":"<<año<<"\n";
} //Funcion para obtener la fecha de nacimiento del Monitor seleccionado


string Monitor::setDNI(){
	cout<<"DNI: ";
	cin>>DNI_;
} //Funcion para introducir el DNI de un nuevo Monitor


void Monitor::getDNI(){
	cout<<"DNI: "<<DNI_<<"\n";
} //Funcion para obtener el DNI del Monitor seleccionado


string Monitor::setCorreo(){
	cout<<"Correo electronico: ";
	cin>>Correo_;
} //Funcion para introducir el correo electronico de un nuevo Monitor


void Monitor::getCorreo(){
	cout<<"Correo electronico: "<<Correo_<<"\n";
} //Funcion para obtener el correo electronico del Monitor seleccionado


int Monitor::setTelefono(){
	cout<<"Telefono: ";
	cin>>Telefono_;
} //Funcion para introducir el numero de telefono de un nuevo Monitor


void Monitor::getTelefono(){
	cout<<"Telefono: "<<Telefono_<<"\n";
} //Funcion para obtener el numero de Telefono del monitor seleccionado
