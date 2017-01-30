#include "/players/fred/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("syrup");
  add_alias("bottle");
  set_short(BRED+BOLD+HIW+"Maple"+BLK+" Syrup"+NORM+" (warm)");
  set_long("A bottle of delicious maple syrup.\n"+
           "Your best bet would be to 'guzzle' it.\n");
  set_type("drinks");
  set_msg("You pull the cap off the syrup and guzzle some\n"+
          "straight from the bottle.  Tastey!!\n");
  set_msg2(" guzzles some syrup from the bottle.\n");
  add_cmd("guzzle");
  set_heal(50,50);
  set_charges(3);
  set_soak(3);
  set_stuff(3);
  set_value(1100);
}
