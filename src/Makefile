
BIN_FOLDER := bin
BINARY := libmatrix
BIN := $(BIN_FOLDER)/$(BINARY) 

OBJ_FOLDER := obj
REPORTS_HOME := reports
CSV_HOME := $(REPORTS_HOME)/csv

SOURCES := core/*.cpp
INCLUDES := -I.
DEFINES := 
LIBS := -lm

OPTI_0 := -g -O0
OPTI_2 := -O2
OPTI := $(OPTI_0)

CXX := g++
CXX_FLAGS := -std=c++11 -Wextra -Wall -Wdeprecated -pedantic

CALLXX := $(CXX) $(CXX_FLAGS) $(DEFINES) $(OPTI)
MOVE_OBJS := mv *.o ../$(OBJ_FOLDER)

##############################################################################
#
##############################################################################
.PHONY: all genesis clean-bin clean-obj clean compile link build run orun crun

all: genesis build run

genesis:;
	mkdir -p ../$(BIN_FOLDER)
	mkdir -p ../$(OBJ_FOLDER)
	mkdir -p ../$(CSV_HOME)

clean-bin:; rm -rf ../$(BIN_FOLDER)
clean-obj:; rm -rf ../$(OBJ_FOLDER)

clean: clean-bin clean-obj

compile:; 
	$(CALLXX) $(INCLUDES) -c $(SOURCES)
	$(MOVE_OBJS)

link:; $(CALLXX) $(INCLUDES) ../$(OBJ_FOLDER)/*.o -o ../$(BIN)
build: compile link

orun:; ../$(BIN)

run: build orun

crun: clean run
