#include "defs.h"

inherit "/obj/weapon.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("reason");
  set_short("Reason the Battleaxe");
  set_alias("battleaxe");
  set_type("axe");
  set_long(
    "Reason is a double-edged battleaxe with a haft about a meter in\n"+
   "length.  The word REASON is etched on the silvery blade.\n");
  set_class(17);
  set_weight(4);
  set_value(1000);
  set_hit_func(this_object());
}

weapon_hit(attacker) {
  if((int)this_player()->query_attrib("int") > (int)attacker->query_attrib("int") && !random(3)) {
    tell_room(environment(TP),TPN+" yells: Listen to "+HIB+"REASON"+NORM+"!\n");
    return random(7);
  }
}
