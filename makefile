CC = g++

CFLAGS =  -Iheader/
LDFLAGS =  

HEADER_DIR = header/
SRC_DIR = src/
OBJ_DIR = obj/

HEADER_FILES = $(HEADER_DIR)*.h
SOURCE_FILES = $(SRC_DIR)*.cpp
OBJ_FILES = $(OBJ_DIR)*.o

EXECUTABLE = baymax-logger

all: $(EXECUTABLE)

$(OBJ_DIR)cmdparser.o: $(SRC_DIR)cmdparser.cpp $(HEADER_DIR)cmdparser.h $(OBJ_DIR)pipeline.o
	$(CC) -c -o $@ $< $(CFLAGS)
    
$(OBJ_DIR)pipeline.o: $(SRC_DIR)pipeline.cpp $(HEADER_DIR)pipeline.h $(OBJ_DIR)cmdparser.o
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ_DIR)main.o: $(SRC_DIR)main.cpp $(HEADER_DIR)main.h $(OBJ_DIR)pipeline.o
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXECUTABLE): $(OBJ_DIR)main.o
	$(CC) $(LDFLAGS) $(OBJ_FILES) -o executable/$(EXECUTABLE)
    

run:
	./executable/$(EXECUTABLE)

debug: $(EXECUTABLE) run
