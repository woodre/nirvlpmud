#include "std.h"
 
object fan;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
    if (!present("mallet")) {
        string weapon;
        weapon = clone_object("obj/weapon");
        call_other(weapon, "set_name", "Polo Mallet");
	call_other(weapon, "set_alias", "mallet");
        call_other(weapon, "set_class", 6);
        call_other(weapon, "set_value", 15);
        call_other(weapon, "set_weight", 3);
	move_object(weapon, this_object());
    }
    if (!fan || !living(fan)) {
	fan = clone_object("obj/monster.talk");
	call_other(fan, "set_name", "polo fan");
        call_other(fan, "set_alias", "fan");
	call_other(fan, "set_level", 3);
	call_other(fan, "set_al", 143);
	call_other(fan, "set_race", "human");
	call_other(fan, "set_long",
            "A Polo fan in an Hawaiian shirt, sunglasses, bermuda shorts,\n" +
            "with a camera hanging around his neck.  He looks Latino.\n");
	call_other(fan, "set_chat", 3);
	call_other(fan, "set_hp", 42);
	move_object(fan, this_object());
	call_other(fan, "set_object", this_object());
        call_other(fan, "set_function", "said");
        call_other(fan, "set_type", "says:");
	call_other(fan, "set_match", " ");
	call_other(fan, "set_chat_chance", 5);
	call_other(fan, "set_a_chat_chance", 20);
	call_other(fan, "load_chat",
            "Fan says:  A donde esta el partido de Polo?\n");
         call_other(fan, "load_a_chat",
            "Fan says:  Con perdone!  No hablo Ingles!!!\n");
	call_other(fan, "load_a_chat",
            "Fan shouts:  Socorro!  Por favor!\n");
    }
}

THREE_EXIT("players/aislinn/polo3", "west",
	 "players/aislinn/polo1", "east",
	 "players/aislinn/stables/2stables", "north",
	 "Viewing Area",
     "You are standing in front of some wooden stands where spectators\n" +
     "of the matches can sit and watch.  The playing field is currently\n" +
     "empty and the stands are deserted.\n" +
     "   \n", 1)
 
said(str) {
    say("The fan says: Con perdone!  No hablo Ingles!!!\n");
    return 1;
}
 
