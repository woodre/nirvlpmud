#include "/players/feldegast/defines.h"

inherit "obj/weapon.c";

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("battleaxe");
  set_alias("axe");
  set_short("Silver Battleaxe");
  set_long(
    "This is a finely made double-bladed axe with a two foot long\n"+
    "handle and a prominent spike on either end.\n"
  );
  set_type("axe");
  set_class(17);
  set_weight(5);
  set_read("You interpret the runes on the battleaxe:\n"+
           "Fire be upon ye should ye fail your liege.\n");
  set_value(1500);
  set_hit_func(this_object());
}

