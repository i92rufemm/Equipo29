#include <fstream>
#include <list>
#include "Monitor.h"
#include "sendero.h"
#include "Cliente.h"
#include "ruta.h"
#include "gtest/gtest.h"

using namespace std;

TEST( Ruta, aniadir_cliente){

    Monitor m;
    Ruta r(1, m);
    r.setAforo(2);
    Cliente c1("Marcos");
    Cliente c2("Arturo");
    Cliente c3("Antonio");

    c1.setDNI("548C");
    c2.setDNI("748C");
    c3.setDNI("648C");


     EXPECT_EQ(1, r.addCliente(c1) );
     EXPECT_EQ(-2, r.addCliente(c1));
     EXPECT_EQ(1, r.addCliente(c2) );
     EXPECT_EQ(-1, r.addCliente(c3) );

    EXPECT_EQ("Marcos", ( (r.getClientes())[0] ).getNombre()  );
    EXPECT_EQ("Arturo", ( (r.getClientes())[1] ).getNombre()  );


}


TEST( Ruta, Borrar_cliente){

    Monitor m;
    Ruta r(1, m);
    r.setAforo(2);
    
    Cliente c1("Marcos");
    Cliente c3("Antonio");

    c1.setDNI("548C");
    c3.setDNI("648C");

     EXPECT_EQ(-1, r.deleteCliente(c3) );

    r.addCliente(c1);
    r.addCliente(c3);

     EXPECT_EQ(1, r.deleteCliente(c1) );
     EXPECT_EQ(-2, r.deleteCliente(c1));
     EXPECT_EQ(1, r.deleteCliente(c3) );

    

    EXPECT_TRUE( r.getClientes().empty() );



}