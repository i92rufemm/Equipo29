/*
 * Monitor.cc
 *
 *  Created on: 8 dic. 2020
 *      Author: Victor Rojas Munoz
 */

#include "Monitor.h"
using namespace std;

Monitor:: Monitor(string Nombre, string Apellidos, string DNI, string Correo, int Telefono ){
	setNombre(Nombre);
	setApellidos(Apellidos);
	setDNI(DNI);
	setCorreo(Correo);
	setTelefono(Telefono);
}

void Monitor:: setFechas(vector <Fecha> ListaFecha, int count){
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

	ListaFecha.push_back(Fecha());
	ListaFecha[count].dia=dia;
	ListaFecha[count].mes=mes;
	ListaFecha[count].anio=anio;

	for(int j=0; j<count-1; j++){
			for (int k=j+1; k<count; k++){
				if(ListaFecha[j].anio>ListaFecha[k].anio){
					aux=ListaFecha[j].anio;
					ListaFecha[j].anio=ListaFecha[k].anio;
					ListaFecha[k].anio=aux;
					aux=ListaFecha[j].mes;
					ListaFecha[j].mes=ListaFecha[k].mes;
					ListaFecha[k].mes=aux;
					aux=ListaFecha[j].dia;
					ListaFecha[j].dia=ListaFecha[k].dia;
					ListaFecha[k].dia=aux;	
				}
				else {
					if(ListaFecha[j].anio==ListaFecha[k].anio && ListaFecha[j].mes>ListaFecha[j].mes){
						aux=ListaFecha[j].anio;
						ListaFecha[j].anio=ListaFecha[k].anio;
						ListaFecha[k].anio=aux;
						aux=ListaFecha[j].mes;
						ListaFecha[j].mes=ListaFecha[k].mes;
						ListaFecha[k].mes=aux;
						aux=ListaFecha[j].dia;
						ListaFecha[j].dia=ListaFecha[k].dia;
						ListaFecha[k].dia=aux;
					} 
				else {
					if (ListaFecha[j].anio==ListaFecha[k].anio && ListaFecha[j].mes==ListaFecha[j].mes && ListaFecha[j].dia>ListaFecha[k].dia){
						aux=ListaFecha[j].anio;
						ListaFecha[j].anio=ListaFecha[k].anio;
						ListaFecha[k].anio=aux;
						aux=ListaFecha[j].mes;
						ListaFecha[j].mes=ListaFecha[k].mes;
						ListaFecha[k].mes=aux;
						aux=ListaFecha[j].dia;
						ListaFecha[j].dia=ListaFecha[k].dia;
						ListaFecha[k].dia=aux;
					}
				}
				}
			}
		}
}

vector <Fecha> Monitor:: getFechas(vector <Fecha> ListaFechas, int count){
	for (int i=0; i<count; i++){
		cout<<"\n"<<ListaFechas[i].dia<<"/"<<ListaFechas[i].mes<<"/"<<ListaFechas[i].anio<<"\n";
		}
	return ListaFechas;

}

