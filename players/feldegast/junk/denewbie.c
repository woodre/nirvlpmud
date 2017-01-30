#include "defs.h"
id(str) { return str=="dekrylon"; }
short() { return "An evil looking device"; }
long() { write("It looks evil.\n"); }
get() { return 0;}
init() {
  if(this_player()->query_level() == 1 &&
    query_ip_number(this_player())=="24.95.212.214")
    {
    write("You may not create a new character at this time.\n");
    destruct(this_player());
  }
}
