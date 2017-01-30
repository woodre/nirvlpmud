#include "std.h"

object plasticop;
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();
extra_init() {
     add_action("look", "look");
     add_action("look", "l");
     add_action("look", "examine");
     add_action("look", "search");
  }
look(str) {
   if (!str) {
   return 0;
  }
 if (str == "at desk") {
  write("An old grey metal desk. It has nothing inside of it.\n");
   return 1;
  }
return 0;
}

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    object money;
    object billy;
    if (!plasticop || !living(plasticop)) {
	plasticop = clone_object("obj/monster");
	call_other(plasticop, "set_name", "plasticop");
call_other(plasticop, "set_alias", "cop");
	call_other(plasticop, "set_hp", 150);
call_other(plasticop, "set_ac", 5);
	call_other(plasticop, "set_wc", 0);
	call_other(plasticop, "set_al", 200);
call_other(plasticop, "set_whimpy");
	call_other(plasticop, "set_short", "A plasticop");
	call_other(plasticop, "set_long",
		   "An overweight man dressed in some strange clothes.\n");
	call_other(plasticop, "set_aggressive", 0);
call_other(plasticop, "set_level", 10);
	call_other(plasticop, "set_spell_mess1",
		   "The plasticop shoots his attacker.");
	call_other(plasticop, "set_spell_mess2",
		   "The plasticop shoots you!!!");
	call_other(plasticop, "set_chance", 50);
	move_object(plasticop, this_object());
call_other(plasticop, "set_spell_dam", 100);
	money = clone_object("obj/money");
        call_other(money, "set_money", random(200));
        move_object(money, plasticop);
billy = clone_object("obj/weapon");
call_other(billy, "set_id", "billy");
call_other(billy, "set_name", "billy club");
call_other(billy, "set_alias", "club");
call_other(billy, "set_class", 7);
call_other(billy, "set_weight",1);
call_other(billy, "set_value",4);
        call_other(billy, "set_short", "A billy club");
        move_object(billy, plasticop);
    }
}

FOUR_EXIT("players/boltar/lv1/dnroom.c", "west",
	 "players/boltar/lv1/nixonroom.c", "south",
 "players/boltar/lv1/room4.c", "north",
 "players/boltar/lv1/room3.c", "east",
     "The Plasti-room",
 "This room was once very grand, however all of the gold leaf and all of the\n" +
 "orimentation has long been removed by thieves.  There seems to be\n" +
 "some new purpose for this now dirty run down area.  The desk in corner seems\n" +
 "to be the station of some sort of guardian.\n", 1)
