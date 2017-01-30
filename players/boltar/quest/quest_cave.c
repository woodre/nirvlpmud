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

/*
FOUR_EXIT("players/boltar/quest/dead_area.c", "north",
 "players/boltar/quest/enterance.c", "south",
*/
THREE_EXIT("players/boltar/quest/enterance.c","south",
 "players/boltar/quest/catacombs.c", "east",
  "players/boltar/quest/combs2.c", "west",
   "cave under Big House",
 "The cave splits here into three directions here. This part of the cave\n"+
 "appears to have been used for the preparation of corpses before burial.\n"+
 "You see that their is a faint glow coming from the west.\n",
 0)
