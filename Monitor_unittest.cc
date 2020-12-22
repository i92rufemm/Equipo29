#include <fstream>
#include <list>
#include "Monitor.h"
#include "gtest/gtest.h"

using namespace std;

TEST(Monitor, ConstructorParametrosDefecto) {
  Monitor m;

  EXPECT_EQ("0", m.getNombre());
  EXPECT_EQ("0", m.getApellidos());
  EXPECT_EQ("0", m.getDNI());
  EXPECT_EQ("0", m.getCorreo());
  EXPECT_EQ(0, m.getTelefono());
  EXPECT_EQ(0, m.getFecha().dia);
  EXPECT_EQ(0, m.getFecha().mes);
  EXPECT_EQ(0, m.getFecha().anio);
}


TEST(Monitor, ConstructorParametros) {
  Monitor m("Adolfo", "Martinez Carrasco", "52457878V", 10, 2, 1996 ,"adolfin_Carrasquito@gmail.com", 603847586);

  EXPECT_EQ("Adolfo", m.getNombre());
  EXPECT_EQ("Martinez Carrasco", m.getApellidos());
  EXPECT_EQ("52457878V", m.getDNI());
  EXPECT_EQ("adolfin_Carrasquito@gmail.com", m.getCorreo());
  EXPECT_EQ(603847586, m.getTelefono());
  EXPECT_EQ(10, m.getFecha().dia);
  EXPECT_EQ(2, m.getFecha().mes);
  EXPECT_EQ(1996, m.getFecha().anio);
}

TEST(Monitor, setNombre) {
  Monitor m("Valdomero");

  EXPECT_EQ("Valdomero", m.getNombre());
  m.setNombre("Jacobo");
  EXPECT_EQ("Jacobo", m.getNombre());
}