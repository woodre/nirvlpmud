#include "/players/maledicta/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("shot");
  add_alias("bloodcleanser");
  add_alias("bloodcleansing shot");
  set_short("A "+HIR+"bloodcleansing"+NORM+" shot");
  set_long("\
 A large shot of blood cleaner.  It is used to lower the\n\
toxins that can build up in a person's body.  You can 'inject'\n\
it at any time.\n");
  set_type("uses");
  set_msg("\
You inject yourself with a shot of blood cleansing fluid.\n\
Instant relief floods into your body.\n");
  set_msg2(" injects something into an arm.\n");
  add_cmd("inject");
  set_heal(0,0);
  set_charges(3);
  set_intox(-10);
  set_value(200);
  set_msg_precharges(HIG+"[");
  set_msg_postcharges("]"+NORM);
  set_type_single("use"); /* verte */
}

int query_weight()
{
  return charges;
}
