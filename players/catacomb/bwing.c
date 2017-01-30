inherit "/obj/generic_heal.c";
#include <ansi.h>

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("buffalo wings");
  add_alias("wing");
  set_short("A container of "+BOLD+HIR+"Blazing "+NORM+"buffalo wings.\n");
  set_long("A cardboard container containing 5 wings, that could be 'eaten'\n");
  set_type("bite");
  set_msg("You grab a wing with both hands and devour it.\n");
  set_msg2(" devours a buffalo wing.\n");
  add_cmd("eat");
  set_heal(30,30); 
  set_charges(5);
  set_stuff(10);
  set_value(330);
}
