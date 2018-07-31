CC  = gcc
SRC = luahost.c
OUT = luahost

LUA_DIR     = /usr/local
LUA_LIB     = $(LUA_DIR)/lib
LUA_INC     = $(LUA_DIR)/include
LUA_LIBRARY = lua
CFLAGS      = -I$(LUA_INC) -L$(LUA_LIB) -l$(LUA_LIBRARY) -lm -ldl

host:
	$(CC) -o$(OUT) $(SRC) $(CFLAGS)

clean:
	rm -f $(OUT)
