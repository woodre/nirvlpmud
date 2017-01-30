inherit "/obj/generic_heal.c";
#include <ansi.h>

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name(""+YEL+"order of french fries"+NORM+"");
  add_alias("french fries");
  add_alias("fries");
  add_alias("order");
  add_alias("order of fries");
  set_short(""+YEL+"an order of french fries"+NORM+"");
  set_long("This is an order of "+YEL+"french fries"+NORM+".\n"+
           "The fries look so tasty you would just want to eat them.\n");    
  set_type("bites");
  set_msg("You shove a handful of "+YEL+"fries"+NORM+" in your mouth.\n");
  set_msg2(" shoves a handful of "+YEL+"fries"+NORM+" into "+this_player()->query_possessive()+" mouth.\n");
  add_cmd("eat");
  set_heal(50,50);
  set_charges(3);
  set_stuff(12);
 /* changed by verte */
  set_value(700);
}

query_save_flag(){
  return 1;
  }
