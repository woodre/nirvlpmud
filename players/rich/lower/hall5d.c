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
	call_other(helmet, "set_al", -50);
call_other(helmet, "set_hp", 300);
	call_other(helmet, "set_aggressive", 0);
call_other(helmet, "set_chat_chance", 40);
call_other(helmet,"load_chat","Dark Helmet says: I am your fathers brothers cousins best friends exroomate that makes us NOTHING!\n");
call_other(helmet,"load_chat","Dark Helmet says: my schwartz is bigger than your schwartz!\n");
call_other(helmet,"load_chat","Dark Helmet says: I'm surrounded by Assholes!!!\n");
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

FOUR_EXIT("players/rich/lower/room2d", "west",
          "players/rich/lower/atrans", "east",
          "players/rich/lower/hall4d", "south",
          "players/rich/lower/bbridge", "north",

         "a hallway",
         "To the north is the battle bridge,\n" +
         "To the south is a hall,to the west a room,\n" +
         "and to the east is the auxiliary transporter room.\n",
         1)
realm(){return "enterprise";}
