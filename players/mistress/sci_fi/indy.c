#include "std.h"
#include "living.h"
object indy,weapon;
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
ONE_EXIT("players/mistress/sci_fi/read.c","north",
   "Indiana Jones",
   "\n" +
   "This appears to be the office of an absent-minded professor... The \n" +
   "desk is cluttered with priceless artifacts and books line the tables\n" +
   "and chairs - not to mention the bookshelves!\n",1)
 
extra_reset()
{
if (!indy || !living(indy))
{
 
indy= clone_object("obj/monster");
call_other(indy, "set_name", "Indiana Jones");
call_other(indy, "set_ac", 12);
call_other(indy, "set_wc", 20);
call_other(indy, "set_al", 100);
call_other(indy, "set_alias", "indy");
call_other(indy, "set_alt_name", "jones");
call_other(indy, "set_race", "Indiana");
call_other(indy, "set_short", "Indiana Jones");
call_other(indy, "set_long", "The swashbuckling hero.\n");
call_other(indy, "set_agressive", 0);
call_other(indy, "set_level", 15);
 
move_object(indy, this_object());
weapon= clone_object("obj/weapon");
call_other(weapon, "set_name", "A Deadly Bullwhip");
call_other(weapon, "set_alias", "whip");
call_other(weapon, "set_alt_name", "bullwhip");
call_other(weapon, "set_class", 13);
call_other(weapon, "set_value", 800);
call_other(weapon, "set_weight", 3);
transfer(weapon,indy);
}
}
