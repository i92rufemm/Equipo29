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
using namespace std;

class Monitor{
private:
	string Nombre_;
	string Apellidos_;
	float Fecha_;
	string DNI_;
	string Correo_;
	int Telefono_;

public:
	Monitor();
	string setNombre();
	void getNombre();
	string setApellidos();
	void getApellidos();
	float setFecha();
	void getFecha();
	string setDNI();
	void getDNI();
	string setCorreo();
	void getCorreo();
	int setTelefono();
	void getTelefono();
};




#endif /* MONITOR_H_ */
