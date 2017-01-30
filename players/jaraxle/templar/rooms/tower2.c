#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(1);
short_desc = "East Tower";
long_desc =
  "   A stairway in a tower.  The stairway continues up\n"+
  "further into the tower, and down to the ground level\n"+
  "into the castle. Paintings continue to line the outer\n"+
  "wall of the tower.  A small lit torch is attached to\n"+
  "an iron hilt, lighting the stairway.\n"; 
items = ({
  "tower","Made of solid stone, the tower rises high above the castle",
  "stairway","A thick wooden stairway.  Splinters of wood reach from the outside\nof the the tower walls to the center of the tower.  The stairway\nleads upward into the top of the tower and down to the castle",
  "paintings","Intricate oil portraits of knights past",
  "torch","An old eternal torch, burning effortlessly",
  "hilt","An old sword's hilt, forged out and made into a torch handle",
  "torch handle","An old sword's hilt, forged out and made into a torch handle",
  "wall","The outer most wall of the tower, it is lined with paintings",
  "outer wall","The outer most wall of the tower, it is lined with paintings",
});

MOCO("/players/jaraxle/templar/mon/rat.c"),TO);
dest_dir = ({
  "/players/jaraxle/templar/rooms/tower3.c","up",
  "/players/jaraxle/templar/rooms/tower.c","down",
});

}

 init(){
        ::init();
this_player()->set_fight_area();
}
exit(){    if(this_player()) this_player()->clear_fight_area();     }

