#include "/players/feldegast/defines.h"
#include "../def.h"
inherit "room/room";
int open;

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="A door in the cliffs";
  long_desc=
"    This is a man-made ledge on the side of the mountain.  It\n"+
"ends in front of a huge stone door set into a cliff.  The\n"+
"statue of a huge winged gargoyle sits in a niche above the door.\n"+
"No sun falls anywhere within a dozen yards of this place and the\n"+
"rocks here seem to resist absorbing any heat.\n";
  items=({
    "ledge","The ledge seems too flat and wide to be natural.  On one side\n"+
            "is a towering cliff, on the other is a fifty foot drop",
    "mountain","It is difficult to get a good view of this towering\n"+
               "edifice as you are currently on it",
    "door","A massive stone door with a family crest on it",
    "crest","The crest is faded, but you can make out a crown"+
            "over a demonic head",
    "rocks","The rocks that make up the ledge are granite, but the\n"+
            "door and gargoyle are something unknown",
    "gargoyle","The stone gargoyle seems to follow you with its eyes.\n"+
               "You could just barely touch it if you wanted to"
  });
  dest_dir=({
    PATH+"trail5","east",
    PATH+"Crypt/crypt1","enter"

  });
}   
init() {
  ::init();
  add_action("cmd_search","search");
  add_action("cmd_touch","touch");
  add_action("cmd_enter","enter");
  add_action("cmd_answer","answer");
}
cmd_search(str) {
  write("You find nothing of interest.\n");
  return 1;
}
cmd_enter() {
  if(open) {
    TP->move_player("in#players/feldegast/realm/crypt1");
    return 0;
  }
  write("The stone door blocks your path.\n");
  return 1;
}
cmd_touch(str) {
  if(str=="gargoyle") {
      write("The gruesome sentinel stirs to life at your touch.\n");
     say(TPN+" jumps back as the gargoyle stirs to life.\n");
    call_out("riddle",15);
    return 1;
  }
  notify_fail("Touch what?\n");
}
riddle() {
  tell_room(this_object(),
"With a voice like rocks rubbing against each other, the gargoyle says:\n"+
"\n\t\tDon't grow attached to this\n"+
"\t\tWithout it, you will never know it is gone\n"+
"\t\tBut be careful, thieves,\n"+
"\t\tIt is much easier to lose it in here.\n\n"+
"You may <answer> or leave.\n"
  );
}
cmd_answer(str) {
  if(!str) {
    write("What is your answer?\n");
    return 1;
  }

  if(str=="life") {
    write("The stone door rumbles open.\n");
    open=1;
    return 1;
  }
  write("The tomb remains closed.\n");
  return 1;
}
