 # the compiler: gcc for C program, define as g++ for C++
  CC = c99

  # compiler flags:
  #  -g    adds debugging information to the executable file
  #  -Wall turns on most, but not all, compiler warnings
  CFLAGS  = -I

  # the build target executable:
  TARGET = IPAnalyser

IPAnalyser: analyser.c main.c
	$(CC) -o IPAnalyser main.c analyser.c -I.

all: $(TARGET)

clean:
	$(RM) $(TARGET)