#include "room.h"

object Legolas;

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
  object weapon;	
object bow;
if (!Legolas ||!living(Legolas)) {
 Legolas = clone_object("obj/monster");
call_other(Legolas, "set_name", "legolas");
call_other(Legolas, "set_alt_name", "elf");
call_other(Legolas, "set_a_chat_chance", 14);
call_other(Legolas, "load_a_chat", "Legolas shouts: Annon edhellen, edro hi ammen! \n");
/* Hp changed from 750 -Snow 3/00 */
call_other(Legolas,"set_hp", 400);
call_other(Legolas, "set_ac", 23);
call_other(Legolas, "set_al", 900);
call_other(Legolas, "set_short", "Legolas the fair elf");
call_other(Legolas, "set_long",
"A fair elf representing his race in the quest to end the ring\n");
call_other(Legolas, "set_agressive", 0);
call_other(Legolas, "set_level", 17);
move_object(Legolas, this_object());
weapon=clone_object("obj/weapon");
call_other(weapon, "set_name", "bow");
call_other(weapon, "set_long", "The slender elven bow that Legolas used.\n");
call_other(weapon, "set_class", 16);
    call_other(weapon, "set_hit_func", this_object());
call_other(weapon, "set_value", 1100);
    call_other(weapon, "set_weight", 2);
call_other(weapon, "set_alt_name", "bow");
move_object(weapon, Legolas);
call_other(Legolas, "init_command", "wield bow");
  }
}

weapon_hit(attacker) {
  if (random(100) < 30) {
write("Legolas hits " +attacker->query_name() + " with a well placed arrow\n");
say(attacker->query_name() + " gets hit by a well placed elven arrow\n");
return 4;
  }
     return 0;
   }

TWO_EXIT("players/ultramagnus/gondor_gates.c","south",
	"players/ultramagnus/bar_gondor.c","west",

"The City of Gondor",
"You have just climbed the walls into this beautify city...\n"+
"Here, on you see Legolas getting ready to join the guards on\n"+
"the walls of the city.  Around you, this city is still rather lively...\n"+
"To the west you see a bar, the north the palace, to the south the chaos\n"+
"from which you came, and to the east a street that seems to\n"+
"guard tower...\n",1)
