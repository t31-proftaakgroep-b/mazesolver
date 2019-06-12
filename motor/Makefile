CFLAGS=-Wall -Werror -ggdb -O0 -Iproduct -O3 -pipe -fomit-frame-pointer -funroll-all-loops -s
PRODUCT=printer

MOTOR_SOURCES=*.cpp

TEST_LIBS=
#-lgtest -lgtest_main -pthread

GCC=g++
GCC_arm=arm-linux-gnueabi-g++

all: printer_arm upload


printer: $(MOTOR_SOURCES) Makefile *.h
	@$(GCC) $(CFLAGS) $(MOTOR_SOURCES) $(TEST_LIBS) -o $@

printer_arm: $(MOTOR_SOURCES) Makefile *.h
	@$(GCC_arm) $(CFLAGS) $(MOTOR_SOURCES) $(TEST_LIBS) -o $(PRODUCT)

upload:
	scp $(PRODUCT) dev:/home/robot/$(PRODUCT)
	ssh dev './$(PRODUCT)'
	
clean:
	rm $(PRODUCT)
	ssh dev 'rm -rf ./$(PRODUCT)'

