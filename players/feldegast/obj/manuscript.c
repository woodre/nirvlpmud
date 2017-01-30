#include "/players/feldegast/defines.h"
inherit "/obj/treasure";

reset(arg) {
  set_id("manuscript");
  set_short("An illuminated manuscript");
  set_weight(2);
  set_long(
"The manuscript is a thick tome with leather covers delicately\n"+
"etched in gold leaf.  A seal in the form of a silver wolfshead\n"+
"is set into the cover.  The pages of this manuscript are\n"+
"painstakingly detailed using exotic inks and masterful\n"+
"illustrations.  You could probably barter it for alot of money\n"+
"to the proper buyer.\n");
  set_value(2500);
  set_read("Sadly, you are unable to understand this language.\n");
}
init() {
  ::init();
  add_action("cmd_barter","barter");
}
cmd_barter(str) {
  if(str=="manuscript") {
    if(present("bedira",environment(TP))) {
      write("Bedira looks delighted to see the manuscript and gives you\n"+
            value+" coins for it.\n");
      TP->add_money(2500);
      destruct(this_object());
      return 1;
    }
  }
  notify_fail("Barter what?\n");
}
