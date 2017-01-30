#include "defs.h"

inherit "/obj/weapon.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("battleaxe");
  set_short(BOLD+BLK+"Black axe"+NORM);
  set_alias("black axe");
  set_type("axe");
  set_long(
    "This is a double-edged battleaxe with a haft approximately one\n"+
    "meter long.  The blade is a dull charcoal black in hue, and the\n"+
    "wood of the haft is made out of darkwood.\n"
  );
  set_class(18);
  set_weight(4);
  set_value(2000);
  set_hit_func(this_object());
}

weapon_hit(attacker) {
  if(TP && TP->query_alignment() > 400) {
    if(!random(4))
      write("You find the inherent evil of your weapon disconcerting.\n");
    return -4;
  }
  /* But at least it LOOKS good! */
  if(!random(5)) {
    write("\nYou strike "+attacker->query_name()+" a mighty blow with the Black Axe.\n\n");
  }
  if(!random(5)) {
    write("\nYou sweap the mighty battleaxe about your body.\n\n");
  }
}

