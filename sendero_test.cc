#include <fstream>
#include <list>
#include "sendero.h"
#include "parque.h"
#include "gtest/gtest.h"

using namespace std;

TEST(Sendero, ConstructorParametrosDefecto) {

    Parque p1("chupilandia");
    Sendero s("a1",p1);

    EXPECT_EQ("a1", s.getCodigo());
    EXPECT_EQ("chupilandia", (s.getParque().getNombre()) );
    EXPECT_EQ("", s.getDificultad());
    EXPECT_EQ("", s.getDisponibilidad());
    EXPECT_EQ(0.0, s.getLongitud());

}


TEST(Sendero, ConstructorParametros) {

    Parque p1("chupilandia");

    Sendero s("a1",p1,"basica","abierto",2.57);

    EXPECT_EQ("a1", s.getCodigo());
    EXPECT_EQ("chupilandia", (s.getParque().getNombre()) );
    EXPECT_EQ("basica", s.getDificultad());
    EXPECT_EQ("abierto", s.getDisponibilidad());
    EXPECT_EQ(2.57, s.getLongitud());

}

