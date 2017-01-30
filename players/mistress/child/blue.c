#include "std.h"
#include "living.h"
object blue;
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
TWO_EXIT("players/mistress/child/rhyme.c","north",
          "players/mistress/child/black.c","east",
    "Little Boy Blue",
    "\n" +
    "Now here is a familiar picture... A boy fast asleep by the hay,\n" +
    "off in the distance a hear of cows happily munching on corn...  and a\n" +
    "little bugle lying neglected on the ground.\n",1)
 
extra_reset()
{
if (!blue || !living(blue) )
{
 
blue = clone_object("obj/monster");
call_other(blue, "set_name", "Little Boy Blue");
call_other(blue, "set_ac", 5);
call_other(blue, "set_wc", 10);
call_other(blue, "set_al", 100);
call_other(blue, "set_short", "Little Boy Blue");
call_other(blue, "set_long", "Little Boy Blue is fast asleep.\n");
call_other(blue, "set_alias", "boy");
call_other(blue, "set_race", "little");
call_other(blue, "set_alt_name", "blue");
call_other(blue, "set_aggressive", 0);
call_other(blue, "add_money", 75);
call_other(blue, "set_level", 7);
call_other(blue, "set_whimpy",1);
 
move_object(blue, this_object() );
}
}
