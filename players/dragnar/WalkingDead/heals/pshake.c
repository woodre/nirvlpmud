inherit "/obj/generic_heal.c";
#include <ansi.h>

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("shake");
  add_alias("spinach protein shake");
  add_alias("spinach shake");
  add_alias("protein shake");
  add_alias("food");
  add_alias("pshake");
  add_alias("spinach");
  set_short(HIG+"Spinach"+NORM+" Protein Shake");
  set_long("A protein shake made with yogurt, spinach, and protein powder.\n\
It looks filling and thirst quenching at the same time.\n");    
  set_type("drink");
  set_msg("You take a drink of the "+HIG+"Spinach "+NORM+"Shake.\n");
  set_msg2(" takes a drink of the "+HIG+"Spinach "+NORM+"Shake.\n");
  add_cmd("drink");
  add_cmd("gulp");
  add_cmd("sip");
  set_heal(50,50);
  set_charges(3);
  set_stuff(3);
  set_soak(3);
  set_value(1100);
}

