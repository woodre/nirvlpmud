#include "std.h"

object troi;

extra_reset() {
   object weapon;
    if (!present("troi")) {
	troi = clone_object("obj/monster");
	call_other(troi, "set_name", "deanna troi");
	call_other(troi, "set_alias", "troi");
	call_other(troi, "set_level", 15);
	call_other(troi, "set_short", "Deanna Troi");
call_other(troi,"set_long","Counselor Deanna Troi\n");
call_other(troi,"set_long","Counselor Deanna Troi\n");
	call_other(troi, "set_wc", 15);
	call_other(troi, "set_ac", 5);
call_other(troi, "set_hp",350);
	call_other(troi, "set_al", 60);
	call_other(troi, "set_aggressive", 0);
call_other(troi, "set_chat_chance", 40);
call_other(troi,"load_chat","Deanna Troi says: I am the goddess of empathy!\n");
call_other(troi,"load_chat","Deanna Troi says: cast away your sorrows and fears!!\n");
call_other(troi,"load_chat","Deanna Troi says: Embrace love,beauty,joy and happiness!!!\n");
	move_object(troi, this_object());
	weapon = clone_object("obj/weapon");
	call_other(weapon, "set_name", "book");
	call_other(weapon, "set_alias", "psychology book");
	call_other(weapon, "set_short", "book");
call_other(weapon, "set_long", "psychology book\n");
	call_other(weapon, "set_class", 13);
	call_other(weapon, "set_weight", 3);
	call_other(weapon, "set_value", 700);
	move_object(weapon, troi);
    }
}

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

ONE_EXIT("players/rich/lower/hall4d", "east",

         "Deanna Troi`s Quarters",
         "This is Deanna Troi`s room on the walls are cabinets filled with books,\n" +
         "in the center of the room you see a psychiatrist`s couch.\n" +
         "To the east you see a hallway.\n",
       1)
realm(){return "enterprise";}
