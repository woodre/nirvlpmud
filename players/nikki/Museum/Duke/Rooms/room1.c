#include "/players/nikki/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg) {
   if(!arg) {
set_light(1);
short_desc = HIC+"The Duke's Career"+NORM;
long_desc = HIC+
 "   This room seems to be the exact replica of the exhibit.  The rope is\n"+
 "blocking the path to outside of the exhibit.  There are rooms within the\n"+
 "exhibit that were not noticeable from the other side of the rope. A spiral\n"+
 "staircase leading upstairs is also visible.\n"+NORM;

items = ({
  "rooms","The rooms are dark but are open for exploration",
  "staircase","A deep mahogany spiral staircase leads to the upstairs.",
  "rope","The same red velvet rope barricades the path to outside the exhibit.",
});
dest_dir = ( {
    "players/nikki/Museum/Duke/Rooms/room2", "left",
    "players/nikki/Museum/Duke/Rooms/room3", "right",
    "players/nikki/Museum/Duke/Rooms/room4", "forward",
    "players/nikki/Museum/Duke/Rooms/room5", "up",
});
} }

realm() { return "NT"; }

init() {
  ::init();
     add_action("lift"); add_verb("lift");
}
lift(arg) {
  if(arg != "rope") {
     write("Lift what?\n");
     return 1;
  }    
  TP->move_player("in a cloud of Mist#players/nikki/Museum/Duke/Rooms/exhibit");
  return 1;
}

