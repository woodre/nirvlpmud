#include "std.h"
#include "living.h"
object athena;
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
ONE_EXIT("players/mistress/sci_fi/galactica/starbuck.c","north",
    "Athena",
    "\nYou enter a dark chamber.  Nice place to sit and spy on a gambler...\n",1)
 
extra_reset()
{
if (!athena || !living(athena) )
{
 
   object armor;
athena = clone_object("obj/monster");
call_other(athena, "set_name", "Athena");
call_other(athena, "set_ac", 7);
call_other(athena, "set_wc", 13);
call_other(athena, "set_al", -100);
call_other(athena, "set_short", "Athena");
call_other(athena, "set_long", "Athena is also the Commander`s daughter.\n");
call_other(athena, "set_alias", "athena");
call_other(athena, "set_aggressive", 0);
call_other(athena, "add_money", 400);
call_other(athena, "set_whimpy",1);
call_other(athena, "set_level", 9);
 
move_object(athena, this_object() );
}
}
