#include "std.h"

object shopkeep;

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    object money;
    object rifle;
    if (!shopkeep || !living(shopkeep)) {
	shopkeep = clone_object("obj/monster");
	call_other(shopkeep, "set_name", "shopkeeper");
call_other(shopkeep, "set_alias", "man");
	call_other(shopkeep, "set_hp", 750);
call_other(shopkeep, "set_ac", 10);
	call_other(shopkeep, "set_wc", 15);
	call_other(shopkeep, "set_al", -150);
	call_other(shopkeep, "set_short", "A shopkeeper");
	call_other(shopkeep, "set_long",
		   "An old man dressed in some strange clothes.\n");
	call_other(shopkeep, "set_aggressive", 0);
call_other(shopkeep, "set_level", 19);
	call_other(shopkeep, "set_spell_mess1",
		   "The shopkeeper shoots his attacker.");
	call_other(shopkeep, "set_spell_mess2",
		   "The shopkeeper shoots you with his rifle!!!");
	call_other(shopkeep, "set_chance", 55);
	move_object(shopkeep, this_object());
call_other(shopkeep, "set_spell_dam", 40);
	money = clone_object("obj/money");
        call_other(money, "set_money", random(1000));
        move_object(money, shopkeep);
rifle = clone_object("obj/weapon");
call_other(rifle, "set_id", "rifle");
call_other(rifle, "set_long", "A good rifle with bayonett, too bad there's no bullets");
call_other(rifle, "set_name", "rifle");
call_other(rifle, "set_class", 14);
call_other(rifle, "set_weight",3);
call_other(rifle, "set_value",1200);
        call_other(rifle, "set_short", "A rifle with bayonett");
        move_object(rifle, shopkeep);
       transfer(shopkeep, "players/boltar/lv2/shop.c");
    }
}

TWO_EXIT("players/boltar/lv1/room2", "east",
	 "players/boltar/lv1/plastiroom", "west",
	 "Hallway of The Big House",
 "This is the middle hall of The Big House. It is in the form of a large arched\n" +
 "passageway.  There are ornatly carved ached supports for the beatifully carved \n" +
  "ceiling.  You stop and think how impressive this must have been when it\n" +
  "was new.\n"
 ,1)
