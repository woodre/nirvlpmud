#include "std.h"

object helmet;

extra_reset() {
   object weapon;
    if (!present("helmet")) {
	helmet = clone_object("obj/monster");
	call_other(helmet, "set_name", "dark helmet");
	call_other(helmet, "set_alias", "helmet");
	call_other(helmet, "set_level", 13);
	call_other(helmet, "set_short", "Dark Helmet");
call_other(helmet,"set_long","A short nerdy man in a black outfit wearing a black helmet.\n");
	call_other(helmet, "set_wc", 18);
	call_other(helmet, "set_ac", 4);
	call_other(helmet, "set_al", -150);
call_other(helmet, "set_hp", 300);
	call_other(helmet, "set_aggressive", 1);
call_other(helmet, "set_chat_chance", 40);
call_other(helmet,"load_chat","Dark Helmet says: I am your fathers brothers cousins best friends exroomate that makes us NOTHING!\n");
call_other(helmet,"load_chat","Dark Helmet says: my schwartz is bigger than your schwartz!\n");
call_other(helmet,"load_chat","Dark Helmet says: I`m surrounded by A******s!!!\n");
	move_object(helmet, this_object());
	weapon = clone_object("obj/weapon");
	call_other(weapon, "set_name", "ring");
	call_other(weapon, "set_alias", "schwartz ring");
	call_other(weapon, "set_short", "schwartz ring");
	call_other(weapon, "set_class", 12);
	call_other(weapon, "set_weight", 2);
	call_other(weapon, "set_value", 1500);
	move_object(weapon, helmet);
    }
}

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

TWO_EXIT("players/rich/quest/hall3.c", "north",
          "players/rich/quest/hall1.c", "south",

         "a hallway",
         "To the north and south are hallways.\n",
          1)
realm(){return "NT";}
