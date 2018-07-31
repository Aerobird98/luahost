#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
#include "stdio.h"

//a custom c function for lua
int ltestf(lua_State *l) {
  printf("%s\n","host says: test function called.");
  //push a boolean value in the stack. stack: [<args>, true]
  lua_pushboolean(l,1);
  //the number of values (in the stack) seen by lua as return values
  return 1;
};
//a custom c library of functions callable from lua
int luaopen_test(lua_State *l) {
  luaL_Reg fns[] = {
    {"testf",ltestf},
    //the last element here needs to be {NULL,NULL}
    {NULL,NULL}
  };
  //creates a new libtable and sets all functions from the given list
  luaL_newlib(l,fns);
  return 1;
};

int main() {
  //create a new lua state
  lua_State *l = luaL_newstate();
  //open all stdlibs for this state
  //luaL_openlibs(l);
  //open just the base functions this state
  luaopen_base(l);
  //open our custom libtable
  luaopen_test(l);
  //and set a global for it
  lua_setglobal(l,"test");
  //do a lua file in this state
  int e = luaL_dofile(l,"test.lua");
  //print error messages in case of errors
  if (e) { fprintf(stderr,"%s\n",lua_tostring(l,-1)); };
  return 0;
};
