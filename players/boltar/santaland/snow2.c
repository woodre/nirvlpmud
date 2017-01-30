#include "std.h"

object frosty;

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    object money;
    if (!frosty || !living(frosty)) {
	frosty = clone_object("obj/monster");
	call_other(frosty, "set_name", "frosty");
	call_other(frosty, "set_hp", 120);
call_other(frosty, "set_ac", 6);
	call_other(frosty, "set_wc", 8);
	call_other(frosty, "set_al", 1000);
	call_other(frosty, "set_short", "Frosty the snowman");
	call_other(frosty, "set_long",
   "It's good old frosty himself.\n");
	call_other(frosty, "set_aggressive", 0);
call_other(frosty, "set_level", 8);
	call_other(frosty, "set_spell_mess1",
		   "Frosty says: I'm melting.");
	call_other(frosty, "set_spell_mess2",
		   "Frosty says: Help me, I'm melting.");
	call_other(frosty, "set_chance", 30);
	move_object(frosty, this_object());
	money = clone_object("obj/money");
        call_other(money, "set_money", random(300));
        move_object(money, frosty);
    }
}

THREE_EXIT("players/boltar/santaland/snow3.c", "north",
 "players/boltar/santaland/snow1.c", "south",
 "players/boltar/santaland/grinchcave.c", "up",
	   "The snow before santa's place",
  "The snow is about six to eight inches deep now, and you are struggling\n"+
  "to get through it.  The snow is heavy and snowshoes would be nice,\n" +
  "but the snow still would not support the weight of an equiped adventurer.\n"+
  "There is a mountian to west with a trail leading upwards to regions unknown.\n" +
  "\n\n\n"+
  "A thick, wet heavy snow begins to fall and it becomes hard to see where\n" +
  "you are going.\n"
  , 1)
