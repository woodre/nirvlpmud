/*
  vampire_speed.c - a doohickey to let vamps do an action twice
*/

#include "/players/nooneelse/black/lib/defs.h"

inherit "obj/treasure";

string hasted_command;
int haste_counter;
object my_player;

query_save_flag() { return 1; }

get() { return 1; }

drop() { return 1; }

reset(arg) {
  if (arg) return;

  set_value(0);
  set_weight(0);
}

set_vampire_speed(str) {
  hasted_command=str;
  add_action("haste_command", hasted_command);
  call_out("end_vampire_speed", 180);
}

query_vampire_speed() { return hasted_command; }

end_vampire_speed() {
  tell_object(my_player, "\nYou can no longer focus your energies.  "+
                         "Your speed returns to normal.\n");
  destruct(this_object());
}

set_my_player(arg) { my_player=arg; }
query_my_player() { return my_player; }

haste_command(str) {
  if (haste_counter==1) {
    haste_counter=0;
    return 0;
  }
  haste_counter++;
  if (str)
    command(hasted_command+" "+str, my_player);
  else
    command(hasted_command, my_player);
}

id(str) { return (str=="vampire guild speed" ||
                  str=="vampire guild speed" ||
                  str=="vampire guild speed marker" ||
                  str=="vampire guild speed marker" ||
                  str=="speed marker" ||
                  str=="marker" ||
                  str=="speed");
}
