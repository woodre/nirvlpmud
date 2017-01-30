#include "/room/room.h"
object susan;
#undef EXTRA_RESET
#define EXTRA_RESET\
  extra_reset();

extra_reset() {
  object money;
  if (!susan || !living(susan)) {
    susan=clone_object("obj/monster");
    call_other(susan, "set_name", "susan");
    call_other(susan, "set_level", 15);
    call_other(susan, "set_hp", 10000);
    call_other(susan, "set_ac",12);
    call_other(susan, "set_wc", 20);
    call_other(susan, "set_al", 1000);
    call_other(susan, "set_short", "Susan the Doctor's granddaughter");
    call_other(susan, "set_aggressive", 0);
    move_object(susan, this_object());
    money=clone_object("obj/money");
    call_other(money, "set_money", 100+random(1000));
    move_object(money, susan);
  }
}

ONE_EXIT("/players/doctor/TARDIS/corridor4","out",
"Laboratory",
"You find yourself in what appears to be some kind of a laboratory.\n"+
"You look around and see experiments that appear to be incomplete. \n"+
"You see all kinds of notes and books scattered around the room.\n",1)
