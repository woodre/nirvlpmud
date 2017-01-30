#include "std.h"
#include "living.h"
object bashful;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

TWO_EXIT("players/mistress/child/snow/happy.c","north",
          "players/mistress/child/snow/white.c","east",
    "Bashful",
     "\n" +
    "Shadows peek in and out through the trees,  making you wonder if you\n" +
    "are being watched.  You get a little nervous at the thought.\n",1)

extra_reset()
{
if (!bashful || !living(bashful) )
{

bashful = clone_object("obj/monster");
call_other(bashful, "set_name", "Bashful");
call_other(bashful, "set_ac", 4);
call_other(bashful, "set_wc", 5);
call_other(bashful, "set_al", 501);
call_other(bashful, "set_short", "Bashful");
call_other(bashful, "set_alias", "bashful");
call_other(bashful, "set_long", "Bashful has a sweet rosey blush on his cheeks.\n");
call_other(bashful, "set_race", "dwarf");
call_other(bashful, "set_aggressive", 0);
call_other(bashful, "add_money", 100);
call_other(bashful, "set_level", 3);
move_object(bashful, this_object() );

}
}
