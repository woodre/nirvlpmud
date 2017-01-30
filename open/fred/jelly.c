#include "/players/fred/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("jelly");
  add_alias("jar");
  set_short(BOLD+MAG+"Grape Jelly"+NORM);
  set_long("A small jar of delicious grape jelly that would\n"+
           "be great to 'eat'.\n");
  set_type("scoop");
  set_msg("You scoop some of the jelly out of the jar and stuff it\n"+
          "in your mouth.\n");
  set_msg2(" eats a glob of grape jelly from the jar.\n");
  add_cmd("eat");
  set_heal(0,50);
  set_charges(3);
  set_soak(7);
  set_stuff(7);
  set_value(400);
}

query_save_flag(){
  return 1;
  }
