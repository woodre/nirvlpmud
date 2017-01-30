#include "/players/fred/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("punch");
  add_alias("jug");
  set_short(RED+"A jug of Hi-C"+NORM);
  set_long("A jug of Hi-C fruit punch.\n"+
           "Maybe you could 'sip' it.\n");
  set_type("drink");
  set_msg("You take a large drink of punch.\n");
  set_msg2(" takes a big gulp of punch.\n");
  add_cmd("sip");
  set_heal(50,50);
  set_charges(3);
  set_soak(14);
  set_value(600);
}
