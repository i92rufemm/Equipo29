/*
 * Monitor.cc
 *
 *  Created on: 8 dic. 2020
 *      Author: Victor Rojas Munoz
 */

#include "Monitor.h"
#include "estructuras.h"
using namespace std;

Fecha:: Fecha(){
    dia=0;
    mes=0;
    año=0;
}

Monitor:: Monitor(string Monitor, string Apellidos, Fecha Fecha, string DNI, string Correo, int Telefono){
	Nombre_=Nombre;
	Apellidos_= Apellidos;
	Fecha_= Fecha;
	DNI_= DNI;
	Correo_= Correo;
	Telefono_= Telefono;
}

//Inicializo los valores de la estructuera monitor


string Monitor::setNombre(Nombre){
	cout<<"Nombre: ";
	cin>>Nombre_;
    Nombre_=Nombre;
} //Funcion para introducir el nombre de un nuevo Monitor


void Monitor::getNombre(Nombre){
	cout<<"Nombre: "<<Nombre_<<"\n";
} //Funcion para obtener el nombre del Monitor seleccionado


string Monitor::setApellidos(Apellidos){
	cout<<"Apellidos: ";
	cin>>Apellidos_;
    Apellidos_=Apellidos;
} //Funcion para introducir apellidos de un nuevo Monitor 


void Monitor::getApellidos(Apellidos){
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


string Monitor::setDNI(DNI){
	cout<<"DNI: ";
	cin>>DNI_;
    DNI_=DNI;
} //Funcion para introducir el DNI de un nuevo Monitor


void Monitor::getDNI(DNI){
	cout<<"DNI: "<<DNI_<<"\n";
} //Funcion para obtener el DNI del Monitor seleccionado


string Monitor::setCorreo(Correo){
	cout<<"Correo electronico: ";
	cin>>Correo_;
    Correo_=Correo;
} //Funcion para introducir el correo electronico de un nuevo Monitor


void Monitor::getCorreo(Correo){
	cout<<"Correo electronico: "<<Correo_<<"\n";
} //Funcion para obtener el correo electronico del Monitor seleccionado


int Monitor::setTelefono(Telefono){
	cout<<"Telefono: ";
	cin>>Telefono_;
    Telefono_=Telefono;
} //Funcion para introducir el numero de telefono de un nuevo Monitor


void Monitor::getTelefono(Telefono){
	cout<<"Telefono: "<<Telefono_<<"\n";
} //Funcion para obtener el numero de Telefono del monitor seleccionado
