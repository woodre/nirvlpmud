/* wc changed from 10 to 20, ac changed from 6 to 26 (300 hps rather than level standard 400) -Snow 3/00 */
#include "room.h"

object Gimli;

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
  object weapon;	
object axe;
if (!Gimli || !living(Gimli)) {
  Gimli = clone_object("obj/monster");
call_other(Gimli, "set_name", "gimli");
   call_other(Gimli, "set_a_chat_chance", 25);
call_other(Gimli, "load_a_chat", "Gimli's eyes turn crimson red\n");
call_other(Gimli, "set_hp", 300);
call_other(Gimli, "set_ac", 26);
/* Moved set_wc from here. -Snow 3/00 */
call_other(Gimli, "set_al", 600);
call_other(Gimli, "set_short", "Gimli the sturdy dwarf");
call_other(Gimli, "set_long",
"A sturdy dwarf representing his race in the quest to finish sauron\n");
call_other(Gimli, "set_agressive", 0);
call_other(Gimli, "set_level", 16);
move_object(Gimli, this_object());
weapon=clone_object("obj/weapon");
call_other(weapon, "set_name", "axe");
call_other(weapon, "set_long", "Gimli's double edged battle axe\n");
call_other(weapon, "set_class", 14);
call_other(Gimli, "set_wc", 10);
    call_other(weapon, "set_hit_func", this_object());
call_other(weapon, "set_value", 500);
    call_other(weapon, "set_weight", 2);
call_other(weapon, "set_alt_name", "axe");
move_object(weapon, Gimli);
call_other(Gimli, "init_command", "wield axe");
call_other(Gimli, "set_wc", 10);
  }
}

weapon_hit(attacker) {
  if (random(100) < 30) {
write("Magic flickers from Gimli's axe striking " +attacker->query_name() + "\n");
say(attacker->query_name() + " is shocked by the power of the Axe\n");
return 4;
  }
     return 0;
   }

ONE_EXIT("players/ultramagnus/rohan", "south",
"Gimli's room",
"Here we see Gimli resting after pulling the boats out of the \n"+
"water.  As most dwarfs go, Gimli is short and stout.\n", 1)
