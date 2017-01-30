#include "def.h"
inherit "obj/treasure";

reset(arg) {
  if(arg)return;
  set_id("rock");
  set_alias("stone");
  set_short(BLK+BOLD+"Stone"+NORM+" of the "+MAG+"Magi"+NORM);
  set_long(
"This is a large round rock about as tall as your waist, etched\n"+
"with intricate runes, faded by time.  The sun itself seems to fade\n"+
"into dull hues whenever you see this stone and you wonder what\n"+
"sort of dweomer enchants it.  You think that you could <"+BLU+"roll"+NORM+">\n"+
"the stone if you wanted to.\n");
  set_value(10000);
  set_weight(999);
}
get() { return 0; }
init() {
  environment(TP)->set_no_magic(1);
  add_action("cmd_roll","roll");
}
cmd_roll(str) {
  string *dests;
  string dest;
  int index;
  notify_fail("Usage: roll <direction>\n");
  if(!str) return 0;
  dests=environment(this_object())->query_dest_dir();
  index=member_array(str,dests);
  if(index<0) {
    write("You cannot push the stone that way.\n");
    return 1;
  }
  dest=dests[index-1];
  write("You roll the stone "+str+".\n");
  say(TPN+" rolls the stone "+str+".\n");
  environment()->set_no_magic(0);
  if(dest) move_object(this_object(),dest);
  else {
    write("You can't roll it that way.\n");
    return 1;
  }
  say("A large round stone rolls into the room.\n");
  return 1;
}
