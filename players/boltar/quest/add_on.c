#include "std.h"

object creeper;
 int xx;

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    object money;
  xx = 0;
    if (!creeper || !living(creeper)) {
 while(xx < 3) {
	creeper = clone_object("obj/monster");
	call_other(creeper, "set_name", "creeper");
	call_other(creeper, "set_hp", 90);
call_other(creeper, "set_ac", 4);
	call_other(creeper, "set_wc", 6);
	call_other(creeper, "set_al", 200);
	call_other(creeper, "set_short", "A Dark Creeper");
	call_other(creeper, "set_long",
    "A small creature that stays away from the light.\n");
	call_other(creeper, "set_aggressive", 0);
call_other(creeper, "set_level", 7);
	move_object(creeper, this_object());
	money = clone_object("obj/money");
        call_other(money, "set_money", random(300));
        move_object(money, creeper);
     xx += 1;
     }
    }
}

TWO_EXIT("players/boltar/quest/add_on2.c", "south",
 "players/boltar/quest/enterance.c", "north",
   "cave under Big House",
 "The cave continues south, and you have a feeling something lies ahead. \n"+
 "This area looks fairly empty roughly dug out.\n",
 0)
