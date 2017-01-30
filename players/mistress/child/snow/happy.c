#include "std.h"
#include "living.h"
object happ;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

THREE_EXIT("players/mistress/child/snow/exit.c","north",
          "players/mistress/child/snow/bash.c","south",
          "players/mistress/child/snow/sneezy.c","west",
    "Happy",
    "\nThe ground is firm beneath your feet,  the sun is shimmering down\n" +
    "through the trees...  You feel joy overwhelm you.\n",1)

extra_reset()
{
if (!happ || !living(happ) )
{

happ = clone_object("obj/monster");
call_other(happ, "set_name", "Happy");
call_other(happ, "set_ac", 7);
call_other(happ, "set_wc", 11);
call_other(happ, "set_al", 600);
call_other(happ, "set_short", "Happy");
call_other(happ, "set_alias", "happy");
call_other(happ, "set_long", "A very cheerful and friendly dwarf.\n");
call_other(happ, "set_race", "dwarf");
call_other(happ, "set_aggressive", 0);
call_other(happ, "add_money", 350);
call_other(happ, "set_level", 8);
move_object(happ, this_object() );

}
}
