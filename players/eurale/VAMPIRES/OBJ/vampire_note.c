/*
  Trialmaster note fro DCing during combat
*/

#include "/players/eurale/defs.h"

inherit "obj/treasure";

reset(arg) {
  if (arg) return;

set_short("A small slip of paper");
set_long(
  "A small slip of paper with a note, scrawled in blood that could\n"+
  "probably be read.\n");
set_value(1);
set_weight(1);
}

id(str) { return(
  str == "vampirenote" ||
  str == "note" ||
  str == "paper"); }

init() {
  ::init();
  add_action("read","read");
}

read(str) {
if(!str) { write("Read what?\n"); return 1; }
if(str == "note" || str == "paper") {
  write(HIR+"\nThe note says:\n"+
        "For whatever reason, you either could not continue or you\n"+
        "elected to try to cheat your way through your trial so I\n"+
        "left to go do other things.  I will inform the elders of\n"+
        "your feeble attempt to try to circumvent the trial process\n"+
        "and leave your fate in their hands.  Next time we meet, I\n"+
        "hope you will come to me better prepared.  You should be\n"+
        "ashamed of yourself for this effort!\n"+
        "                                   Vampire Trialmaster\n\n"+NORM);
  return 1; }
}
