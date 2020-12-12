/*
 * Monitor.cc
 *
 *  Created on: 8 dic. 2020
 *      Author: Victor Rojas Munoz
 */

#include "Monitor.h"
using namespace std;

Monitor:: Monitor(string Nombre, string Apellidos, Fecha Fecha, string DNI, string Correo, int Telefono, Fecha Fecha){
	setNombre(Nombre);
	setApellidos(Apellidos);
	setFechaN(Fecha);
	setDNI(DNI);
	SetCorreo(Correo);
	SetTelefono(Telefono);
	getFechas();
}

