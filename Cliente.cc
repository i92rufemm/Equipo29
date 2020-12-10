/*
 * Cliente.cc
 *
 *  Created on: 9 dic. 2020
 *      Author: Victor Rojas Muñoz
 */

#include "Cliente.h"
#include "estructuras.h"
using namespace std;

Cliente::Cliente(string Nombre, string Apellidos, Fecha Fecha, string DNI, ){
	setNombre(Nombre);
	setApellidos(Apellidos);
	setFechaN(Fecha);
	setDNI(DNI);
	SetCorreo(Correo);
	SetDiscapacidad(Discapacidad);
}


