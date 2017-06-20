CC = gcc

SRC = sli.c
OUT = sli

LUA_DIR = /usr/local
LUA_LIB = $(LUA_DIR)/lib
LUA_INC = $(LUA_DIR)/include
LUA_LIBRARY = lua

CFLAGS = -o$(OUT) -I$(LUA_INC) -L$(LUA_LIB) -l$(LUA_LIBRARY) -lm -ldl

linux:
	$(CC) $(SRC) $(CFLAGS)