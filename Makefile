# Fill this makefile with the makefile format instructions to 
#   build your program.

# Define C compiler & flags
CC = gcc
CFLAGS = -Wall -g
# Define libraries to be linked (for example -lm)
LDLIBS = 

# Define sets of source files and object files

########
SRC = driver.c data.c list.c

# OBJ is the same as SRC, just replace .c with .o
OBJ = $(SRC:.c=.o)
 
# Define the executable name(s)
EXE = dict1

# The first target:
$(EXE): $(OBJ) 
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ) $(LDLIBS)

clean:
	rm -f $(OBJ) $(EXE)
