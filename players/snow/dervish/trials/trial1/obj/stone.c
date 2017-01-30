/* 
 * Forbin
 * Created:   2003.08.21
 * Last edit: 2003.08.22 -forbin
 */

#include "/players/forbin/define.h"
inherit "/obj/treasure";
#define ROOT "/players/snow/dervish/trials/trail1/"

id(str) { return (::id(str) || str == "stone"); }

reset(arg) {
  if(arg) return;
   
  set_short(YEL+"A gnarled stone"+NORM);
  set_long("  A small, gnarled stone pokes through the desert floor.  It appears\n"+
           "that someone has brushed the sand away to reveal it.\n");
  set_weight(1000000);
}

init() {
  ::init();
  add_action("cmd_touch","touch");
  add_action("cmd_twist","twist");
}

cmd_touch(string str) {
  if(str == "stone" || str == "gnarled stone") { 
    write("The stone is attached loosely to something beneath it.  It wobbles\n"+
          "slightly as your hand touches it - you may be able to twist it.\n");
      return 1;
  }
}

cmd_twist(string str) {
  if(!str || (str != "stone" && str != "gnarled stone")) {
    notify_fail("Twist what?\n");
      return 0;
  }
  write("You struggle, but finally twist the stone.\n");
  say(this_player()->query_name()+" twists the stone.\n");
  if(!present("pillarcall",this_player()) {
    move_object(clone_object(ROOT+"obj/pillarcall.c"),this_player());
    write("There is a slight click as you turn it.  A loud hum begins\n"+
          "to roar.\n\n");
    say("A loud hum begins to roar.\n\n");
      return 1;
  }
  write("Nothing happens.\n");
    return 1;
}
