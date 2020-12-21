#include <fstream>
#include <list>
#include "Cliente.h"
#include "gtest/gtest.h"

using namespace std;

TEST(Cliente, ConstructorParametrosDefecto) {
  Cliente m;

  EXPECT_EQ("0", m.getNombre());
  EXPECT_EQ("0", m.getApellidos());
  EXPECT_EQ("0", m.getDNI());
  EXPECT_EQ("0", m.getDiscapacidad());
  EXPECT_EQ("0", m.getCorreo());
  EXPECT_EQ(0, m.getFecha().dia);
  EXPECT_EQ(0, m.getFecha().mes);
  EXPECT_EQ(0, m.getFecha().anio);
}


TEST(Cliente, ConstructorParametros) {
  Cliente m("Adolfo", "Martinez Carrasco",  10, 2, 1996 ,"52457878V","adolfin_Carrasquito@gmail.com", "Requiere de muletas para andar");

  EXPECT_EQ("Adolfo", m.getNombre());
  EXPECT_EQ("Martinez Carrasco", m.getApellidos());
  EXPECT_EQ("52457878V", m.getDNI());
  EXPECT_EQ("adolfin_Carrasquito@gmail.com", m.getCorreo());
  EXPECT_EQ("Requiere de muletas para andar", m.getDiscapacidad());
  EXPECT_EQ(10, m.getFecha().dia);
  EXPECT_EQ(2, m.getFecha().mes);
  EXPECT_EQ(1996, m.getFecha().anio);
}

TEST(Cliente, setNombre) {
  Cliente m("Valdomero");

  EXPECT_EQ("Valdomero", m.getNombre());
  m.setNombre("Jacobo");
  EXPECT_EQ("Jacobo", m.getNombre());
}