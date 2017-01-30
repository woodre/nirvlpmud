#include "std.h"
#include "living.h"
object luke;
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
TWO_EXIT("players/mistress/sci_fi/star_wars/r2d2.c","south",
         "players/mistress/sci_fi/star_wars/entrance.c","west",
   "Luke Skywalker",
    "\nYou enter a bare looking chamber.  There seems to be enough room\n" +
    "to practice some jedi moves though...\n",0)
 
extra_reset()
{
if ( !luke || !living(luke) )
{
   object weapon;
luke= clone_object("obj/monster");
call_other(luke, "set_name", "Luke Skywalker");
call_other(luke, "set_ac", 12);
call_other(luke, "set_wc", 20);
call_other(luke, "set_hp", 800);
call_other(luke, "set_al", 900);
call_other(luke, "set_short", "Luke Skywalker");
call_other(luke, "set_alias", "luke");
call_other(luke, "set_aggressive", 0);
call_other(luke, "set_long", "Young jedi warrior.\n");
call_other(luke, "set_level", 15);
 
move_object(luke, this_object() );
weapon = clone_object("obj/weapon");
call_other(weapon, "set_name", "Deadly lightsabre");
call_other(weapon, "set_alias", "lightsabre");
call_other(weapon, "set_race", "sabre");
call_other(weapon, "set_short", "A glowing lightsabre");
 
call_other(weapon, "set_class", 15);
call_other(weapon, "set_long", "A beatiful yet deadly weapon.");
call_other(weapon, "set_weight", 4);
call_other(weapon, "set_value", 2000);
transfer(weapon,luke);
call_other(weapon, "set_read", "The weapon of a jedi knight");
}
}
