#include <ansi.h> /* 2007-10-29 removed ; after #include -Vital */

inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("GoGurt");
  add_alias("gogurt");
  add_alias("gurt");
  add_alias("tube");
  set_short(HIR+"["+HIB+"GoGurt"+HIR+"]"+NORM);
  set_long("A tube filled with a liquid yogurt. It comes\n\
in many flavors and you are not sure which\n\
one to try first! You have the urge to\n\
'squeeze' it.\n");
  set_type("drinks");
  set_type_single("drink");
  set_msg("You place the tube to your mouth and squeeze it gently.\n\
Some of the liquid squirts into your mouth.  Yummy!\n");
  set_msg2(" squeezes the tube as it squirts\n\
out with lighting speed.\n");
  add_cmd("squeeze");
  set_heal(50,50);
  set_charges(4);
  set_soak(6);
  set_stuff(6);
  set_value(700);
}

query_save_flag() { return 1; }
