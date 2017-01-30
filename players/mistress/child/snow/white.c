#include "std.h"
#include "living.h"
object white;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

ONE_EXIT("players/mistress/child/snow/bash.c","west",
    "Snow White",
    "\nYou come to a small clearing.  The sun fills this space with a beauty\n" +
    "you kind of expected to find.\n",1)

extra_reset()
{
if (!white || !living(white) )
{

white = clone_object("obj/monster");
call_other(white, "set_name", "Snow White");
call_other(white, "set_ac", 4);
call_other(white, "set_wc", 8);
call_other(white, "set_hp", 190);
call_other(white, "set_level", 4);
call_other(white, "set_al", 400);
call_other(white, "set_short", "Snow White");
call_other(white, "set_alias", "snow");
call_other(white, "set_long", "The fairest of them all.\n");
call_other(white, "set_race", "white");
call_other(white, "set_alt_name", "snow white");
call_other(white, "set_aggressive", 0);
call_other(white, "add_money", 150);
move_object(white, this_object() );

}
}
