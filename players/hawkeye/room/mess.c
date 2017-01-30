#include "room.h"

object igor;
object hawkeye;

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    object money;
    if (!hawkeye) { /* /07/04/06 Earwax */
        hawkeye=clone_object("players/pain/NEW/mon/korean.c");
        move_object(hawkeye,this_object());
    }
    if (!igor || !living(igor)) {
	igor = clone_object("obj/monster");
/*changed from monster_lars to monster. lars is only for old village things.-Bp*/
	call_other(igor, "set_name", "igor");
	call_other(igor, "set_level", 4);
	call_other(igor, "set_hp", 60);
	call_other(igor, "set_wc", 8);
     call_other(igor, "set_al", 77);
	call_other(igor, "set_short", "Igor");
	call_other(igor, "set_long",
              "The camp cook, Igor.\n");
	call_other(igor, "set_spell_mess1",
		   "Igor says: I just serve the slop");
	call_other(igor, "set_spell_mess2",
                   "Igor says:  I hate the Army.");
	call_other(igor, "set_chance", 20);
	move_object(igor, this_object());
	money = clone_object("obj/money");
        call_other(money, "set_money", random(200));
        move_object(money, igor);
    }
}

TWO_EXIT("players/hawkeye/room/rd2.c", "east",
     "players/hawkeye/room/offclub.c", "west",
      "The mess tent",
   "This is the famed mess tent of the famed 4077th.\n"+
       "The place where the words food and garbage mean\n"+
       "the same thing. Look around but if you eat the\n"+
       "we are not responsible for what happens to you!.\n",1)
