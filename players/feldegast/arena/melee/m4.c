#include "def.h"

inherit AROOM;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Hills";
  long_desc=
"  A gurgling underground stream breaks out of the rock here and forms\n"+
"a small waterfall, plunging into a small pool of crystal clear water\n"+
"before it trickles downhill and to the south.  To the north, the hills\n"+
"become a towering mountain which blocks out the sunlight.  To the east\n"+
"you see a stone ruin on top of a hill.\n";

  
  items=({
    "stream","The stream flies out of a small crack in the rock",
    "rock","These rolling hills are filled with the huge rock formations\n"+
             "which become the mountains to the north",
    "waterfall","A beautiful cascade of foaming water",
    "pool","You seem to see brief snatches of half-forgotten faces and roads\n"+
             "once travelled.  Perhaps you should <"+MAG+"gaze"+NORM+"> into the pool",
    "water","You seem to see brief snatches of half-forgotten faces and roads\n"+
             "once travelled.  Perhaps you should <"+MAG+"gaze"+NORM+"> into the pool",
    "mountain","view_room",
    "ruin","view_room",
  });
  dest_dir=({
    PATH+"m1","north",
    PATH+"m5","east",
    PATH+"m7","south"
  });
}
init() {
  ::init();
  add_action("cmd_gaze","gaze");
}
long(str) {
  if(str=="mountain") view_room(PATH+"m1");
  else if(str=="ruin") view_room(PATH+"m5");
  else ::long(str);
}
cmd_gaze(str) {
  object targ;
  notify_fail("Usage: gaze <player>\n");
  if(!str) return 0;
  targ=find_player(str);
  if(!targ) return 0;
  if(!environment(targ)->query_grand_arena()) {
    write("You can't make out that person.\n");
    return 1;
  }
  if(TP->query_sp() < 20) {
    write("You don't have enough spell points!\n");
    return 1;
  }
  TP->add_spell_point(-20);
  view_room(explode(file_name(environment(targ)),"#")[0]);
  say(TPN+" gazes into the pool of water.\n");
  return 1;
}
