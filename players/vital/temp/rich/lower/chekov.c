#include "std.h"

object chekov;

extra_reset() {
   object weapon;
    if (!present("chekov")) {
	chekov = clone_object("obj/monster");
	call_other(chekov, "set_name", "chekov");
	call_other(chekov, "set_alias", "chekov");
	call_other(chekov, "set_short", "Chekov");
call_other(chekov,"set_long","Pavel Andreivich Chekov\n");
	call_other(chekov, "set_wc", 20);
	call_other(chekov, "set_ac", 10);
call_other(chekov, "set_hp",350);
	call_other(chekov, "set_al", 60);
call_other(chekov, "set_level", 15);
	call_other(chekov, "set_aggressive", 0);
call_other(chekov, "set_chat_chance", 40);
call_other(chekov,"load_chat","Chekov says:The Russians invented everything!!!\n");
call_other(chekov,"load_chat","Chekov says:Where are the nucwear wessels at?\n");
call_other(chekov,"load_chat","Chekov says:Please let Sulu say something besides `yes Captain!!`\n");
	move_object(chekov, this_object());
	weapon = clone_object("obj/weapon");
	call_other(weapon, "set_name", "russian ingenuity");
	call_other(weapon, "set_alias", "ingenuity");
	call_other(weapon, "set_short", "Russian Ingenuity");
	call_other(weapon, "set_class", 13);
	call_other(weapon, "set_weight", 3);
	call_other(weapon, "set_value", 500);
	move_object(weapon, chekov);
    }
}

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

ONE_EXIT("players/rich/lower/hall1d", "east",

         "Security",
         "This is security before you you see\n" +
         "the layouts of the various parts of the\n" +
         "ship on the walls.On another wall you see\n" +
         "Security Chief Chekov`s motto.\n" +
         "    `The Russians inwented ewerything!!!!!'\n" ,
         1)
realm(){return "enterprise";}
