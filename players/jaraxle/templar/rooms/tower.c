#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
if(!present("templar_guard", this_object())){
move_object(clone_object("players/jaraxle/templar/mobs/templar_security.c"),this_object());
}
  if(arg) return;
set_light(1);
short_desc = "East Tower";
long_desc =
"  This is the foyer of a large and open tower.  To the north is a\n"+
"vine covered archway.  From the south a small scent of insence can\n"+
"be detected.  A dark feeling occupies the space overhead where a\n"+
"dark stairway disappears into the shadow of the top of the tower.\n";
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

dest_dir = ({
  "/players/jaraxle/templar/rooms/tower2.c","up",
  "/players/jaraxle/templar/rooms/garden.c","north",
  "/players/jaraxle/templar/rooms/hallway1.c","east",
  "/players/jaraxle/templar/rooms/library.c","south",
});

}

 init(){
        ::init();
this_player()->set_fight_area();
}
exit(){    if(this_player()) this_player()->clear_fight_area();     }

