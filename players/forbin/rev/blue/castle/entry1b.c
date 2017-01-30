#include "/players/forbin/rev/blue/pathdef.h"
inherit "/players/vertebraker/closed/std/room";

reset(arg) {
  if(arg) return;
  short_desc = "A passage";
  long_desc = 
    "A stone passageway leads from a metal gate to what looks like an\n"+
    "inner courtyard.  The rough hewn walls slope gently inward before\n"+
    "rounding overhead to form a barrel ceiling.  Moss and grass peek\n"+
    "through cracks and joints of the tile floor.  Several smoldering\n"+
    "torches burn near the gate, while sunlight from the courtyard\n"+
    "brightly illuminates the northern third of the passage.\n";
  set_light(1);
  add_item(({"passage","passageway","stone passage","stone passageway"}),
    "");
  add_item(({"gate","metal gate"}),
    "");
  add_item("courtyard",
    "");
  add_item(({"wall","walls","rough hewn wall","rough hewn walls"}),
    "");
  add_item(({"ceiling","barrel ceiling"}),
    "");
  add_item("moss",
    "");
  add_item("grass",
    "");
  add_item(({"crack","joint","cracks","joints"}),
    "");
  add_item(({"floor","tile floor"}),
    "");
  add_item(({"tile","tiles"}),
    "");
  add_item(({"torch","torches"}),
    "");    
  add_item(({"light","sunlight"}),
    "");
  add_exit(ROOT+"castle/courtyard","north");
  add_exit(ROOT+"castle/entry","south");
}

void init() {
  ::init();
  add_action("cmd_lift", "lift");
  add_action("cmd_move","south");  
}

status cmd_move() {
  if(query_verb() = "south") {
    write(
      "The metal gate blocks your path.  Maybe if you lifted it, you\n"+
      "could hurry pass.\n");
    return 1;
  }
}

status cmd_lift(string str) {
     if(!str || str != "gate") return 0;
     if (this_player()->query_level() < 13) {
       write(
         "You pull with all your might, but the gate refuses to budge.\n"+
         "You are too small to lift the gate.\n");
       return 1;
     }
     write(
       "You lift the gate and quickly walk under it.\n"+
       "It crashes down loudly down behind you.\n");
     this_player()->move_player("beyond the gate#"+ROOT+"castle/entry1");
     return 1;
}
