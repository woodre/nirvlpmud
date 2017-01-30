#include "room.h"

object Gandalf;

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
  object weapon;	
  object glamering;
  if (!Gandalf || !living(Gandalf)) {
    Gandalf = clone_object("obj/monster");
    call_other(Gandalf, "set_name", "gandalf");
    call_other(Gandalf, "set_a_chat_chance", 55);
call_other(Gandalf, "load_a_chat", "Gandalf says: One Ring to rule them all, One  Ring to find them, One Ring to    bring them all, and in Darkness bind them.\n");
	call_other(Gandalf, "set_hp", 1000);
call_other(Gandalf, "set_ac", 17);
/* Moved set_wc from here. -Snow 3/00 */
    call_other(Gandalf, "set_al", 400);
    call_other(Gandalf, "set_short", "The white wizard, Gandalf");
    call_other(Gandalf, "set_long",
"Here we see Gandalf upon Shadowfax, out chasing the Nazgul off\n");
    call_other(Gandalf, "set_agressive", 0);
    call_other(Gandalf, "set_level", 20);
    move_object(Gandalf, this_object());
    weapon=clone_object("obj/weapon");
    call_other(weapon, "set_name", "glamering");
    call_other(weapon, "set_long", "This is the Weapon that Gandalf wears\n");
    call_other(weapon, "set_class", 18);
    call_other(weapon, "set_hit_func", this_object());
    call_other(weapon, "set_value", 10000);
    call_other(weapon, "set_weight", 3);
    call_other(weapon, "set_alt_name", "glamering");
    move_object(weapon, Gandalf);
    call_other(Gandalf, "init_command", "wield glamering");
    call_other(Gandalf, "set_wc", 30);
  }
}

weapon_hit(attacker) {
  if (random(100) < 30) {
    write("Lightning flickers, striking " + attacker->query_name() +"\n");
 say(attacker->query_name() + " is bathed in lightning from Glamering\n");
   return 6;
  }
     return 0;
   }

THREE_EXIT(
"/players/ultramagnus/bridge1.c","east",
"players/ultramagnus/rohan.c", "west",
          "players/ultramagnus/mines.c","north",
     "Gandalf's room",
"Gandalf is astride Shadowfax, armored for war. He is chasing the\n" +
"evil winged Nazgul away from lord Faramir\n", 1)
