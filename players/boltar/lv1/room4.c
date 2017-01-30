#include "std.h"

object goldeat;
int count;
object lostgold;
 int mon, eatmoney, plymon;

#undef EXTRA_RESET
#define EXTRA_RESET\
    if (!find_living("goldeat"))\
        starta_goldeat();


TWO_EXIT("players/boltar/lv1/stairroom.c", "west",
	   "players/boltar/lv1/plastiroom", "south",
	   "The Night Gallery",
   "This area has black walls placed in front of the decorative walls of\n" +
   "the rest of the house.  There are many paintings on the black walls and\n" +
   "floating in the center.\n", 1)

starta_goldeat() {
    if(!goldeat || !living(goldeat)) {
	goldeat = clone_object("obj/monster.c");
	call_other(goldeat, "set_name", "creature");
	call_other(goldeat, "set_short", "A small golden creature");
	call_other(goldeat, "set_long",
  "A small, fat, gold colored creature with four limbs and a very large mouth.\n" +
  "It makes a sound of coins knocking against one another as it moves.\n" +
  "\n");
	call_other(goldeat, "set_ac", 9);
	call_other(goldeat, "set_level",12);
	call_other(goldeat, "set_al",125);
	call_other(goldeat, "set_hp",140);
	call_other(goldeat, "set_wc",12);
	call_other(goldeat, "set_aggressive", 0);
move_object(goldeat, "players/boltar/lv1/room4");
	call_other(goldeat, "set_object", this_object());
	call_other(goldeat, "set_function", "eatgold");
	call_other(goldeat, "set_type", "arrives");
	call_other(goldeat, "set_match", "");
call_other(goldeat, "set_function", "eatgold");
call_other(goldeat, "set_type", "hit");
call_other(goldeat, "set_match", "");
call_other(goldeat, "set_function", "eatgold");
call_other(goldeat, "set_type", "missed");
call_other(goldeat, "set_match", "");
call_other(goldeat, "set_function", "eatgold");
call_other(goldeat, "set_type", "leaves");
call_other(goldeat, "set_match", "");
	
    }
}

eatgold(str) {
   string who, ext;
   sscanf(str, "%s %s\n", who, ext);
   lostgold = find_player(lower_case(who));
   if (lostgold == 0) {
    return 1;
}
     mon = 0 - random(300) - 1;
      count = call_other(lostgold, "query_money", 0);
     plymon = 0 - count;
     if (mon < plymon) {
        mon = plymon;
        }
        eatmoney = 0 - mon/3;
       if(mon == 0) {
   tell_object(lostgold, "The creature finds you have no money and gets very angry.\n"+
   "The creature bites you very hard.\n");
    call_other(lostgold, "add_hit_point", -10);
    }
    call_other(lostgold, "add_money", mon);
    call_other(goldeat, "add_money", eatmoney);
     tell_object(lostgold, "The creature eats your money!!\n");
   return 1;
  }
