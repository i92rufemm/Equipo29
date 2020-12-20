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
#include <vector>
using namespace std;

class Monitor{
private:
	string Nombre_;
	string Apellidos_;
	string DNI_;
	string Correo_;
	int Telefono_;
	struct Fecha Fecha_;
	vector <Fecha> ListaFecha_;
	int count_;

public:
	Monitor(string Nombre_="0", string Apellidos="0", string DNI_="0", int dia = 0, int mes = 0, int anio = 0, string Correo_="0", 
			int Telefono = 0);
	inline void setNombre(string Nombre){Nombre_=Nombre;}
	inline string getNombre()const{return Nombre_;}
	inline void setApellidos(string Apellidos){Apellidos_=Apellidos;}
	inline string getApellidos()const{return Apellidos_;}
	void setFechaN(Fecha);//Ahora cuando averigue como funciona la pongo
	Fecha getFechaN()const{return Fecha_;}
	inline void setDNI(string DNI){DNI_=DNI;}
	inline string getDNI()const{return DNI_;}
	inline void setCorreo(string Correo){Correo_=Correo;}
	inline string getCorreo()const{return Correo_;}
	inline void setTelefono(int Telefono){Telefono_=Telefono;}
	inline int getTelefono()const{return Telefono_ ;}
    void setFechas(vector <Fecha> ListaFecha_, int count);
	inline vector <Fecha> getFechas(){return ListaFecha_;}
	void setFecha(Fecha Fecha_, int dia, int mes, int anio);
	inline Fecha getFecha(){return Fecha_;}
};




#endif /* MONITOR_H_ */
