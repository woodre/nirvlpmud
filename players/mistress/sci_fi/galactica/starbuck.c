#include "std.h"
#include "living.h"
object buck;
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
TWO_EXIT("players/mistress/sci_fi/galactica/apollo.c","east",
          "players/mistress/sci_fi/galactica/athena.c","south",
    "Starbuck",
    "\n" +
    "A large, cavernous room spreads out before you.  This looks to be\n" +
    "part of the hanger deck.  As you approach the side of the room,  you\n" +
    "see a card table set up..\n",1)
 
extra_reset()
{
if (!buck || !living(buck) )
{
 
buck = clone_object("obj/monster");
call_other(buck, "set_name", "Starbuck");
call_other(buck, "set_ac", 9);
call_other(buck, "set_wc", 16);
call_other(buck, "set_al", -50);
call_other(buck, "set_short", "Starbuck");
call_other(buck, "set_long", "Captain Starbuck... need you say more?\n");
call_other(buck, "set_alias", "starbuck");
call_other(buck, "set_race", "star");
call_other(buck, "set_alt_name", "buck");
call_other(buck, "set_aggressive", 0);
call_other(buck, "add_money", 600);
call_other(buck, "set_level", 12);
move_object(buck, this_object() );
 
}
}
