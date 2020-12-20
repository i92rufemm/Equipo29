/*
 * Monitor.cc
 *
 *  Created on: 8 dic. 2020
 *      Author: Victor Rojas Munoz
 */

#include "Monitor.h"
using namespace std;

Monitor:: Monitor(string Nombre, string Apellidos, string DNI, int dia, int mes, int anio ,string Correo, int Telefono){
	setNombre(Nombre);
	setApellidos(Apellidos);
	setDNI(DNI);
	setCorreo(Correo);
	setTelefono(Telefono);
}

void Monitor:: setFechas(vector <Fecha> ListaFecha_, int count){
	int dia;
	int mes;
	int anio;
	int aux;
	
	cout<<"\nIntroducir dia\n";
	cin>>dia;
	cout<<"\nIntroducir mes\n";
	cin>>mes;
	cout<<"\nIntroducir anio\n";
	cin>>anio;

	ListaFecha_.push_back(Fecha());
	ListaFecha_[count].dia=dia;
	ListaFecha_[count].mes=mes;
	ListaFecha_[count].anio=anio;

	for(int j=0; j<count-1; j++){
			for (int k=j+1; k<count; k++){
				if(ListaFecha_[j].anio>ListaFecha_[k].anio){
					aux=ListaFecha_[j].anio;
					ListaFecha_[j].anio=ListaFecha_[k].anio;
					ListaFecha_[k].anio=aux;
					aux=ListaFecha_[j].mes;
					ListaFecha_[j].mes=ListaFecha_[k].mes;
					ListaFecha_[k].mes=aux;
					aux=ListaFecha_[j].dia;
					ListaFecha_[j].dia=ListaFecha_[k].dia;
					ListaFecha_[k].dia=aux;	
				}
				else {
					if(ListaFecha_[j].anio==ListaFecha_[k].anio && ListaFecha_[j].mes>ListaFecha_[j].mes){
						aux=ListaFecha_[j].anio;
						ListaFecha_[j].anio=ListaFecha_[k].anio;
						ListaFecha_[k].anio=aux;
						aux=ListaFecha_[j].mes;
						ListaFecha_[j].mes=ListaFecha_[k].mes;
						ListaFecha_[k].mes=aux;
						aux=ListaFecha_[j].dia;
						ListaFecha_[j].dia=ListaFecha_[k].dia;
						ListaFecha_[k].dia=aux;
					} 
				else {
					if (ListaFecha_[j].anio==ListaFecha_[k].anio && ListaFecha_[j].mes==ListaFecha_[j].mes && ListaFecha_[j].dia>ListaFecha_[k].dia){
						aux=ListaFecha_[j].anio;
						ListaFecha_[j].anio=ListaFecha_[k].anio;
						ListaFecha_[k].anio=aux;
						aux=ListaFecha_[j].mes;
						ListaFecha_[j].mes=ListaFecha_[k].mes;
						ListaFecha_[k].mes=aux;
						aux=ListaFecha_[j].dia;
						ListaFecha_[j].dia=ListaFecha_[k].dia;
						ListaFecha_[k].dia=aux;
					}
				}
				}
			}
		}
}

void Monitor:: setFecha(int dia,int mes, int anio){
	fecha_.dia=dia;
	fecha_.mes=mes;
	fecha_.anio=anio;
}
