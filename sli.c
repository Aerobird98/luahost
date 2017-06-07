#include <stdio.h>
#include <string.h>

#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

int main (int argc, char ** argv) {
  int l_state = 0;

  lua_State *l = luaL_newstate();   /* new lua state */
  luaL_openlibs(l); /* opens std libs for lua */

  int i;
  for (i=1; i<argc; i++) {
    l_state = 1;
    const char *file = argv[i];
    int e = luaL_dofile(l, file);
    if (e) {
      fprintf(stderr, "%s\n", lua_tostring(l, -1));
      lua_pop(l, 1); /* pop error message from the stack */
    }
  }

  if (l_state == 0) {
    fprintf(stdout,"SLI for lua 5.3.4 (Simple Lua Interpreter) by Aerobird98\n");
    char buff[256];
    while (fprintf(stdout,"> ") && fgets(buff, sizeof(buff), stdin) != NULL) {
      int e = luaL_dobuffer(l, buff, strlen(buff) - 1, "=stdin");
      if (e) {
        fprintf(stderr, "%s\n", lua_tostring(l, -1));
        lua_pop(l, 1); /* pop error message from the stack */
      }
    }
  }

  lua_close(l); /* close lua state */
  return 0;
}