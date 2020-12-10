/*
 * Monitor.cc
 *
 *  Created on: 8 dic. 2020
 *      Author: Victor Rojas Munoz
 */

#include "Monitor.h"
#include "estructuras.h"
using namespace std;

Fecha:: Fecha(int dia_, int mes_n int anio_){
    dia=dia_;
    mes=mes_;
    anio=anio_;
}

Monitor:: Monitor(string Nombre, string Apellidos, Fecha Fecha, string DNI, string Correo, int Telefono){
	setNombre(Nombre);
	setApellidos(Apellidos);
	setFecha(Fecha);
	setDNI(DNI);
	SetCorreo(Correo);
	SetTelefono(Telefono);
}

