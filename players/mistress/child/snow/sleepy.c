#include "std.h"
#include "living.h"
object sleep;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

TWO_EXIT("players/mistress/child/snow/dopey.c","south",
          "players/mistress/child/snow/doc.c","west",
    "Sleepy",
    "\n" +
    "As you enter a nice sunny glade,  you see what appears to be nice log\n" +
    "sitting smack-dab in the middle of a sunny patch.  This would be a perfect\n" +
    "place for a nap.\n",1)

extra_reset()
{
if (!sleep || !living(sleep) )
{

   object weapon;
sleep = clone_object("obj/monster");
call_other(sleep, "set_name", "Sleepy");
call_other(sleep, "set_ac", 6);
call_other(sleep, "set_wc", 11);
call_other(sleep, "set_al", -346);
call_other(sleep, "set_short", "Sleepy");
call_other(sleep, "set_alias", "sleepy");
call_other(sleep, "set_long", "He looks like he will fall back asleep any second.\n");
call_other(sleep, "set_race", "dwarf");
call_other(sleep, "set_aggressive", 0);
call_other(sleep, "add_money", 43);
call_other(sleep, "set_level", 7);

move_object(sleep, this_object() );
weapon = clone_object("obj/weapon");
call_other(weapon, "set_name", "Pillow");
call_other(weapon, "set_alias", "pillow");
call_other(weapon, "set_short", "Pillow");
call_other(weapon, "set_lon", "You see a big S embroidered onto the pillow\n");
call_other(weapon, "set_class", 7);
call_other(weapon, "set_value", 75);
call_other(weapon, "set_weight", 1);
transfer(weapon,sleep);
call_other(sleep, "init_command", "wield pillow");
}
}
