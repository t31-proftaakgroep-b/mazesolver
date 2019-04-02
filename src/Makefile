CXXFLAGS=-Wall -Werror -pedantic -ggdb -O0 -std=c++11 -Iproduct
#we are using C++11 because TinyXMLm uses a 'long long' type and C++ 98 does not support this

SERVER_SOURCES=$(wildcard Server/*.cpp)
SERVER_HEADERS=$(wildcard Server/*.h)

SERVER_OBJECTS=$(SERVER_SOURCES:.cpp=.o)

CLIENT_SOURCES=$(wildcard Client/*.cpp)
CLIENT_HEADERS=$(wildcard Client/*.h)

CLIENT_OBJECTS=$(CLIENT_SOURCES:.cpp=.o)

HEADERS=$(wildcard *.h)

SERVER_TARGET=server
CLIENT_TARGET=client

CXX=g++

.PHONY: all clean

all: $(SERVER_TARGET) $(CLIENT_TARGET)

$(SERVER_TARGET): $(SERVER_SOURCES) $(SERVER_OBJECTS) $(HEADERS)
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ $(SERVER_SOURCES)


$(CLIENT_TARGET): $(CLIENT_SOURCES) $(CLIENT_OBJECTS) $(HEADERS)
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ $(CLIENT_SOURCES)


clean:
	@rm -f $(SERVER_TARGET) $(CLIENT_TARGET) ./*/*.o
