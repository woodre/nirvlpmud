#include "std.h"
#include "living.h"
object tighe;
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
TWO_EXIT("players/mistress/sci_fi/galactica/adama.c","north",
          "players/mistress/sci_fi/galactica/hall.c","west",
    "Tighe",
    "\n" +
    "You feel a chill in the air as you watch the stars float by.  You\n" +
    "wonder how anyone could really live here,  dream or no.\n",1)

extra_reset()
{
if (!tighe || !living(tighe) )
{
 
tighe = clone_object("obj/monster");
call_other(tighe, "set_name", "Tighe");
call_other(tighe, "set_ac", 12);
call_other(tighe, "set_wc", 20);
call_other(tighe, "set_hp", 300);
call_other(tighe, "set_al", -100);
call_other(tighe, "set_short", "Tighe");
call_other(tighe, "set_alias", "tighe");
call_other(tighe, "set_long", "Tighe looks like he could be trouble..\n");
call_other(tighe, "set_aggressive", 0);
call_other(tighe, "add_money", 359);
call_other(tighe, "set_level", 15);
move_object(tighe, this_object() );
 
}
}
