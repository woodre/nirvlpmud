#include "defs.h"

inherit "/obj/weapon.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("fortitude");
  set_short("Fortitude the Broadsword");
  set_alias("broadsword");
  set_long(
    "This is a magnificent broadsword with a silvery blade and a gold\n"+
    "cross-piece.  The word FORTITUDE is etched on the blade.\n"
  );
  set_type("sword");
  set_class(17);
  set_weight(3);
  set_value(1000);
}

add_wear(x) { return; }

count_misses() { return 1; }
count_hit_made() { return 1; }
