#include <ansi.h> /* 2007-10-29 removed ; after #include -Vital */

inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("cheese wiz");
  add_alias("wiz");
  add_alias("stem");
  add_alias("cheese");
  add_alias("can");
  set_short(HIR+"["+HIY+"Cheese Wiz"+HIR+"]"+NORM);
  set_long("This is a can of cheese wiz. On top of the can\n\
you notice a white stem. You get the impression\n\
that you might be able to 'press' the stem.\n");
  set_type("squirts");
  set_type_single("squirt");
  set_msg("You place the can near your mouth and press the stem\n\
gently. The cheese pours into your mouth.   Yummy!\n");
  set_msg2(" press agianst the stem. The cheese\n\
squirts out with lighting speed.\n");
  add_cmd("press");
  set_heal(50,50);
  set_charges(3);
  set_soak(7);
  set_stuff(7);
  set_value(600);
}

query_save_flag() { return 1; }
