#include "room.h"

object Pippin;

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
object money, weapon;
object Sword;
if (!find_living("pippin")) {
  money = clone_object("obj/money");
 Pippin = clone_object("obj/monster");
  call_other(Pippin, "set_name", "pippin");

  call_other(Pippin, "set_hp", 350);
call_other(money, "set_money", random (250));
call_other(Pippin, "set_ac", 6);
call_other(Pippin, "set_wc", 12);

call_other(Pippin, "set_al", 5000);
call_other(Pippin, "set_short", "The hobbit Pippin");
call_other(Pippin, "set_long",

"Pippin is one of Frodo's personal friends\n");

call_other(Pippin, "set_level", 16);
move_object(Pippin, this_object());
move_object(money, Pippin);
weapon=clone_object("obj/weapon");
call_other(weapon, "set_name", "sword");
call_other(weapon, "set_long", "A Western Barrow sword that Pippin took. \n");
call_other(weapon, "set_class", 14);
call_other(weapon, "set_value", 1350);
call_other(weapon, "set_weight", 1);
move_object(weapon, Pippin);
call_other(Pippin, "init_command", "wield sword");
    }
}

TWO_EXIT("players/turk/boromir", "east",

        "players/turk/merry", "north",
 "Hobbits",
"Here is where Merry and Pippin were while Frodo and Sam left the company\n" +
"for fear of themselves and Boromir.\n", 1)
