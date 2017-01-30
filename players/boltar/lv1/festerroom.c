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
if (str == "rack" || str == "at rack"){
 write ("The good old rack.\n");
 return 1;
}
if (str == "stockade" || str == "at stockade") {
 write ("a wooden stockade.\n");
   return 1;
  }
return 0;
}
object fester;

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    object money;
    object bulb;


    if (!fester || !living(fester)) {
	fester = clone_object("obj/monster");
	call_other(fester, "set_name", "fester");
	call_other(fester, "set_hp", 110);
call_other(fester, "set_ac", 6);
	call_other(fester, "set_wc", 12);
	call_other(fester, "set_al", 200);
	call_other(fester, "set_short", "Uncle Fester");
	call_other(fester, "set_long",
		   " It's the dopey bald guy himself, Uncle Fester, with a light bulb in his mouth.\n");
	call_other(fester, "set_aggressive", 1);
call_other(fester, "set_level", 9);
	call_other(fester, "set_spell_mess1",
		   "Uncle Fester fires his musket ");
	call_other(fester, "set_spell_mess2",
		   "Uncle Fester fires his musket at you! OUCH!!");
	call_other(fester, "set_chance", 40);
call_other(fester, "set_spell_dam", 15);
	move_object(fester, this_object());
	money = clone_object("obj/money");
        call_other(money, "set_money", random(350));
        move_object(money, fester);
bulb = clone_object("obj/treasure");
call_other(bulb, "set_id", "bulb");
call_other(bulb, "set_short", "A light bulb");
call_other(bulb, "set_long", "It lights up if it gets some energy to use\n");
call_other(bulb, "set_value", 15);
call_other(bulb, "set_weight", 1);
move_object(bulb, fester);
    }
}

ONE_EXIT("players/boltar/lv1/thingroom.c", "east",
 "Uncle Fester's room",
 "This room is much the same as the last, but much stranger.  On the wall is a\n" +
 "large mounted fish with a man's legs sticking out of its mouth.\n" +
 "along the west wall is a rack, (that good old pain reliver) and on the\n" +
 "north wall a stockcade.\n",1)
