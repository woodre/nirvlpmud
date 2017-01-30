#include "std.h"

object scrooge;

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    object money;
    if (!scrooge || !living(scrooge)) {
	scrooge = clone_object("obj/monster");
	call_other(scrooge, "set_name", "scrooge");
	call_other(scrooge, "set_hp", 140);
call_other(scrooge, "set_ac", 8);
	call_other(scrooge, "set_wc", 12);
	call_other(scrooge, "set_al", -500);
	call_other(scrooge, "set_short", "Mr. Scrooge");
	call_other(scrooge, "set_long",
   "An old man dressed in his night clothes, ready to go to bed.\n"+
   "He seems to yelling and pleading with something you cannot see.\n");
	call_other(scrooge, "set_aggressive", 0);
call_other(scrooge, "set_level", 9);
	call_other(scrooge, "set_spell_mess1",
		   "Scrooge says: Bah Humbug!!!");
	call_other(scrooge, "set_spell_mess2",
   " Scrooge says:  Bah Humm-bug!!");
	call_other(scrooge, "set_chance", 30);
call_other(scrooge, "set_chat_chance", 30);
call_other(scrooge, "load_chat", "Scrooge says: This can't be my future!\n");
call_other(scrooge, "load_chat", "Scrooge says: Can it be changed?\n");
call_other(scrooge, "load_chat", "Scrooge screams in terror.\n");
	move_object(scrooge, this_object());
	money = clone_object("obj/money");
        call_other(money, "set_money", random(500));
        move_object(money, scrooge);
    }
}

ONE_EXIT("players/boltar/santaland/snow1.c", "west",
        "The Scrooge room",
    "You have entered a grave yard, before you stands the tombstone of somebody\n"+
    "named Scrooge.  It looks very uncared for. It seems like no one liked\n"+
    "this man at all.\n",1)
