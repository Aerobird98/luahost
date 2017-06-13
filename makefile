CC = gcc

SRC = sli.c
OUT = sli

LUA_DIR = f:/lua
LUA_BIN = $(LUA_DIR)/bin
LUA_INC = $(LUA_DIR)/include
LUA_DLL = lua53

CFLAGS = -o$(OUT) -I$(LUA_INC) -L$(LUA_BIN) -l$(LUA_DLL)

build:
	$(CC) $(SRC) $(CFLAGS)
