#include "std.h"

object ball;

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();
    
extra_reset() {
    object money;
    if (!ball || !living(ball)) {
	ball = clone_object("obj/monster");
	call_other(ball, "set_name", "ball");
	call_other(ball, "set_alias", "waterpolo ball");
	call_other(ball, "set_level", 7);
	call_other(ball, "set_hp", 100);
	call_other(ball, "set_wc", 9);
	call_other(ball, "set_ac", 5);
	call_other(ball, "set_al", 0);
	call_other(ball, "set_short", "A waterpolo ball");
	call_other(ball, "set_long",
	  "A waterpolo ball is floating on the water....\n");
	move_object(ball, this_object());
	money = clone_object("obj/money");
        call_other(money, "set_money", random(300));
        move_object(money, ball);
    }
}
    
TWO_EXIT("players/aislinn/poolside", "west",
         "players/aislinn/pool_medium", "east",
	 "In the pool, shallow end",
    "The water feels wonderful in the heat of the sun, and is a lovely,\n" +
    "clear, blue in color.  It is extremely tempting to just sit down \n" +
    "and bask in the sun....\n" +
    "    \n", 1)
