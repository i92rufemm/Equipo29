/*
 * Cliente.h
 *
 *  Created on: 9 dic. 2020
 *      Author: Victor Rojas Munoz
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
#include <iostream>
#include <string>
using namespace std;

class Cliente{
private:
	string Nombre_;
	string Apellidos_;
	float Fecha_;
	string DNI_;
	string Correo_;
	string Discapacidad_;

public:
	Cliente();
	void setNombre();
	string getNombre();
	string setApellidos();
	void getApellidos();
	float setFecha();
	void getFecha();
	string setDNI();
	void getDNI();
	string setCorreo();
	void getCorreo();
	string setDiscapacidad();
	void getDiscapacidad();
};




#endif /* CLIENTE_H_ */