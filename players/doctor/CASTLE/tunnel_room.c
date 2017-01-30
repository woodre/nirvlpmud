#include "/room/room.h"

object hobgoblin;

#undef EXTRA_RESET
#define EXTRA_RESET\
    if (!hobgoblin || !living(hobgoblin)) {\
        object money;\
   	hobgoblin = clone_object("obj/monster");\
	call_other(hobgoblin, "set_name", "hobgoblin");\
	call_other(hobgoblin, "set_level", 5);\
        call_other(hobgoblin, "set_wc", 9);\
	call_other(hobgoblin, "set_short", "A generic creature wearing a T-shirt that reads HOBGOBLIN");\
	move_object(hobgoblin, this_object());\
	money = clone_object("obj/money");\
	call_other(money, "set_money", random(50));\
	move_object(money, hobgoblin);\
    }
ONE_EXIT("/players/doctor/CASTLE/tunnel5", "south",
	 "Small generic room",
	 "A small generic room with rough cut generic walls.\n", 0)
