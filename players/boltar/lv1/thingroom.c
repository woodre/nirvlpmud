#include "std.h"

#undef EXTRA_INIT
#define EXTRA_INIT extra_init();
extra_init() {
     add_action("look", "look");
     add_action("look", "l");
     add_action("look", "examine");
     add_action("look", "search");
  }
look(str) {
   if (!str) {
   return 0;
  }
 if (str == "at table" || str == "at box" || str == "box" || str == "table") {
  write("The box on top of the table looks like the home for some sort of creature.\n");
   return 1;
  }
return 0;
}
object thing;

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    object money;
    if (!thing || !living(thing)) {
	thing = clone_object("obj/monster");
	call_other(thing, "set_name", "thing");
	call_other(thing, "set_hp", 60);
call_other(thing, "set_ac", 7);
	call_other(thing, "set_wc", 5);
	call_other(thing, "set_al", 200);
	call_other(thing, "set_short", "A thing");
	call_other(thing, "set_long",
		   "It looks like a hand, it lives in the box. \n");
	call_other(thing, "set_aggressive", 0);
call_other(thing, "set_level", 3);
	call_other(thing, "set_spell_mess1",
		   "The Thing gives you the thumbs down.");
	call_other(thing, "set_spell_mess2",
		   "The Thing gives you the finger!");
	call_other(thing, "set_chance", 20);
	move_object(thing, this_object());
	money = clone_object("obj/money");
        call_other(money, "set_money", random(200));
        move_object(money, thing);
    }
}

TWO_EXIT("players/boltar/lv1/festerroom.c", "west",
	 "players/boltar/lv1/room2.c", "south",
        "The Thing room",
  "Upon entering this room one sees that it is in a much different style\n" +
  "than that of the entrance hall.  The house looks quite old and run\n" +
"down here.  The wallpaper is faded and the furiture looks very old.\n" +
"You notice a small box on a table in the center of the room.\n" +
"It's small, yet it appears bottomless, it may be the home of some sort\n" +
"of creature.\n", 1)
