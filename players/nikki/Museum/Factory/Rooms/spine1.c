#include "/players/nikki/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg) {
   if(!arg) {
set_light(3);
short_desc = HIW+"Wax Factory"+NORM;
long_desc = HIW+
 "   A long corridor beams brightly from the extremely white walls,\n"+
 "spotless tile floors and luminous lights.  Pictures and windows line\n"+
 "the walls down the hall.  To the left there is another small hallway\n"+
 "that leads to the Gowning rooms.\n"+NORM;

items = ({
  "walls","The walls are stark white and seem to be very clean",
  "pictures","Pictures of the factory are hung on the walls",
  "floors","The tiled floors shine from constant cleaning and waxing",
  "lights","Halogen lights fill the corridor with almost blinding light",
  "hallway","A small hallway leading to the gowning rooms",
  "windows","Several windows line the walls",
  "corridor","The corridor glows from the illuminated walls and floors",
  "hall","The hall seems very long and eeriely quiet",
  "rooms","The rooms can't be seen from here",
});
dest_dir = ( {
    "players/nikki/Museum/Rooms/hall6.c", "backward",
    
});
} }

realm() { return "NT"; }

init() {
  ::init();
     add_action("open"); add_verb("open");
}
lift(arg) {
  if(arg != "door") {
     write("Open what?\n");
     return 1;
  }    
  TP->move_player("opens the door and leaves#players/nikki/Museum/Rooms/hall6");
  return 1;
}

