#include "std.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset()
{
    object toyelf, money, hamr;
    int i;

    i = 0;
    if (!present("elf")) {
	while(i<8) {
	    i += 1;
	    toyelf = clone_object("obj/monster");
	call_other(toyelf, "set_name", "elf");
	call_other(toyelf, "set_hp", 50);
call_other(toyelf, "set_ac", 3);
	call_other(toyelf, "set_wc", 4);
	call_other(toyelf, "set_al", 500);
	call_other(toyelf, "set_short", "A small, magical, toy making elf");
	call_other(toyelf, "set_long",
   "This is one of Santa's little helpers.\n");
	call_other(toyelf, "set_aggressive", 0);
call_other(toyelf, "set_level", 2);
	    move_object(toyelf, this_object());
	money = clone_object("obj/money");
        call_other(money, "set_money", random(100));
        move_object(money, toyelf);
hamr = clone_object("obj/weapon");
call_other(hamr, "set_id", "screw driver");
call_other(hamr, "set_name", "screw driver");
call_other(hamr, "set_short", "A small elven screw driver");
call_other(hamr, "set_long", "A small elven screw driver\n");
call_other(hamr, "set_value", 15);
call_other(hamr, "set_weight", 1);
call_other(hamr, "set_class", 4);
move_object(hamr, toyelf);
	}
    }
}

TWO_EXIT("players/boltar/santaland/wk_shp_ent.c", "south",
    "players/boltar/santaland/rndeer.c", "north",
 "The toyelf's place",
  "This appears to be the Santa's main workshop.  There are lots of tables\n"+
  "and supplies here for toy making.  If you're lucky you might see the elves\n"+
  "at work.\n", 1)
