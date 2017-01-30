inherit "/obj/generic_heal.c";
#include "/players/softly/closed/ansi.h"

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("nut");
  add_alias("Nut");
  add_alias("choc");
  set_short(YEL+"A nut"+NORM);
  set_long("A small brown nut that may help revive you.\n");
  set_type("bites");
  set_msg("You nibble on the nut.\n");
  set_msg2(" takes a small bite of the nut.\n");
  add_cmd("bites");
  add_cmd("eat");
  add_cmd("chew");
  add_cmd("bite");
  add_cmd("nibble");
  set_heal(20,0); 
  set_charges(2);
  set_stuff(8);
  set_value(104);
}
short(){ return YEL+"Nut"+NORM+" ["+charges+"]"; }
