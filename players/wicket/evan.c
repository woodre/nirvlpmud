#include "/sys/lib.h"
#include <ansi.h>

inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("evan");
  add_alias("whiskey");
  set_short("A Massive Supply of"+HIK+" Evan Williams"+NORM);
  set_long("A massive supply of Evan Williams bourbon whiskey.\n");
  set_type("drink");
  set_msg("You slam down a shot of Evan Williams and it feels oh so good!\n");
  set_msg2(" slams down a shot of Evan Williams.\n");
  add_cmd("drink");
  set_heal(10,10); /* hp,sp */
  set_charges(100);
  set_intox(10);
  set_value(0); /* This is per charge */
}
