#include "std.h"
#include "living.h"
object thumper;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

ONE_EXIT("players/mistress/child/bambi.c","exit",
    "Thumper",
    "\n" +
    "The ground here is littered with burrows.  As far as you can tell,  they\n" +
    "belong to rabbits.  Bending close to the ground you see LARGE bunny-prints\n" +
    "scattered about.\n",1)

extra_reset()
{
if (!thumper || !living(thumper) )
{

   object weapon;
thumper = clone_object("obj/monster");
call_other(thumper, "set_name", "Thumper rabbit");
call_other(thumper, "set_ac", 5);
call_other(thumper, "set_wc", 10);
call_other(thumper, "set_al", 399);
call_other(thumper, "set_short", "Thumper rabbit");
call_other(thumper, "set_alias", "rabbit");
call_other(thumper, "set_long", "A fluffy rabbit with loppy ears and HUGE feet.\n");
call_other(thumper, "set_race", "rabbit");
call_other(thumper, "set_alt_name", "thumper");
call_other(thumper, "set_aggressive", 0);
call_other(thumper, "set_level", 6);

move_object(thumper, this_object() );
weapon = clone_object("obj/weapon");
call_other(weapon, "set_name", "Rabbit foot");
call_other(weapon, "set_alias", "foot");
call_other(weapon, "set_short", "Rabbit foot");
call_other(weapon, "set_long", "Thumper`s large yet effective foot.\n");
call_other(weapon, "set_class", 12);
call_other(weapon, "set_value", 600);
call_other(weapon, "set_weight", 3);
transfer(weapon,thumper);
call_other(thumper, "init_command", "wield foot");
}
}
