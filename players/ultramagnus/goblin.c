#include "room.h"

object Goblin;

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
  object weapon;	
object club;
 if (!Goblin || !living(Goblin)) {
  Goblin = clone_object("obj/monster");
   call_other(Goblin,"set_name", "goblin");
   call_other(Goblin, "set_hp", 500);
  call_other(Goblin, "set_ac", 14);
    call_other(Goblin, "set_wc", 20);
  call_other(Goblin, "set_al", -300);
   call_other(Goblin, "set_short", "A huge goblin from moria");
  call_other(Goblin, "set_long",
  "A huge goblin set to guard the area\n");
   call_other(Goblin, "set_agressive", 0);
   call_other(Goblin, "set_level", 20);
   move_object(Goblin, this_object());
    weapon=clone_object("obj/weapon");
  call_other(weapon, "set_name", "black club");
call_other(weapon, "set_long", " A huge black club from a goblin\n");
   call_other(weapon, "set_class", 13);
   call_other(weapon, "set_value", 1500);
    call_other(weapon, "set_weight", 2);
  call_other(weapon, "set_alt_name", "club");
  move_object(weapon, Goblin);
  call_other(Goblin, "init_command", "wield black club");

    }
    }
TWO_EXIT("players/ultramagnus/mines.c", "south",
"players/ultramagnus/orc2.c", "north",
  "Goblin",
"You find yourself in the middle of an open area, between several rocks\n" +
"where foul things come to watch the road \n", 1 )
