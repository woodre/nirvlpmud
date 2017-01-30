#include "defs.h"

inherit MAPROOM;

object *squires;
object *cultists;

void reset(int arg) {
  int i;
  string dest;
  if(!arg) {
    squires=allocate(3);
    cultists=allocate(3);
    no_clean=1;
  }
  if(sscanf(file_name(this_object()),"%s#%s",dest,dest)!=2)
    return;
  for(i=0; i < 3; i++) {
    if(!squires[i]) {
      squires[i]=clone_object(MON_PATH+"squire.c");
      switch(random(4)) {
        case 0: dest=PATH+"castle1.c"; break;
        case 1: dest=PATH+"castle2.c"; break;
        case 2: dest=PATH+"castle3.c"; break;
        case 3: dest=PATH+"castle4.c"; break;
      }
      move_object(squires[i],dest);
    }
    if(!cultists[i]) {
      cultists[i]=clone_object(MON_PATH+"cultist.c");
      switch(random(3)) {
        case 0: dest=PATH+"castle9.c"; break;
        case 1: dest=PATH+"castle10.c"; break;
        case 2: dest=PATH+"castle11.c"; break;
      }
      move_object(cultists[i],dest);
    }
  }
  if(arg) return;
  set_light(1);
  short_desc="Castle Magnarn";
  long_desc=
"  A large stone edifice sits atop a small mesa in the middle of the\n\
Jal-Hab.  A rope snakes down from the northern face and you notice a\n\
cave in the mesa's western face.\n";
  items=({
    "edifice", "It appears to be a ruined castle",
    "mesa", "The mesa is not very large, and relatively circular.\n"+
            "The cliff walls are about fifty meters high",
    "rope", "The rope is tied to a wall near the edifice.  It appears to be\n"+
            "secure",
    "cave", "The cave is about thirty yards up on the western face",
  });
  dest_dir=({
    "blank", "north",
    "blank", "west",
    "blank", "east",
    "blank", "south",
  });
}

void init() {
  ::init();
  add_action("cmd_climb", "climb");
  add_action("cmd_enter", "enter");
}

int cmd_climb(string str) {
  if(str=="rope" || str=="northern face") {
    write("You climb the northern face and over the castle's walls.\n");
    say(TPN+" climbs up to the castle.\n");
    move_object(TP,PATH+"castle1.c");
    say(TPN+" climbs up from below.\n");
    command("look",TP);
    return 1;
  }
  if(str=="western face") {
    write("You climb the western face and enter the cave.\n");
    say(TPN+" climbs up the western face.\n");
    move_object(TP,PATH+"castle9.c");
    say(TPN+" climbs up from below.\n");
    return 1;
  }
  notify_fail("Climb what?\n");
}

int cmd_enter(string str) {
  if(str=="cave") {
    write("You enter the cave on the western face.\n");
    say(TPN+" enters the cave.\n");
    move_object(TP,PATH+"castle9.c");
    say(TPN+" climbs up from below.\n");
    return 1;
  }
  notify_fail("Enter what?\n");
}

    