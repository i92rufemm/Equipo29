#include "Cliente.h"
using namespace std;

Cliente::Cliente(string Nombre, string Apellidos,int dia,int mes, int anio, string DNI,string Correo, string Discapacidad){
	setNombre(Nombre);
	setApellidos(Apellidos);
	setDNI(DNI);
	setCorreo(Correo);
	setDiscapacidad(Discapacidad);
}


