#include "defs.h"

inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("rabbit");
  set_alt_name("bunny");
  set_short("A bunny rabbit");
  set_long(
    "This is a cute furry wittle bunny rabbit.\n"
  );
  set_gender("male");
  set_race("critter");
  set_level(1);
  set_wc(5);
  set_ac(3);
  set_hp(15);
  set_al(-350);
  set_chat_chance(5);
  load_chat("The bunny rabbit looks VERY confused.\n");
}
