#include "def.h"

inherit AROOM;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc=BOLD+BLK+"Chasm"+NORM;
  long_desc=
"  This is a small, narrow chasm with sharp, high walls that form a\n"+
"'V'.  The bottom of the chasm is filled with rocks, shrubs, and other\n"+
"detritus that has been casually tossed down here.  High above you is\n"+
"a bridge that crosses the crevice.  To the north, the chasm becomes\n"+
"too narrow to navigate, but to the south it rises up to the top of the\n"+
"wall.\n";  
  items=({
    "walls","The walls are high and offer few handholds, but you think you\n"+
            "could <"+HIG+"climb"+NORM+"> them",
    "bottom","It's filled with rocks, shrubs, tribbles, anti-matter, my Uncle Hesie..",
    "rocks","As fascinating as you find the rocks, perhaps you should pay attention\n"+
            "to the insane killer standing right behind you?  I think so too",
    "killer","Made you look",
    "shrubs","Brown vegetation barely clinging to its meager existence",
    "detritus","Leaves, twigs, and other rocks",
    "bridge","The George Washington bridge!  What's that doing here?",
    "crevice","What you're in",
    "chasm","What you're in",
  });
  dest_dir=({
    PATH+"m5","south"
  });
}
long(str) {
  if(str=="bridge") view_room(PATH+"m2");
  else ::long(str);
}

init() {
  ::init();
  add_action("cmd_climb","climb");
}
cmd_climb(str) {
  notify_fail("Climb what?\n");
  if(!str) { return 0;}
  if(str!="wall" &&
     str!="crevice" &&
     str!="walls" &&
     str!="chasm") return 0;
  if(TP->query_attrib("ste")+TP->query_attrib("str") < random(50)) {
    write("You make it halfway up the wall before plummeting down\n"+
          "to rocky ground.\n");
    say(TPN+" tries to climb the canyon wall, but falls off halfway.\n");
    TP->hit_player(20);
    return 1;
  }
  write("You painstakingly climb up the chasm wall to the bridge above.\n");
  say(TPN+" painstakingly climbs up the chasm wall to the bridge above.\n");
  move_object(TP,PATH+"m2");
  command("look",TP);
  say(TPN+" climbs up from the chasm below.\n");
  return 1;
}
