#include "std.h"

object old_man;
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
extra_reset() {
  if(!old_man || !living(old_man)) {
  object tbag, money;
    old_man = clone_object("obj/monster");
    call_other(old_man, "set_name","old man");
    call_other(old_man, "set_alias","man");
    call_other(old_man, "set_level",6);
    call_other(old_man, "set_hp",150);
    call_other(old_man, "set_wc",10);
    call_other(old_man, "set_ac",6);
    call_other(old_man, "set_al",100);
    call_other(old_man, "set_short","An elderly man in tennis shorts");
    call_other(old_man, "set_long",
      "An older gentleman stands watching the two women on court 6.  He\n" +
      "is dressed in tennis shorts and wears an izod shirt.  His clothes\n" +
      "are absolutely spotless, and he looks as if he is affluent.\n");
    move_object(old_man,this_object());
    tbag = clone_object("players/aislinn/objects/tbag");
    call_other(tbag, "set_id","racquet bag");
    call_other(tbag, "set_alias","bag");
    call_other(tbag, "set_short","A tennis racquet bag.");
    call_other(tbag, "set_value",150);
    call_other(tbag, "set_weight",2);
    transfer(tbag,old_man);
    money = clone_object("obj/money");
    call_other(money, "set_money",random(200));
    move_object(money,old_man);
  }
}
 
TWO_EXIT("players/aislinn/courts_7n8", "north",
	 "players/aislinn/courts_3n4", "south",
	 "Courts 5 and 6",
   "Court 5 is apparently closed for repairs, since there is no net on\n" +
   "the court.  On court 6 a sedate match is taking place between two\n" +
   "elderly women.  One of the women has blue hair and you stop for a\n" +
   "moment in amazement.\n" +
   "   \n", 1)
