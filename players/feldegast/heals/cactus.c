#include "defs.h"

inherit HEAL;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("cactus");
  add_alias("plant");
  add_alias("meat");
  set_short(HIG+"Cactus meat"+NORM);
  set_long("This is a chunk of what appears to be cactus.  It's not very\n"+
           "tasty, but with all the thorns gone it is edible.\n");
  set_type("pieces");
  set_msg("You eat a slice of cactus and decide you could get to like it.\n");
  set_msg2(" eats some cactus.\n");
  add_cmd("eat");
  add_cmd("chew");
  add_cmd("injest");
  set_heal(50,50);
  set_charges(2);
  set_stuff(12);
  set_value(600);
}
