#include "defs.h"

inherit "/obj/weapon.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("weedslayer");
  set_alias("slayer");
  set_short("Weedslayer");
  set_long(
    "This is a classic example of a botched enchantment.  This fine\n"+
    "silver longsword with its golden hilt and elaborate runes has\n"+
    "been enchanted to slay weeds of all kinds!\n"
  );
  set_type("sword");
  set_class(15);
  set_weight(3);
  set_value(500);
  set_hit_func(this_object());
}

weapon_hit(attacker) {
  if(!random(4) &&
      (attacker->id("plant") || attacker->id("weed"))) {
    write("You weed the "+attacker->query_name()+" with ruthless precision!\n");
    say(TPN+" weeds the "+attacker->query_name()+" with ruthless determination!\n");
    return 5;
  }
}
