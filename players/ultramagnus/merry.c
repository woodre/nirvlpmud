#include "room.h"

object Merry;

#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();

extra_reset() {
object money, weapon;
object Sword;
if (!Merry ||living(Merry)) {
  money = clone_object("obj/money");
Merry = clone_object("obj/monster");
call_other(Merry, "set_name", "merry");

call_other(Merry, "set_hp", 350);
call_other(money, "set_money", random (250));
call_other(Merry, "set_ac", 6);
call_other(Merry, "set_wc", 12);

call_other(Merry, "set_al", 5000);
call_other(Merry, "set_short", "The hobbit Merry");
call_other(Merry, "set_long",

"Merry and Frodo are good friends, but Merry and Pippin are unseperable\n");

call_other(Merry, "set_level", 16);
move_object(Merry, this_object());
move_object(money, Merry);
weapon=clone_object("obj/weapon");
call_other(weapon, "set_name", "sword");
call_other(weapon, "set_long", "The Barrow weapon that Merry took. \n");
call_other(weapon, "set_class", 14);
call_other(weapon, "set_value", 1350);
call_other(weapon, "set_weight", 1);
move_object(weapon, Merry);
call_other(Merry, "init_command", "wield sword");
    }
}

ONE_EXIT("players/turk/pippin", "south",

 "Hobbits",
"Here we see Merry searching around for his pipe in his bags. \n", 1)
