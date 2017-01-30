#include "std.h"
#include "living.h"
object grump;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

ONE_EXIT("players/mistress/child/snow/exit.c","west",
    "Grumpy",
    "\nYou cautiously step into a dark clearing.  The trees seem to shut\n" +
    "out most of the light.  You feel uneasy and a dismal mood settles over\n" +
    "you.\n",1)

extra_reset()
{
if (!grump || !living(grump) )
{

grump = clone_object("obj/monster");
call_other(grump, "set_name", "Grumpy");
call_other(grump, "set_ac", 7);
call_other(grump, "set_wc", 12);
call_other(grump, "set_al", -374);
call_other(grump, "set_short", "Grumpy");
call_other(grump, "set_alias", "dwarf");
call_other(grump, "set_long", "A mean looking dwarf.\n");
call_other(grump, "set_race", "grumpy");
call_other(grump, "set_aggressive", 0);
call_other(grump, "add_money", 400);
call_other(grump, "set_level", 9);
move_object(grump, this_object() );

}
}
