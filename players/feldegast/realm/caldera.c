#include "/players/feldegast/defines.h"
#include "def.h"

int puzzle;

inherit ROOM;

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc="Caldera";
  long_desc=
"  You stand on the rim of a caldera atop what was once, long ago,\n\
an active volcano.  Time and precipitation have turned the bottom of\n\
the caldera into a lake.  An obsidian spire rises up out of the lake,\n\
the top of some structure you can't make out.\n";
  items=({
    "lake","An obsidian spire rises up out of the murky water",
    "spire","The spire has four sides, like an elongated pyramid",
    "structure","Some large structure lies beneath the lake, but you cannot\n"+
                "make it out",
  });
  dest_dir=({
    PATH+"volcano2","descend",
  });
}
void init() {
  ::init();
  add_action("cmd_enter","enter");
}

void set_puzzle(int arg) {
  if(arg) {
    long_desc=
"  You stand on the rim of a caldera atop what was once, long ago,\n\
an active volcano.  Time and precipitation had turned the bottom of\n\
the caldera into a lake, but the water has been drained and some sort\n\
of obsidian shrine has been revealed.\n";
    items=({
      "lake","There is no lake anymore",
      "spire","The spire has four sides, like an elongated pyramid",
      "structure","The structure has been revealed to be an obsidian shrine",
      "shrine","The shrine is all planes and sharp angles, a cold emotionless\n"+
               "place, that seems to lack spirit",
    });
  }
  puzzle=arg;
}
int cmd_enter(string str) {
  if(!str || str!="shrine") {
    notify_fail("Enter what?\n");
    return 0;
  }
  write("You enter the obsidian shrine.\n");
  say(TPN+" enters the obsidian shrine.\n");
  move_object(TP,PATH+"obsidian_shrine");
  return 1;
}
