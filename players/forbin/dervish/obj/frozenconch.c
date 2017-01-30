/* 
 * Forbin
 * Created:   2003.08.29
 * Last edit: 2003.08.29 -forbin
 * Change log:
 */

#include "/players/forbin/define.h"
inherit "/obj/treasure";
#define ROOT "/players/snow/dervish/trials/trial1/"

id(str) { return (::id(str) || str == "shell" || str == "conch" 
                            || str == "conch shell"
                            || str == "frozen shell"); }

reset(arg) {
  if(arg) return;
   
  set_short("A large conch shell ("+HIC+"FrOZeN"+NORM+")");
  set_long("  This rather large conch shell has been hollowed out to make a\n"+
           "horn of some sort.  Who knows how long it has been buried in\n"+
           "the snow; it's frozen solid and ice cold.  Through the thin\n"+
           "layer of ice, you can make out a red squiggle on its side.\n"+
           "You can 'blow' the shell.\n");
  set_weight(2);
  set_value(212);
}

set_no_clean(1);

init() {
  ::init();
  add_action("cmd_blow","blow");
}

cmd_blow(string arg) {
  if(!arg) return 0;
  if(arg != "shell" && arg != "conch" && arg != "conch shell") {
    notify_fail("Blow what?\n"); 
      return 0;
  }
  write("You place the shell to you lips and start to blow, but the ice cold\n"+
        "shell freezes your lips.  Maybe you could find a way to thaw it.\n");
  say(this_player()->query_name()+" freezes his lips on the frozen shell.\n");
    return 1;
}
