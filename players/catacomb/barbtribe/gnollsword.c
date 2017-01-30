inherit "/obj/weapon";
#include "/players/catacomb/misc/ansi.h"
#define TPN this_player()->query_name()
#define ATN attacker->query_name()

reset (arg)
{
  ::reset(arg);
  if(arg) return;

  set_name("sword");
  set_short("A "+HIR+"rusted"+NORM+" sword");
  set_long(
 "  The sword looks to be almost rusted through.  It could have\n"+
 "been a good sword at one time, but many years of use in combat\n"+
 "has made it almost useless now.\n" );
  set_type("sword");
  set_class(7);
  set_weight(2);
  set_value(250);
 }

  
