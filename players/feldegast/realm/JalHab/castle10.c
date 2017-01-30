#include "defs.h"

inherit ROOM;

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc=BOLD+BLK+"Castle Magnarn"+NORM;
  long_desc=
"  This is a large gallery about twenty meters across.  It appears\n\
to be a central point with tunnels leaving it from the four compass\n\
directions.  The tunnel to the north has an ornate archway decorated\n\
with demonic symbols.  In the middle of the cave is a campsite with\n\
a small fire burning.\n";
  items=({
    "gallery", "reflexive",
    "tunnels", "The tunnels lead in the compass directions",
    "tunnel", "The tunnel to the north has an ornate archway decorated\n"+
              "with demonic symbols",
    "cave", "reflexive",
    "archway", "The archway is decorated by demonic heads with sharp fangs and\n"+
               "demonic symbols written in black",
    "symbols", "You haven't the foggiest idea what they mean",
    "campsite", "There are a few minor items scattered in a circle around\n"+
                "the fire",
   "fire", "It burns poorly and creates a great deal of smoke which brings\n"+
            "tears to your eyes",
  });
  dest_dir=({
    PATH+"castle13.c", "north",
    PATH+"castle11.c","west",
    PATH+"castle12.c","east",
    PATH+"castle9.c","south",
  });
}

void init() {
  ::init();
  add_action("cmd_north", "north");
}

cmd_north(str) {
  if(TP->query_alignment() > 800) {
    write(HIR+"You feel ill as you pass through the demonic archway.\n"+NORM);
    say(TPN+" looks ill.\n");
    TP->add_hit_point(-random(15));
  }
  return cmd_move(str);
}
