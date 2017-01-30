#include "std.h"
#include "living.h"
object leia;
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
TWO_EXIT("players/mistress/sci_fi/star_wars/exit.c","east",
          "players/mistress/sci_fi/star_wars/hall.c","west",
    "Princess Leia",
    "\n" +
    "This chamber is beautiful enough for royalty... indeed,  this\n" +
    "appears to be a princess' room... Princess Leia,  who also happens to\n" +
    "be sister to Luke Skywalker..\n",1)
 
extra_reset()
{
if (!leia || !living(leia) )
{
 
leia = clone_object("obj/monster");
call_other(leia, "set_name", "Princess Leia");
call_other(leia, "set_ac", 4);
call_other(leia, "set_wc", 7);
call_other(leia, "set_al", 600);
call_other(leia, "set_short", "Princess Leia");
call_other(leia, "set_alias", "leia");
call_other(leia, "set_race", "princess");
call_other(leia, "set_long", "Princess and potential jedi.\n");
call_other(leia, "set_alt_name", "Leia");
call_other(leia, "set_aggressive", 0);
call_other(leia, "add_money", 100);
call_other(leia, "set_level", 3);
move_object(leia, this_object() );
 
}
}
