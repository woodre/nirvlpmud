#include "defs.h"

inherit "/obj/monster.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_short("Sheep");
  set_name("sheep");
  set_long(
    "This is a bizarre creature.  Short, with black features and a fluffy\n"+
    "cloud-like shape, perhaps camouflage in its native habitat.  It gives\n"+
    "off a repulsive smell, perhaps as part of some sort of natural defense.\n"
  );
  set_level(2);
  set_wc(6);
  set_ac(3);
  set_hp(30);
  load_chat("Sheep says: Baaaaaaaa!\n");
  set_dead_ob(this_object());
}

monster_died(ob) {
  int value;
  value=random(180);
  write("You shear the dead sheep and sell the wool at market for "+value+" coins.\n");
  this_player()->add_money(value);
}
