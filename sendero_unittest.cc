#include <fstream>
#include <list>
#include "sendero.h"
#include "gtest/gtest.h"

using namespace std;

TEST(Sendero, ConstructorParametrosDefecto) {

    Sendero s("a1");

    EXPECT_EQ("a1", s.getCodigo());
    EXPECT_EQ("", s.getDificultad());
    EXPECT_EQ("", s.getDisponibilidad());
    EXPECT_EQ(0.0, s.getLongitud());

}


TEST(Sendero, ConstructorParametros) {


    Sendero s("a1","basica","abierto",2.5);

    EXPECT_EQ("a1", s.getCodigo());
    EXPECT_EQ("basica", s.getDificultad());
    EXPECT_EQ("abierto", s.getDisponibilidad());
    EXPECT_EQ(2.5, s.getLongitud());

}

