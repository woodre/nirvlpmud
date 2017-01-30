#include "room.h"

object Bolrog;

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
object money, weapon;
object armor;
 if (!Bolrog || !living(Bolrog)) {
  money = clone_object("obj/money");
     Bolrog = clone_object("obj/monster");
  call_other(Bolrog, "set_name", "bolrog");
	call_other(Bolrog, "set_hp", 1000);
  call_other(money, "set_money", random (500));
/* Moved set_ac and set_wc from here. -Snow 3/00 */
       call_other(Bolrog, "set_al", -600);
  call_other(Bolrog, "set_short", "A Huge Bolrog");
  call_other(Bolrog,"set_race","devil");
       call_other(Bolrog, "set_long",
"The Bolrog is a huge monster dredged from the foul land of Mordor.\n");
   call_other(Bolrog, "set_aggressive", 1);
 call_other(Bolrog, "set_level", 20);
        move_object(Bolrog, this_object());
       move_object(money, Bolrog);
weapon=clone_object("obj/weapon");
call_other(weapon, "set_name", "whip");
call_other(weapon, "set_long", "A huge whip, powerful in masterly hands\n");
/* Whip wc changed from 12 -Snow 3/00 */
call_other(weapon, "set_class", 16);
call_other(weapon, "set_value", 1000);
call_other(weapon, "set_weight", 1);
call_other(weapon, "set_alt_name", "whip");
move_object(weapon, Bolrog);
Bolrog->init_command("wield whip");
armor = clone_object("/players/ultramagnus/breastplate.c");
move_object(armor, Bolrog);
Bolrog->init_command("wear plate");
call_other(Bolrog, "set_ac", 15);
    call_other(Bolrog, "set_wc", 25);
    }
}

THREE_EXIT("players/ultramagnus/moria.c", "south",
	"players/ultramagnus/orcs.c", "east",
	"players/ultramagnus/gondor_gates.c","north",
    "Bolrog",
"You see standing in the middle of the road a huge Bolrog to\n" +
"Keep aid from reaching the city of Gondor.\n", 1)
