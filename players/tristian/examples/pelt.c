inherit "obj/treasure.c";
#include "/players/linus/def.h"

  id(str) {return str == "pelt" || str == "skin" || str == "bear pelt" || str == "bear skin"; }
reset(arg) {
  if(arg) return;
  set_short("The pelt of a bear");
set_long("This is a bear pelt.");
set_value(1000+(random(501)));
set_weight(2);
}
