#include "std.h"
#include "living.h"
object solo;
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
TWO_EXIT("players/mistress/sci_fi/star_wars/hall.c","east",
          "players/mistress/sci_fi/star_wars/yoda.c","south",
    "Hans Solo",
    "\n" +
    "You feel a little disoriented as you step onto a well-worn path.\n" +
    "Who knows where you'll end up next!\n",1)
 
extra_reset()
{
if (!solo || !living(solo) )
{
 
   object weapon;
solo = clone_object("obj/monster");
call_other(solo, "set_name", "Hans Solo");
call_other(solo, "set_ac", 7);
call_other(solo, "set_wc", 12);
call_other(solo, "set_al", 100);
call_other(solo, "set_short", "Hans Solo");
call_other(solo, "set_alias", "hans");
call_other(solo, "set_long", "The space pilot and unlikely hero.\n");
call_other(solo, "set_race", "man");
call_other(solo, "set_alt_name", "solo");
call_other(solo, "set_aggressive", 0);
call_other(solo, "add_money", 60);
call_other(solo, "set_level", 8);
 
move_object(solo, this_object() );
weapon = clone_object("obj/weapon");
call_other(weapon, "set_name", "Hand blaster");
call_other(weapon, "set_alias", "blaster");
call_other(weapon, "set_short", "Blaster");
call_other(weapon, "set_long", "A hand-held blaster");
call_other(weapon, "set_class", 8);
call_other(weapon, "set_value", 30);
call_other(weapon, "set_weight", 1);
call_other(weapon, "set_read", "This comes from Hans Solo");
transfer(weapon,solo);
}
}
