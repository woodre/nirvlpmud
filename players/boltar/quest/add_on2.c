#include "std.h"

object creeper, stalker;
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
	call_other(creeper, "set_aggressive", 1);
call_other(creeper, "set_level", 7);
	move_object(creeper, this_object());
	money = clone_object("obj/money");
        call_other(money, "set_money", random(300));
        move_object(money, creeper);
     xx += 1;
     }
    }
    if (!stalker || !living(stalker)) {
	stalker = clone_object("obj/monster");
	call_other(stalker, "set_name", "stalker");
	call_other(stalker, "set_hp", 300);
call_other(stalker, "set_ac", 6);
	call_other(stalker, "set_wc", 15);
	call_other(stalker, "set_al", 200);
	call_other(stalker, "set_short", "A Dark Stalker");
	call_other(stalker, "set_long",
    "A leader of the dark creepers, it is about the size of a human.\n");
	call_other(stalker, "set_aggressive", 1);
call_other(stalker, "set_level", 14);
	move_object(stalker, this_object());
	money = clone_object("obj/money");
        call_other(money, "set_money", random(700));
        move_object(money, stalker);
     }

}

ONE_EXIT("players/boltar/quest/add_on.c", "north",
   "cave under Big House",
  "The cave dead ends here, it looks like this area is some sort of home,\n"+
  "or maybe a command center of some sort.\n",
 0)
