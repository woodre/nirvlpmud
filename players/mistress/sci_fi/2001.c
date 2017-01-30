#include "std.h"
#include "living.h"
object hal;
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
ONE_EXIT("players/mistress/sci_fi/hall2.c","north",
    "Hal",
    "\n" +
    "The books make way for metal and blinking lights.  <Oops... wonder\n" +
    "if I stepped into the wrong section?>  The whir of activity suggests\n" +
    "a computer is hard at work somewhere nearby..\n",1)
 
extra_reset()
{
if (!hal || !living(hal) )
{
 
hal = clone_object("obj/monster");
call_other(hal, "set_name", "Hal, the interactive computer of 2001");
call_other(hal, "set_ac", 9);
call_other(hal, "set_wc", 16);
call_other(hal, "set_hp", 200);
call_other(hal, "set_al", -50);
call_other(hal, "set_short", "Hal, the interactive computer of 2001");
call_other(hal, "set_alias", "hal");
call_other(hal, "set_long", "Hal is a computer with a mind of his own.\n");
call_other(hal, "set_race", "computer");
call_other(hal, "set_alt_name", "comp");
call_other(hal, "set_aggressive", 0);
call_other(hal, "add_money", 671);
call_other(hal, "set_level", 13);
move_object(hal, this_object() );
 
}
}
