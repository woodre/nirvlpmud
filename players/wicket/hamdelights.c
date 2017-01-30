#include "/sys/lib.h"
#include <ansi.h>

inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("delights");
  add_alias("ham delights");
  set_short("A Delicious batch of "+HIM+"Ham Delights"+NORM+"");
  set_long("A fresh and hot delicious batch of ham delights.\n");
  set_type("eat");
  set_msg("You eat a massive chunk of the ham delights.\n");
  set_msg2(" eats a massive chunk of the ham delights.\n");
  add_cmd("eat");
  set_heal(10,10); /* hp,sp */
  set_charges(100);
  set_stuff(0);
  set_value(10); /* This is per charge */
}
