/* Not for sale. Ansi version of the Dark Naga's clutch of eggs */

#include <ansi.h>
inherit "/players/daranath/qualtor/newstuff/heals/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;

  set_name("eggs");
  add_alias("egg");
  add_alias("clutch");
  set_short("A clutch of "+WHT+"naga eggs"+NORM);
  set_long("A small clutch of leathry eggs. They are a dark grey in color,\n"+
           "and it looks like you could "+WHT+"eat"+NORM+" the eggs.\n");

  set_msg("You greedily stuff some of the "+WHT+"eggs"+NORM+" into your mouth.\n");
  set_msg2(" stuffs some of the "+WHT+"eggs"+NORM+" into thier mouth.\n");
  add_cmd("eat");
  set_type("egg");

  set_heal(25,25);
  set_charges(3);
  set_stuff(10);
  set_value(150);
}

query_save_flag(){
  return 1;
  }
