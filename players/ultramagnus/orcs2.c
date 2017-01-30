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
     call_other(Orc, "set_hp", 350);
  call_other(Orc, "set_ac", 7);
   call_other(Orc, "set_wc", 7);

  call_other(Orc, "set_al", -175);
call_other(Orc, "set_short", "An orc clad for war");
 call_other(Orc, "set_long",
"A rather large orc captain, with a red lidless eye on his \n"+
"forehead.  He is mustering up the next assault\n");
  call_other(Orc, "set_level", 16);
  move_object(Orc, this_object());
    weapon=clone_object("obj/weapon");
 money=clone_object("obj/money");
call_other(money, "set_money", random (250));
move_object(money, Orc);
call_other(weapon, "set_name", "bloody curved sword");
  call_other(weapon, "set_long", "A curved sword taken from an orc\n");
  call_other(weapon, "set_class", 7);
  call_other(weapon, "set_value", 600);
    call_other(weapon, "set_weight", 2);
  call_other(weapon, "set_alt_name", "sword");
  move_object(weapon, Orc);
call_other(Orc, "init_command", "wield sword");
  }
   }
THREE_EXIT("players/ultramagnus/goblin.c", "south",
     "players/ultramagnus/orcs3.c", "west",
.c"players/ultramagnus/aragorn", "east",

"Orc gathering",
"This is where the evil Nazgul gather their forces for another\n" +
"assault on Gondor.  As you look around you see that war has already\n"+
"been here.  There are dead bodies of fair men, Orcs, Goblins,\n"+
"and and many other foul creatures of war unknown to you.\n"+
"It would appear that to be here would require a strong will or\n"+
"great might of arms.\n", 1)
