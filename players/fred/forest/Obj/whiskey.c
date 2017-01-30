#include "/players/fred/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("whiskey");
  add_alias("bottle");
  set_short("A bottle of "+BOLD+"Whiskey"+NORM);
  set_long("A tall bottle of whiskey.\n");
  set_type("drink");
  set_msg("You open the bottle and take a long drink from it.\n");
  set_msg2(" drinks a shot of whiskey.\n");
  add_cmd("drink");
  set_heal(50,50);
  set_charges(3);
  set_intox(14);
  set_value(600);
}
