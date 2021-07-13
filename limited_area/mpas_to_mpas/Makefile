.SUFFIXES: .cpp .c .o

OBJS = main.o timer_newer.o RemapperBase.o RemapperCell.o RemapperEdge.o NCFieldBase.o Dictionary.o Queue.o mpas_utils.o interp_utils.o

CXX = g++ -std=c++11 -fopenmp
CXXFLAGS = -I${NETCDF}/include -g
#LDFLAGS = -L${NETCDF}/lib -lnetcdf -lhdf5_hl -lhdf5 -lpnetcdf -lz
LDFLAGS = -L${NETCDF}/lib -lnetcdf

all: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(LDFLAGS) -lrt

main.o: NCField.hpp

clean:
	rm -f a.out $(OBJS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<

.c.o:
	$(CXX) $(CXXFLAGS) -c $<
