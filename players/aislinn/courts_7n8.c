#include "std.h"

object bmachine;
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
extra_reset() {
  if(!bmachine || !living(bmachine)) {
  object platball;
    bmachine = clone_object("obj/monster");
    call_other(bmachine, "set_name","ball machine");
    call_other(bmachine, "set_alias","machine");
    call_other(bmachine, "set_level",11);
    call_other(bmachine, "set_hp",195);
    call_other(bmachine, "set_wc",11);
    call_other(bmachine, "set_ac",13);
    call_other(bmachine, "set_al",-200);
    call_other(bmachine, "set_aggressive",1);
    call_other(bmachine, "set_short","A ball machine");
    call_other(bmachine, "set_long",
      "A somewhat beat-up tennis ball machine, used to train students.\n" +
      "The paint is chipped and it looks as if at least one frustrated\n" +
      "tennis player has vented his frustration on the machine, most\n" +
      "probably with a tennis racquet.\n");
    call_other(bmachine,"set_chance",80);
    call_other(bmachine,"set_spell_mess1","A tennis ball wizzes by your ear");
    call_other(bmachine,"set_spell_mess2","A tennis ball hits you in the face!");
    call_other(bmachine,"set_spell_dam",1);
    move_object(bmachine,this_object());
    platball = clone_object("obj/treasure");
    call_other(platball, "set_id","platinum tennis ball");
    call_other(platball, "set_alias","ball");
    call_other(platball, "set_short","A platinum tennis ball");
    call_other(platball, "set_value",600);
    call_other(platball, "set_weight",2);
    transfer(platball,bmachine);
  }
}
 
ONE_EXIT("players/aislinn/courts_5n6", "south",
	 "Courts 7 and 8",
   "Courts 7 and 8 are abit more worn than the others.  You would guess\n" +
   "that they are used for practice and lessons.  There is a very tall,\n" +
   "wooden back-board behind court 8, for those who wish to practice.\n" +
   "   \n", 1)
