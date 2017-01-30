#include "std.h"
#include "living.h"
object star;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

TWO_EXIT("players/mistress/child/beast.c","east",
          "players/mistress/child/rhyme.c","south",
    "Little Star",
    "\n" +
    "It is difficult to really see in this room.  Even with light you.\n" +
    "have a hard time making out what is here.  Suddenly you catch a glimpse\n" +
    "of a shining star hurtling from the sky..\n",1)

extra_reset()
{
if (!star || !living(star) )
{

star = clone_object("obj/monster");
call_other(star, "set_name", "Little Star");
call_other(star, "set_ac", 4);
call_other(star, "set_wc", 5);
call_other(star, "set_al", 500);
call_other(star, "set_short", "Little Star");
call_other(star, "set_alias", "star");
call_other(star, "set_long", "Twinkle, twinkle little star... The Little Star is here..\n");
call_other(star, "set_race", "Star");
call_other(star, "set_alt_name", "little");
call_other(star, "set_aggressive", 1);
call_other(star, "add_money", 60);
call_other(star, "set_level", 2);
move_object(star, this_object() );

}
}
