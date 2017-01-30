#include "std.h"

object trekkie;

#undef EXTRA_INIT
#define EXTRA_INIT extra_init();

extra_init() {
    add_action("spellfail","fireball");
    add_action("spellfail","shock");
    add_action("spellfail","missile");
}

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

ONE_EXIT("players/rich/quest/main2.c", "up",
 "A convention room",
	 "You are in a convention room, the lair of the dreaded ultimate trekkie.\n", 1)


extra_reset() {
    object treasure;
    if (!trekkie || !living(trekkie)) {
	trekkie = clone_object("obj/monster");
call_other(trekkie,"set_name","ultimate trekkie");
	call_other(trekkie, "set_alias", "trekkie");
	call_other(trekkie, "set_level", 5);
        call_other(trekkie, "set_hp", 300);
        call_other(trekkie, "set_ep", 1000000);
	call_other(trekkie, "set_short", "The Ultimate Trekkie");
	call_other(trekkie, "set_wc", 20);
	call_other(trekkie, "set_ac", 14);
	call_other(trekkie, "set_al", 200);
	call_other(trekkie, "set_aggressive", 1);
        call_other(trekkie, "set_chance",45);
        call_other(trekkie, "set_spell_mess1",
                   "The ultimate trekkie throws his collection.");
        call_other(trekkie, "set_spell_mess2",
                   "The ultimate trekkie hits you with his collection.");
        call_other(trekkie, "set_spell_dam",35);
	move_object(trekkie, this_object());
	treasure = clone_object("obj/treasure");
	call_other(treasure, "set_id", "emerald");
	call_other(treasure, "set_alias", "gem");
	call_other(treasure, "set_short", "A  emerald");
	call_other(treasure, "set_weight", 3);
	call_other(treasure, "set_value", 500);
	move_object(treasure, trekkie);
    }
}

spellfail(arg) {
    if (!trekkie || !living(trekkie)) return 0;
    if (arg && arg != "trekkie") return 0;
    write ("Spells are useless against the the Ultimate Trekkie.\n");
    return 1;
}
