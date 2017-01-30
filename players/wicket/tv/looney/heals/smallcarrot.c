#include "/sys/lib.h"
#include <ansi.h>

inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("carrot");
  add_alias("small carrot");
  set_short("A small "+HIY+"carrot"+NORM+"");
  set_long("A smal healthy looking carrot ready to eat. Go ahead take a BITE.\n");
  set_type("bite");
  set_msg("You take bite of a small carrot. It's now all gone.\n");
  set_msg2(" eats a small carrot.\n");
  add_cmd("eat");
  set_heal(10,10); /* hp,sp */
  set_charges(1);
  set_stuff(14);
  set_value(10); /* This is per charge */
}
