#include "std.h"
#include "living.h"
object dope;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

THREE_EXIT("players/mistress/child/snow/sleepy.c","north",
          "players/mistress/child/snow/enter.c","south",
          "players/mistress/child/snow/sneezy.c","east",
    "Dopey",
    "\nYou are travelling along a well-worn path.  There are even indications\n" +
    "of someone's recent passage.  The dirt is freshly scuffed and part of\n" +
    "a nearby bush is partially torn.\n",1)

extra_reset()
{
if (!dope || !living(dope) )
{

   object armor;
dope = clone_object("obj/monster");
call_other(dope, "set_name", "Dopey");
call_other(dope, "set_ac", 5);
call_other(dope, "set_wc", 7);
call_other(dope, "set_al", 400);
call_other(dope, "set_short", "Dopey");
call_other(dope, "set_long", "Dopey seems to be perpetually lost.\n");
call_other(dope, "set_alias", "dopey");
call_other(dope, "set_race", "dwarf");
call_other(dope, "set_aggressive", 0);
call_other(dope, "add_money", 36);
call_other(dope, "set_level", 4);

move_object(dope, this_object() );
armor = clone_object("obj/armor");
call_other(armor, "set_name", "Button");
call_other(armor, "set_alias", "button");
call_other(armor, "set_short", "button");
call_other(armor, "set_long", "An overly large button that looks like a good shield\n");
call_other(armor, "set_type", "shield");
call_other(armor, "set_value", 100);
call_other(armor, "set_weight", 1);
call_other(armor, "set_ac", 0);
transfer(armor,dope);
call_other(dope, "init_command", "wear button");
}
}
