CXX=c++
CXX_FLAG=-std=c++11 -o log

build:
	${CXX} src/*.cpp ${CXX_LIBS} ${CXX_FLAG} ${CXX_INC}

lib:

test:

