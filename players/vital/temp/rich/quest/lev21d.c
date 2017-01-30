#include "std.h"

object trekkie;

#undef EXTRA_INIT
#define EXTRA_INIT extra_init();

extra_init() {
    add_action("spellfail","flare");
    add_action("spellfail"); add_verb("fireball");
    add_action("spellfail"); add_verb("shock");
    add_action("spellfail"); add_verb("missile");
}

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

FOUR_EXIT("players/rich/quest/lev21c.c", "up",
           "players/rich/quest/lev23a.c", "down",
           "players/rich/quest/lev24c.c", "north",
           "players/rich/quest/main2.c", "west",
 "A convention room",
	 "You are in a convention room, the lair of the dreaded ultimate trekkie.\n", 1)


extra_reset() {
    object tape;
    if (!trekkie || !living(trekkie)) {
	trekkie = clone_object("obj/monster");
call_other(trekkie,"set_name","ultimate trekkie");
	call_other(trekkie, "set_alias", "trekkie");
	call_other(trekkie, "set_level", 5);
        call_other(trekkie, "set_hp", 300);
        call_other(trekkie, "set_ep", 10);
	call_other(trekkie, "set_short", "The Ultimate Trekkie");
	call_other(trekkie, "set_wc", 35);
	call_other(trekkie, "set_ac", 30);
	call_other(trekkie, "set_al", 200);
	call_other(trekkie, "set_aggressive", 1);
        call_other(trekkie, "set_chance",45);
        call_other(trekkie, "set_spell_mess1",
                   "The ultimate trekkie throws his collection.");
        call_other(trekkie, "set_spell_mess2",
                   "The ultimate trekkie hits you with his collection.");
        call_other(trekkie, "set_spell_dam",35);
	move_object(trekkie, this_object());
	tape = clone_object("players/rich/quest/questtape.c");
	move_object(tape, trekkie);
    }
}

spellfail(arg) {
    if (!trekkie || !living(trekkie)) return 0;
    if (arg && arg != "trekkie") return 0;
    write ("Spells are useless against the the Ultimate Trekkie.\n");
    return 1;
}
realm(){return "NT";}
