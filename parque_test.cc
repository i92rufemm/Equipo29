#include <fstream>
#include <list>
#include <vector>
#include "parque.h"
#include "gtest/gtest.h"

using namespace std;

TEST(Parque, Seleccionar_cliente){

    Parque p1("chupilandia");

    Cliente c1("Ramiro","Martinez Carrasco",  10, 2, 1996 ,"52457878V");
    Cliente c2("Manolo","Ortiz Carrasco",  22, 4, 1978 ,"89541465B");
    Cliente c3("Jesus","Martinez Ortiz",  25, 12, 1987 ,"78788954Y");

    p1.AddCliente(c1);
    p1.AddCliente(c2);
    p1.AddCliente(c3);


    EXPECT_EQ("Ramiro",( (p1.Seleccionar_cliente("52457878V")).getNombre() ));

    EXPECT_EQ("Manolo", (p1.Seleccionar_cliente("89541465B") ).getNombre());

    EXPECT_EQ("Jesus", (p1.Seleccionar_cliente("78788954Y") ).getNombre());


}