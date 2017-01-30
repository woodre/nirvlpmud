#include "/room/room.h"
object k9;
#undef EXTRA_RESET
#define EXTRA_RESET\
  extra_reset();

extra_reset() {
  object money;
  if (!k9 || !living(k9)) {
    k9=clone_object("obj/monster");
    call_other(k9, "set_name", "k9");
    call_other(k9, "set_level", 9);
    call_other(k9, "set_hp", 200);
    call_other(k9, "set_wc", 15);
    call_other(k9, "set_al", 1000);
    call_other(k9, "set_short", "K-9 the Doctor's robot dog");
    call_other(k9, "set_aggressive", 0);
    move_object(k9, this_object());
    money=clone_object("obj/money");
    call_other(money, "set_money", random(500));
    move_object(money, k9);
  }
}

ONE_EXIT("/players/doctor/TARDIS/corridor3","out",
"Workroom",
"You find yourself in what appears to be some kind of a workroom.\n"+
"You see around you a work bench with strange tools which you do not \n"+
"recognize laying around in a most disorderly fashion.\n",1)
