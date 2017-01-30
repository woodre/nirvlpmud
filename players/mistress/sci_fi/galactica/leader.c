#include "std.h"
#include "living.h"
object leader, disk;
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
TWO_EXIT("players/mistress/sci_fi/galactica/Ebaltar.c","west",
          "players/mistress/sci_fi/galactica/exit.c","south",
    "Cylon leader",
    "\n" +
    "This seems to be another version of Baltar`s room.  The only\n" +
    "major difference is the height of the throne.  This one is MUCH \n" +
    "higher.\n",1)
 
extra_reset()
{
if (!leader || !living(leader) )
{
 
leader = clone_object("obj/monster");
call_other(leader, "set_name", "Imperial Leader");
call_other(leader, "set_ac", 12);
call_other(leader, "set_wc", 20);
call_other(leader, "set_level", 15);
call_other(leader, "set_al", -769);
call_other(leader, "set_short", "Imperial Leader");
call_other(leader, "set_alias", "leader");
call_other(leader, "set_long", "The cylon Imperial Leader.\n");
call_other(leader, "set_race", "cylon");
call_other(leader, "set_aggressive", 0);
move_object(leader, this_object() );
 
 
}
}

