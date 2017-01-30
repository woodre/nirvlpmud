#include "std.h"
#include "living.h"
object black;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

TWO_EXIT("players/mistress/child/child.c","north",
          "players/mistress/child/blue.c","west",
    "Black Stallion",
    "\n" +
    "The carpeting amazingly turns to green beneath your feet.\n" +
    "You seem to be in some kind of pasture.\n",1)

extra_reset()
{
if (!black || !living(black) )
{

   object weapon;
black = clone_object("obj/monster");
call_other(black, "set_name", "Black Stallion");
call_other(black, "set_ac", 5);
call_other(black, "set_wc", 7);
call_other(black, "set_al", -300);
call_other(black, "set_short", "Black Stallion");
call_other(black, "set_alias", "black");
call_other(black, "set_long", "A powerful and beautiful arabian..\n");
call_other(black, "set_race", "horse");
call_other(black, "set_alt_name", "stallion");
call_other(black, "set_aggressive", 0);
call_other(black, "add_money", 39);
call_other(black, "set_level", 3);

move_object(black, this_object() );
weapon = clone_object("obj/weapon");
call_other(weapon, "set_name", "Golden hoof");
call_other(weapon, "set_alias", "hoof");
call_other(weapon, "set_short", "Golden hoof");
call_other(weapon, "set_class", 7);
call_other(weapon, "set_long", "The hoof of a brave and mighty beast\n");
call_other(weapon, "set_value", 300);
call_other(weapon, "set_weight", 1);
call_other(weapon, "set_read", "This hoof belongs to the Black Stallion");
transfer(weapon,black);
call_other(black, "init_command", "wield hoof");
}
}
