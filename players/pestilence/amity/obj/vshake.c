inherit "/obj/generic_heal.c";
#include "/players/pestilence/ansi.h"

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("a large"+WHT+" vanilla milkshake"+NORM+"");
  add_alias("vanilla milkshake");
  add_alias("milkshake");
  add_alias("large");
  add_alias("large vanilla milkshake");
  add_alias("shake");
  set_short("a large"+WHT+" vanilla milkshake"+NORM+"");
  set_long("This is a large"+WHT+" vanilla milkshake"+NORM+".\n"+
           "The milkshake looks like it would be very refreshing to drink.\n");    
  set_type("sips");
  set_msg("You take a big gulp of the "+WHT+"vanilla milkshake"+NORM+".\n");
  set_msg2(" takes a big gulp of the "+WHT+"vanilla milkshake"+NORM+".\n");
  add_cmd("drink");
  add_cmd("gulp");
  add_cmd("sip");
  set_heal(50,50);
  set_charges(3);
  set_stuff(7);
  set_soak(7);
  set_value(600);
}

query_save_flag(){
  return 1;
  }
