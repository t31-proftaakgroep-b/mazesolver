CFLAGS=-Wall -Werror -ggdb -O0 -Iproduct -O3 -pipe -fomit-frame-pointer -funroll-all-loops -s
PRODUCT=printer

MOTOR_SOURCES=*.cpp

TEST_LIBS=
#-lgtest -lgtest_main -pthread

GCC=arm-linux-gnueabi-g++

all: $(PRODUCT)


printer: $(MOTOR_SOURCES) Makefile *.h
	@$(GCC) $(CFLAGS) $(MOTOR_SOURCES) $(TEST_LIBS) -o $@
	scp $(PRODUCT) dev:/home/robot/printer
	ssh dev './printer'
	
clean:	rm $(PRODUCT)

