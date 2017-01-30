inherit "/obj/generic_heal.c";
#include <ansi.h>

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("shake");
  add_alias("blueberry shake");
  add_alias("food");
  add_alias("bshake");
  add_alias("blueberry");
  set_short(HIB+"Blueberry"+NORM+" Shake");
  set_long("A protein shake made with regular fat yogurt and "+HIB+"blueberries"+NORM+".\n\
It looks very filling and thirst quenching at the same time.\n");    
  set_type("drink");
  set_msg("You take a drink of the "+HIB+"Blueberry "+NORM+"Shake.\n");
  set_msg2(" takes a drink of the "+HIB+"Blueberry "+NORM+"Shake.\n");
  add_cmd("drink");
  add_cmd("gulp");
  add_cmd("sip");
  set_heal(50,50);
  set_charges(3);
  set_stuff(10);
  set_soak(10);
  set_value(400);
}

