CC=gcc
IN=main.c ipfuncs.c calcfuncs.c 
OUT=nethelper
ARGS_OUT=-o
ARGS_LIB=-lm

all: build

build:

	$(CC) $(IN) $(ARGS_OUT) $(OUT) $(ARGS_LIB)
