PROJECT_HOME=.

#STRUCT_DIR= $(PROJECT_HOME)/Struct

JSON_LIB=$(PROJECT_HOME)/json/include/nlohmann

CFLAGS=-Wall -Werror -Wextra -pedantic -std=gnu++11 -ggdb -O0 -I$(JSON_DIR) #-I$(STRUCT_DIR) -Isrc -static

TEST_LIBS=-lgtest -lgmock -lgtest_main -lpthread

SERVER_SOURCES=$(wildcard server/*.cpp)
SERVER_HEADERS=$(wildcard server/*.h)

SERVER_OBJECTS=$(SERVER_SOURCES:.cpp=.o)

SCANNER_SOURCES=$(wildcard scanner/*.cpp)
SCANNER_HEADERS=$(wildcard scanner/*.h)

SCANNER_OBJECTS=$(SCANNER_SOURCES:.cpp=.o)

PLOTTER_SOURCES=$(wildcard plotter/*.cpp)
PLOTTER_HEADERS=$(wildcard plotter/*.h)

PLOTTER_OBJECTS=$(PLTTER_SOURCES:.cpp=.o)

SERVER_TARGET=server
SCANNER_TARGET=scanner
PLOTTER_TARGET=plotter

GCC-ARM=arm-linux-gnueabi-g++
GCC-x86=g++


all: $(SERVER_TARGET) $(SCANNER_TARGET) $(PLOTTER_TARGET)

$(SERVER_TARGET): $(SERVER_SOURCES) $(SERVER_OBJECTS) $(HEADERS)
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ $(SERVER_SOURCES)


$(SCANNER_TARGET): $(SCANNER_SOURCES) $(SCANNER_OBJECTS) $(HEADERS)
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ $(SCANNER_SOURCES)

$(PLOTTER_TARGET): $(PLOTTER_SOURCES) $(PLOTTER_OBJECTS) $(HEADERS)
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ $(PLOTTER_SOURCES)

clean:
	@rm -f $(SERVER_TARGET) $(SCANNER_TARGET) $(PLOTTER_TARGET) ./*/*.o
