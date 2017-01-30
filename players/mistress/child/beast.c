#include "std.h"
#include "living.h"
object beast;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

TWO_EXIT("players/mistress/child/child.c","south",
          "players/mistress/child/star.c","west",
    "Beast",
    "\n" +
    "Ahhh, the classic tale of Beauty and the Beast.  The book lies open on.\n" +
    "the table before you,  but something seems odd about the pages.  They .\n" +
    "look so dog-eared that you are sure no child could have done this..\n",1)

extra_reset()
{
if (!beast || !living(beast) )
{

beast = clone_object("obj/monster");
call_other(beast, "set_name", "Beast");
call_other(beast, "set_ac", 5);
call_other(beast, "set_wc", 9);
call_other(beast, "set_hp", 100);
call_other(beast, "set_al", -437);
call_other(beast, "set_short", "Beast");
call_other(beast, "set_alias", "beast");
call_other(beast, "set_long", "This is Beauty`s Beast.\n");
call_other(beast, "set_alt_name", "y");
call_other(beast, "set_aggressive", 1);
call_other(beast, "add_money", 29);
call_other(beast, "set_level", 6);
move_object(beast, this_object() );

}
}
