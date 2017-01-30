#include "std.h"
#include "living.h"
object darth;
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
ONE_EXIT("players/mistress/sci_fi/star_wars/hall.c","south",
   "Darth Vader",
   "\n" +
   "You step into the shadows.  Even with light,  you can't really see\n" +
    "anything...  \n",0)
 
extra_reset()
{
if ( !darth || !living(darth) )
{
   object weapon;
darth= clone_object("obj/monster");
call_other(darth, "set_name", "Darth Vader");
call_other(darth, "set_ac", 9);
call_other(darth, "set_wc", 16);
call_other(darth, "set_hp", 400);
call_other(darth, "set_al", -760);
call_other(darth, "set_short", "Darth Vader");
call_other(darth, "set_alias", "darth");
call_other(darth, "set_alt_name", "vader");
call_other(darth, "set_aggressive", 1);
call_other(darth, "set_long", "Evil jedi warrior.\n");
call_other(darth, "set_level", 12);
 
move_object(darth, this_object() );
weapon = clone_object("obj/weapon");
call_other(weapon, "set_name", "Sinister lightsabre");
call_other(weapon, "set_alias", "lightsabre");
call_other(weapon, "set_alt_name", "sabre");
call_other(weapon, "set_short", "An evil-looking lightsabre");
 
call_other(weapon, "set_class", 10);
call_other(weapon, "set_long", "A sinister and deadly weapon\n");
call_other(weapon, "set_weight", 3);
call_other(weapon, "set_value", 600);
transfer(weapon,darth);
call_other(weapon, "set_read", "The weapon on an evil one\n");
}
}
