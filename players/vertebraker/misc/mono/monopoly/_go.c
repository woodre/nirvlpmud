#include "path.h"
inherit SQUARE;

reset() {
  name="Go";
  long_desc="Collect "+MONEYSIGN+"200.00 Salary as you pass.\n"
           +"--> Type 'west' to leave";
}

init() {
  add_action("out","west");
  ::init();
}

out(arg) {
  if(arg) return 0;
  TP->move_player("the board#"+PATH+"/main");
  return 1;
}

bounce(i) {
  ::bounce(i);
  if(i==1) return;  /* get money on land() */
  write("++You get "+MS+"200 for passing go.\n");
  SHOUT("--"+NAME+" gets "+MS+"200 for passing go.\n");
  TPMOBJ->add_cash(200);
}

land() {
  ::land();
#ifdef LAND_GO
  write("++You get "+MS+LAND_GO+" for landing on go.\n");
  SHOUT("--"+NAME+" gets "+MS+LAND_GO+" for passing go.\n");
  TPMOBJ->add_cash(LAND_GO);
#else
  write("++You get "+MS+"200 for landing on go.\n");
  SHOUT("--"+NAME+" gets "+MS+"200 for passing go.\n");
  TPMOBJ->add_cash(200);
#endif
}
