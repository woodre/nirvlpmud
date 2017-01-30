#include "../def.h"
inherit "room/room";
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="Flower Shop";
  long_desc=
"    This lovely little shop is filled to overflowing with flowers\n"+
"of all shapes and sizes grown in a carefully managed garden just\n"+
"outside the city.  It is said that even Lord Byron buys his flowers\n"+
"here for his mistresses.\n";
  items=({
  });
  dest_dir=({

  });
}   
