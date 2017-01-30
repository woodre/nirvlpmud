#include "std.h"
#include "living.h"
object obi;
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
ONE_EXIT("players/mistress/sci_fi/star_wars/yoda.c","east",
    "Obiwan Kenobi",
    "\n" +
    "Is is hard to see in here...  not sure if it is the lighting or\n" +
    "an illusion.  Could there be a the shadowy presence of SOMEONE\n" +
    "a meter or two before you?\n",1)
 
extra_reset()
{
if (!obi || !living(obi) )
{
 
obi = clone_object("obj/monster");
call_other(obi, "set_name", "Obiwan Kenobi");
call_other(obi, "set_ac", 9);
call_other(obi, "set_wc", 16);
call_other(obi, "set_al", 879);
call_other(obi, "set_short", "Obiwan Kenobi");
call_other(obi, "set_alias", "obiwan");
call_other(obi, "set_long", "Obiwan Kenobi is here.\n");
call_other(obi, "set_race", "kenobi");
call_other(obi, "set_alt_name", "obi");
call_other(obi, "set_aggressive", 0);
call_other(obi, "add_money", 567);
call_other(obi, "set_level", 12);
move_object(obi, this_object() );
 
}
}
