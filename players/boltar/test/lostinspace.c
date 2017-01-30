#include "std.h"

object robot,will,judy,smith,don;

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    object money;
    if (!don || !living(don)) {
	don = clone_object("obj/monster");
	call_other(don, "set_name", "don");
	call_other(don, "set_level", 5);
	call_other(don, "set_hp", 90);
call_other(don, "set_ac", 6);
	call_other(don, "set_wc", 7);
	call_other(don, "set_al", 200);
	call_other(don, "set_short", "Astro the dog");
	call_other(don, "set_long",
    "You seem to rembemer this toon from somewhere.\n");
	call_other(don, "set_aggressive", 0);
	move_object(don, this_object());
	money = clone_object("obj/money");
        call_other(money, "set_money", random(150));
        move_object(money, don);
    }

    if (!smith || !living(smith)) {
	smith = clone_object("obj/monster");
	call_other(smith, "set_name", "smith");
	call_other(smith, "set_level", 3);
	call_other(smith, "set_hp", 70);
call_other(smith, "set_ac", 4);
	call_other(smith, "set_wc", 4);
	call_other(smith, "set_al", 200);
	call_other(smith, "set_short", "Jane his wife");
	call_other(smith, "set_long",
    "You seem to rembemer this toon from somewhere.\n");
	call_other(smith, "set_aggressive", 0);
	move_object(smith, this_object());
	money = clone_object("obj/money");
        call_other(money, "set_money", random(150));
        move_object(money, smith);
    }

    if (!judy || !living(judy)) {
	judy = clone_object("obj/monster");
	call_other(judy, "set_name", "judy");
	call_other(judy, "set_level", 3);
	call_other(judy, "set_hp", 55);
call_other(judy, "set_ac", 3);
	call_other(judy, "set_wc", 4);
	call_other(judy, "set_al", 200);
	call_other(judy, "set_short", "daughter Judy");
	call_other(judy, "set_long",
    "You seem to rembemer this toon from somewhere.\n");
	call_other(judy, "set_aggressive", 0);
	move_object(judy, this_object());
	money = clone_object("obj/money");
        call_other(money, "set_money", random(150));
        move_object(money, judy);
    }

    if (!will || !living(will)) {
	will = clone_object("obj/monster");
	call_other(will, "set_name", "will");
	call_other(will, "set_level", 3);
	call_other(will, "set_hp", 50);
call_other(will, "set_ac", 3);
	call_other(will, "set_wc", 5);
	call_other(will, "set_al", 200);
	call_other(will, "set_short", "his boy Elroy");
	call_other(will, "set_long",
    "You seem to rembemer this toon from somewhere.\n");
	call_other(will, "set_aggressive", 0);
	move_object(will, this_object());
	money = clone_object("obj/money");
        call_other(money, "set_money", random(150));
        move_object(money, will);
    }

    if (!robot || !living(robot)) {
	robot = clone_object("obj/monster");
	call_other(robot, "set_name", "robot");
	call_other(robot, "set_level", 4);
	call_other(robot, "set_hp", 70);
call_other(robot, "set_ac", 4);
	call_other(robot, "set_wc", 6);
	call_other(robot, "set_al", 200);
	call_other(robot, "set_short", "Meet George Jetson");
	call_other(robot, "set_long",
    "You seem to rembemer this toon from somewhere.\n");
	call_other(robot, "set_aggressive", 0);
	move_object(robot, this_object());
	money = clone_object("obj/money");
        call_other(money, "set_money", random(200));
        move_object(money, robot);
    }

}

TWO_EXIT("players/boltar/endless3.c", "west",
	 "players/boltar/endless2.c", "east",
        "The Jetson's room",
        " You are still in the cartoon area, the hallway looks endless.\n", 1)
