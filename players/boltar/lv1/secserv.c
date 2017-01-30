#include "std.h"

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
 if (str == "at desk" || str == "desk") {
  write ("An old gray metal desk with a lighted box on it.\n");
   return 1;
  }
return 0;
}
object agent;
object tv;

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
    object money;
    object walkie;
    if (!tv || !present(tv)) {
   tv = clone_object("players/boltar/things/stv.c");
   move_object(tv, this_object());
   }
    if (!agent || !living(agent)) {
	agent = clone_object("obj/monster");
	call_other(agent, "set_name", "agent");
call_other(agent, "set_alias", "service");
	call_other(agent, "set_hp", 180);
call_other(agent, "set_ac", 7);
	call_other(agent, "set_wc", 13);
	call_other(agent, "set_al", 200);
call_other(agent, "set_whimpy");
	call_other(agent, "set_short", "A secret service agent");
	call_other(agent, "set_long",
		   "A very well trained looking man wearing dark sunglasses.\n");
	call_other(agent, "set_aggressive", 0);
call_other(agent, "set_level", 12);
	call_other(agent, "set_spell_mess1",
		   "The agent shoots his attacker.");
	call_other(agent, "set_spell_mess2",
		   "The agent shoots you!!!");
	call_other(agent, "set_chance", 50);
	move_object(agent, this_object());
call_other(agent, "set_spell_dam", 20);
	money = clone_object("obj/money");
        call_other(money, "set_money", random(400));
        move_object(money, agent);
walkie = clone_object("obj/treasure");
call_other(walkie, "set_id", "walkie");
call_other(walkie, "set_name", "walkie talkie");
call_other(walkie, "set_alias", "talkie");
call_other(walkie, "set_weight",1);
call_other(walkie, "set_value",300);
        call_other(walkie, "set_short", "A walkie talkie");
        move_object(walkie, agent);
    }
}

THREE_EXIT("players/boltar/lv1/nixonroom.c", "west",
 "players/boltar/lv1/itroom.c", "east",
 "players/boltar/lv1/k_ent.c", "south",
  "the agent's area",
 " This room looks like the entrance area, yet it has been converted into\n"+
 " an office like area. In the northwest corner there is a desk with some\n"+
 " strange equipment on it.  There is a dark tunnel to the south.\n", 1)
