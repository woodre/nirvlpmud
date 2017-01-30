#include "std.h"

object cricketeer;
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
extra_reset() {
  if(!cricketeer || !living(cricketeer)) {
  object weapon, armor;
    cricketeer = clone_object("obj/monster");
    call_other(cricketeer,"set_name","cricketeer");
    call_other(cricketeer,"set_alias","player");
    call_other(cricketeer,"set_level",6);
    call_other(cricketeer,"set_hp",100);
    call_other(cricketeer,"set_wc",8);
    call_other(cricketeer,"set_ac",6);
    call_other(cricketeer,"set_al",250);
    call_other(cricketeer,"set_short","A cricket player");
    call_other(cricketeer,"set_long",
      "A cricket player, waiting for his turn at bat.\n");
    move_object(cricketeer,this_object());
    weapon = clone_object("obj/weapon");
    call_other(weapon,"set_name","cricket bat");
    call_other(weapon,"set_alias","bat");
    call_other(weapon,"set_short","A cricket bat");
    call_other(weapon,"set_class",8);
    call_other(weapon,"set_value",80);
    call_other(weapon,"set_weight",3);
    transfer(weapon,cricketeer);
    armor = clone_object("obj/armor");
    call_other(armor,"set_name","shin guards");
    call_other(armor,"set_alias","guards");
    call_other(armor,"set_short","shin guards");
    call_other(armor,"set_value",40);
    call_other(armor,"set_ac",1);
    call_other(armor,"set_weight",1);
/*
    call_other(armor,"set_type","shin guards");
Chg'd for nirvana -Bp
*/
    call_other(armor,"set_type","pants");
    move_object(armor,this_object());
    transfer(armor,cricketeer);
  }
}
 
ONE_EXIT("players/aislinn/cricket1", "west",
	 "Cricket Field",
   "This is a large grassy area that has been set aside for those who wish\n" +
   "to play cricket.  In fact, a game is currently in progress.  It would \n" +
   "be very inadvisable to try to proceed forward, as you might get hit by\n" +
   "a ball!\n" +
   "    \n", 1)
