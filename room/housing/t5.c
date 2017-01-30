#include "defs.h"

inherit LAND;

void reset(status arg) {

  if (arg)
  {
    ::reset(arg);
    return;
  }

  set_cost(10000000);
  set_realm_name("Testing Area");
  set_lot_size("-2");
  short_desc = "Player Housing System Test Room";
  long_desc = "This is a testing room.  Fear this shit.\n";
  ::reset(arg);
}
void init() {
"/players/earwax/housing/land_daemon.c"->dump_list(this_player(), "all");
}
