/*  Changed to new heal format 8/21/02 - Eurale  */
/*  Cost:  50hps at stuff 12 * 12/pt = 600 * 3 bites = 1800  */

#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */

inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("honeycomb");
  add_alias("gooey honeycomb");
  set_short(YEL+"gooey honeycomb"+NORM);
  set_long("A large piece of gooey honeycomb that you can eat for energy.\n");
  add_cmd("eat");
  set_type("bites");
  set_type_single("bite");
  set_msg(YEL+"You bite off and swallow a piece of gooey honeycomb.\n"+NORM);
  set_msg2(" takes a bite of gooey honeycomb.\n");
  set_heal(50,50);
  set_charges(3);
  set_msg_precharges("<");
  set_msg_postcharges(">");
  set_stuff(12);  /*  intox  soak  stuff  */
  set_value(500);
  set_msg_stuffed("You feel too full to eat any more honeycomb.\n");
  set_empty_msg(YEL +
    "You stuff the last piece of gooey honeycomb into your mouth.\n"+NORM);
}
