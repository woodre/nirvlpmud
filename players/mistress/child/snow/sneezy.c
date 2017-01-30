#include "std.h"
#include "living.h"
object sneez;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

TWO_EXIT("players/mistress/child/snow/happy.c","east",
          "players/mistress/child/snow/dopey.c","west",
    "Sneezy",
    "\n" +
    "The forest appears to be getting lighter here.  Unfortunately,  the\n" +
    "ground seems to be a little damp.  It's a kind of sticky dampness\n" +
    "covered with a substance you can't identify.\n",1)

extra_reset()
{
if (!sneez || !living(sneez) )
{

sneez = clone_object("obj/monster");
call_other(sneez, "set_name", "Sneezy");
call_other(sneez, "set_ac", 3);
call_other(sneez, "set_wc", 6);
call_other(sneez, "set_level", 3);
call_other(sneez, "set_al", 64);
call_other(sneez, "set_short", "Sneezy");
call_other(sneez, "set_alias", "sneezy");
call_other(sneez, "set_long", "He is too busy sneezing!.\n");
call_other(sneez, "set_race", "dwarf");
call_other(sneez, "set_aggressive", 0);
call_other(sneez, "add_money", 100);
move_object(sneez, this_object() );

}
}
