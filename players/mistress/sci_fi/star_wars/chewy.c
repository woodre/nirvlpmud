#include "std.h"
#include "living.h"
object chew;
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
TWO_EXIT("players/mistress/sci_fi/star_wars/yoda.c","north",
          "players/mistress/sci_fi/star_wars/entrance.c","east",
    "Chewbacca",
    "\n" +
    "A menacing growl comes from the shadows... Too bad you have to \n" +
    "go this way to get out.\n",0)
 
extra_reset()
{
if (!chew || !living(chew) )
{
 
   object armor;
chew = clone_object("obj/monster");
call_other(chew, "set_name", "Chewbacca");
call_other(chew, "set_ac", 7);
call_other(chew, "set_wc", 13);
call_other(chew, "set_al", -100);
call_other(chew, "set_short", "Chewbacca");
call_other(chew, "set_long", "Chewbacca,  the large and hairy wookie.\n");
call_other(chew, "set_alias", "chewbacca");
call_other(chew, "set_race", "wookie");
call_other(chew, "set_alt_name", "chewy");
call_other(chew, "set_aggressive", 1);
call_other(chew, "add_money", 79);
call_other(chew, "set_level", 9);
 
move_object(chew, this_object() );
armor = clone_object("obj/armor");
call_other(armor, "set_name", "Wookie boots");
call_other(armor, "set_alias", "boots");
call_other(armor, "set_short", "Boots");
call_other(armor, "set_type", "boots");
call_other(armor, "set_long", "A LARGE pair of boots off a dead wookie");
call_other(armor, "set_value", 125);
call_other(armor, "set_weight", 1);
call_other(armor, "set_read", "These come from Chewbacca,  the wookie");
call_other(armor, "set_ac", 1);
transfer(armor,chew);
}
}
