#include "/players/catacomb/misc/ansi.h"
inherit "/obj/weapon.c";

reset (arg) 
{
  ::reset(arg);
  if(arg) return;

  set_name("knife");
  set_alias("dagger");
  set_short(HIY+"A filleting knife");
  set_long(
    "  A serrated blade used for the filleting of fish.  Although it is not\n"+
    "specifically designed to be used as a weapon, it could still prove to \n"+
    "be somewhat efficient.\n" );
  set_type("dagger");
  set_class(13);
  set_weight(1);
  set_value(600);
}

  
