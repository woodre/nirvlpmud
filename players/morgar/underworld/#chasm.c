#include "std.h"

object balrog;

#undef EXTRA_INIT
#define EXTRA_INIT extra_init();

extra_init() {
#ifndef __LDMUD__ /* Rumplemintz */
    add_action("spellfail"); add_verb("fireball");
    add_action("spellfail"); add_verb("shock");
    add_action("spellfail"); add_verb("missile");
#else
  add_action("spellfail", "fireball");
  add_action("spellfail", "shock");
  add_action("spellfail", "missile");
#endif
}

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

ONE_EXIT("players/morgar/underworld/brink", "up",
	 "The Balrog's chasm",
	 "You are in a deep chasm, the lair of the dreaded balrog.\n" 
         , 0)

realm() { return "under"; }

extra_reset() {
    object treasure;
    if (!balrog || !living(balrog)) {
	balrog = clone_object("obj/monster");
	call_other(balrog, "set_name", "balrog");
	call_other(balrog, "set_alias", "demon");
	call_other(balrog, "set_level", 19);
        call_other(balrog, "set_hp", 475);
	call_other(balrog, "set_short", "A balrog");
	call_other(balrog, "set_wc", 28);
	call_other(balrog, "set_ac", 16);
	call_other(balrog, "set_al", -1200);
	call_other(balrog, "set_aggressive", 1);
        call_other(balrog, "set_chance",35);
        call_other(balrog, "set_spell_mess1",
                   "The balrog casts a deadly spell.");
        call_other(balrog, "set_spell_mess2",
                   "The balrog wounds you with a deadly spell.");
        call_other(balrog, "set_spell_dam",40);
	move_object(balrog, this_object());
	treasure = clone_object("obj/treasure");
	call_other(treasure, "set_id", "emerald");
	call_other(treasure, "set_alias", "gem");
	call_other(treasure, "set_short", "A giant emerald");
	call_other(treasure, "set_weight", 3);
	call_other(treasure, "set_value", 5000);
	move_object(treasure, balrog);
    }
}

spellfail(arg) {
    if (!balrog || !living(balrog)) return 0;
    if (arg && arg != "balrog") return 0;
    write ("Spells are useless against the the Balrog.\n");
    return 1;
}
