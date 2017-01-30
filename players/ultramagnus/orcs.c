#include "room.h"

object Orc;

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
 object weapon, money;
  object sword;
 if (!Orc || !living(Orc)) {
   Orc = clone_object("obj/monster");
  call_other(Orc, "set_name", "orc");
  call_other(Orc, "set_a_chat_chance", 20);
call_other(Orc, "load_a_chat", "Orc says: gnash wabash shlav\n");
	call_other(Orc, "set_hp", 800);
call_other(Orc,"set_ac",19);
/* Set wc moved from here. -Snow 3/00 */

  call_other(Orc, "set_al", -175);
  call_other(Orc, "set_short", "A flat-footed orc");
 call_other(Orc, "set_long",
"A rather large orc, with a red lidless eye on his forehead\n");
call_other(Orc, "set_aggressive", 1);
  call_other(Orc, "set_level", 20);
  move_object(Orc, this_object());
    weapon=clone_object("obj/weapon");
 money=clone_object("obj/money");
call_other(money, "set_money", random (250));
move_object(money, Orc);
  call_other(weapon, "set_name", "curved sword");
  call_other(weapon, "set_long", "A curved sword taken from an orc\n");
call_other(weapon, "set_class", 16);
call_other(weapon, "set_value", 4000);
    call_other(weapon, "set_weight", 2);
  call_other(weapon, "set_alt_name", "sword");
  move_object(weapon, Orc);
  call_other(Orc, "init_command", "wield curved sword");
call_other(Orc,"set_wc",18);
  }
   }
ONE_EXIT("players/ultramagnus/mines.c","west",

"Orc tunnels",
"Here stands your destiny.  A huge orc.\n"+
"To the east you see the entrance to Sauron's castle...\n",1)
