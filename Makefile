GTEST_DIR = https://github.com/i92rufemm/Equipo29/googletest-release-1.8.1/googletest

CPPFLAGS += -isystem $(GTEST_DIR)/include
CXXFLAGS += -g -Wall -pthread -std=gnu++11
TESTS = contador_unittest
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h
all : $(TESTS)

clean :
	rm -f $(TESTS) gtest.a gtest_main.a *.o
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)
gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

monitor.o: Monitor.h Monitor.cc
cliente.o: Cliente.h Cliente.cc
parque.o: parque.h parque.cc
ruta.o: ruta.h ruta.cpp
sendero.o: sendero.h sendero.cc

monitor_test.o: monitor_test.cc Monitor.h Monitor.cc Cliente.h Cliente.cc parque.h parque.cc ruta.h ruta.cpp sendero.h sendero.cc
cliente_test.o: cliente_test.cc Monitor.h Monitor.cc Cliente.h Cliente.cc parque.h parque.cc ruta.h ruta.cpp sendero.h sendero.cc
parque_test.o: parque_test.cc Monitor.h Monitor.cc Cliente.h Cliente.cc parque.h parque.cc ruta.h ruta.cpp sendero.h sendero.cc
sendero_test.o: sendero_test.cc Monitor.h Monitor.cc Cliente.h Cliente.cc parque.h parque.cc ruta.h ruta.cpp sendero.h sendero.cc
ruta_test.o: ruta_test.cc Monitor.h Monitor.cc Cliente.h Cliente.cc parque.h parque.cc ruta.h ruta.cpp sendero.h sendero.cc



monitor_test: monitor.o cliente.o parque.o ruta.o sendero.o monitor_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o $@

cliente_test: monitor.o cliente.o parque.o ruta.o sendero.o cliente_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o $@

parque_test: monitor.o cliente.o parque.o ruta.o sendero.o parque_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o $@

sendero_test: monitor.o cliente.o parque.o ruta.o sendero.o sendero_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o $@

ruta_test: monitor.o cliente.o parque.o ruta.o sendero.o ruta_test.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o $@