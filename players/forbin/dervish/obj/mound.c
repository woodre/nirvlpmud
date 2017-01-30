/* 
 * Forbin
 * Created:   2003.08.21
 * Last edit: 2003.08.22 -forbin
 */

#include "/players/forbin/define.h"
inherit "/obj/treasure";
#define ROOT "/players/snow/dervish/trials/trail1/"

id(str) { return (::id(str) || str == "mound" || str == "hidden mound"); }

reset(arg) {
  if(arg) return;
   
  set_short();
  set_long("The sand is raised up into an obviously out of place pile, right\n"+
           "in front of your feet.\n");
  set_weight(1000000);
}

init() {
  ::init();
  add_action("cmd_touch","touch");
  add_action("cmd_uncover","uncover");
}

cmd_touch(string str) {
  if(str == "mound") {
    write("You touch a round, gnarled object beneath a layer of sand.  You may\n"+
          "be able to see what it is if you uncover it.\n");
      return 1;
  }
}

cmd_uncover(string str) {
  if(!str || str != "mound") {
    notify_fail("What do you want to uncover?\n");
      return 0;
  }
  write("You carefully brush off the sand to reveal a rugged stone.\n");
  say(CAP(this_player()->query_name())+" uncovers a stone buried in the sand.\n");
  move_object(clone_object(ROOT+"obj/stone.c"),environment(this_object()));
  environment(this_object())->new_look();
  destruct(this_object());
    return 1;
}
