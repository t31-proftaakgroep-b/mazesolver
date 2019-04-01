STRUCT_DIR= ../struct

CFLAGS=-Wall -Werror -Wextra -pedantic -std=gnu++11 -ggdb -O0 -I$(STRUCT_DIR) -Isrc -pthread #-static -pthread

#HOST=192.168.0.191

OUTPUT=hello

SOURCES=$(wildcard src/*.cpp)
HEADERS=$(wildcard src/*.h) $(STRUCT_DIR)/Structs.h

UPLOAD=sshpass -pmaker scp $(OUTPUT) robot@$(HOST):/home/robot/
SSH=sshpass -pmaker ssh robot@$(HOST) ./$(OUTPUT)

GCC=g++

all: clean server scanner plotter

server: $(SOURCES) $(HEADERS) Makefile
	@$(GCC) $(CFLAGS) $(SOURCES) src/server/server.cpp -o server

scanner: $(SOURCES) $(HEADERS) Makefile
	@$(GCC) $(CFLAGS) $(SOURCES) src/scanner/scanner_main.cpp -o scanner

plotter: $(SOURCES) $(HEADERS) Makefile
	@$(GCC) $(CFLAGS) $(SOURCES) src/plotter/plotter_main.cpp -o plotter

clean:
	@rm -rf scanner plotter server

run:
	@$(SSH)

compile: $(SOURCES) $(HEADERS) Makefile
	@$(GCC) $(CFLAGS) $(SOURCES) -o $(OUTPUT)

upload: hello
	@echo Uploading...
	@$(UPLOAD)
	@echo Done uploading
