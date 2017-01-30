#include "/players/wocket/closed/ansi.h"

 inherit "/players/earwax/housing/land.c";

void reset(status arg) {

  if (arg)
  {
    ::reset(arg);
    return;
  }

  set_cost(50000);
  set_realm_name("Turtleville");
  set_lot_size("5");
  short_desc = HIG+"Player Housing System in Turtleville"+OFF;
  long_desc = "This is a testing room.  Fear this shit.\n";
  ::reset(arg);
}
