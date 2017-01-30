#include "std.h"
#include "living.h"
object jabba;
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
ONE_EXIT("players/mistress/sci_fi/star_wars/exit.c","south",
    "Jabba the Hut",
    "\n" +
    "The stench in this room is overpowering.  Before you is a low dias\n" +
    "covered with recent drool... (UGH!)\n",0)
 
extra_reset()
{
if (!jabba || !living(jabba) )
{
 
jabba = clone_object("obj/monster");
call_other(jabba, "set_name", "Jabba the Hut");
call_other(jabba, "set_ac", 10);
call_other(jabba, "set_wc", 17);
call_other(jabba, "set_al", -790);
call_other(jabba, "set_short", "Jabba the Hut");
call_other(jabba, "set_alias", "jabba");
call_other(jabba, "set_long", "An ugly and fierce creature.\n");
call_other(jabba, "set_race", "Jabba");
call_other(jabba, "set_alt_name", "jabba");
call_other(jabba, "set_aggressive", 1);
call_other(jabba, "add_money", 700);
call_other(jabba, "set_level", 13);
move_object(jabba, this_object() );
 
}
}
