#include "room.h"

object Nazgul;

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
  object weapon;	
object armor;
if (!Nazgul|| !living(Nazgul)) {
  Nazgul = clone_object("obj/monster");
   call_other(Nazgul, "set_name", "nazgul");
   call_other(Nazgul, "set_a_chat_chance", 35);
call_other(Nazgul, "load_a_chat", "Nazgul says: Never come between a nazgul and its prey!! \n");

call_other(Nazgul, "set_hp", 1000);
/* Set wc moved from here. -Snow 3/00 */
call_other(Nazgul, "set_al", -5000);
call_other(Nazgul, "set_short", "A black cloaked Nazgul");
call_other(Nazgul, "set_long",
"You begin to tremble as you find yourself in front \n" +
"of one of the nine ring wraiths\n");
call_other(Nazgul, "set_race", "devil");
call_other(Nazgul, "set_agressive", 1);
call_other(Nazgul, "set_level", 20);
move_object(Nazgul, this_object());
    weapon=clone_object("obj/weapon");
call_other(weapon, "set_name", "fear");
call_other(weapon, "set_long", "Fear---> A good weapon for anything\n");
call_other(weapon, "set_class", 19);
    call_other(weapon, "set_hit_func", this_object());
    call_other(weapon, "set_value", 8000);
    call_other(weapon, "set_weight", 3);
call_other(weapon, "set_alt_name", "fear");
move_object(weapon, Nazgul);
call_other(Nazgul, "init_command","wield fear");
armor = clone_object("/players/ultramagnus/breastplate.c");
move_object(armor, Nazgul);
Nazgul->init_command("wear plate");
call_other(Nazgul, "set_ac", 17);
call_other(Nazgul, "set_wc", 30);
Nazgul->set_alt_name("demon");
  }
}

weapon_hit(attacker) {
  if (random(100) < 30) {
write("Fear strikes at the heart of " +attacker->query_name() + "\n");
say(attacker->query_name() + " is struck down in pure terror.\n");
   return 6;
  }
     return 0;
   }

TWO_EXIT("players/ultramagnus/mines.c","south",
	"players/ultramagnus/ins_gondor.c","north",
"The Gates of Gondor",
"You are at the huge gates of Gondor.  The gates are closed at the moment.\n"+
"In front of them is a large, evil Nazgul.  The Nazgul seems to be looking for something to kill...\n"+
"It seems that the city is preparing for a siege...\n"+
"You see the guards in the towers scanning the horizons for something...\n",1)
