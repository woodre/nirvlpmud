#include "std.h"
#include "living.h"
object apollo;
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
THREE_EXIT("players/mistress/sci_fi/galactica/hall.c","north",
          "players/mistress/sci_fi/galactica/serena.c","east",
          "players/mistress/sci_fi/galactica/starbuck.c","west",
    "Apollo",
    "\n" +
    "You are in the flight simulation chamber.  Someone seems to have set\n" +
    "up for a training review.\n",1)
 
extra_reset()
{
if (!apollo || !living(apollo) )
{
 
   object weapon;
apollo = clone_object("obj/monster");
call_other(apollo, "set_name", "Captain Apollo");
call_other(apollo, "set_ac", 10);
call_other(apollo, "set_wc", 15);
call_other(apollo, "set_hp", 300);
call_other(apollo, "set_al", 3000);
call_other(apollo, "set_short", "Captain Apollo");
call_other(apollo, "set_alias", "apollo");
call_other(apollo, "set_long", "Apollo happens to be the Commanders son.\n");
call_other(apollo, "set_race", "captain");
call_other(apollo, "set_alt_name", "cpt");
call_other(apollo, "set_aggressive", 0);
call_other(apollo, "set_level", 11);
 
move_object(apollo, this_object() );
weapon = clone_object("obj/weapon");
call_other(weapon, "set_name", "Hand Blaster");
call_other(weapon, "set_alias", "blaster");
call_other(weapon, "set_short", "Hand Blaster");
call_other(weapon, "set_long", "This does not blast hands... it blasts people\n");
call_other(weapon, "set_class", 15);
call_other(weapon, "set_value", 500);
call_other(weapon, "set_weight", 4);
call_other(weapon, "set_read", "Engraved is small print is the name Apollo");
transfer(weapon,apollo);
call_other(apollo, "init_command", "wield blaster");
}
}
