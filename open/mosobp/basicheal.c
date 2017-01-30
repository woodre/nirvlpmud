

#include <ansi.h> 
inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("basic heal");
  add_alias("heal");
  set_short("+HIR+"Basic Heal"+NORM);
  set_long("A basic heal to regen you. enjoy the drink.\n");
  set_type("drink");
  set_msg("You hold the bottle mouth and drink. MMMmm!\n");
  set_msg2(" lifts the bottle into their mouth.\n");
  add_cmd("drink");
  set_heal(50,50);
  set_charges(3);
  set_soak(7);
  set_stuff(7);
  set_value(600);

}

query_save_flag() { return 1; }



/*
also read the heal rules, they are in.....

										/doc/build/items/heals*/