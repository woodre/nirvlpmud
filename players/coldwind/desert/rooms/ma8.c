#include "/players/coldwind/define.h"

inherit "room/room";
reset(arg) {	
if(!present("giant", this_object())){
move_object(clone_object("/players/coldwind/desert/mobs/gyellow.c"), this_object());
}
if(!present("villager", this_object())){
move_object(clone_object("/players/coldwind/desert/mobs/villagers.c"), this_object());
move_object(clone_object("/players/coldwind/desert/mobs/villagers.c"), this_object());
}
  if(arg) return;
set_light(1);

short_desc = ""+HIY+"Dahna desert"+NORM+"";
long_desc =
"    You have entered what looks like Ashgan's workroom.  Some \n"+
"villagers and giants are tied by thier legs to the walls by strong \n"+
"long chains.  A small table has been placed in the northeast corner \n"+
"of the room.  The floor is completely covered by a blue carpet.  \n"+
"Someone has spent a great deal of time and effort to flatten the \n"+
"brown walls.  Some wooden stairs are leading upstairs.\n";

items = ({
  "workroom",
  "A large room with a small opening in the ceiling. A blue carpet covers the\n"+
  "floor and a small table stands in the northeast corner",
  "room",
"A large room with a small opening in the ceiling. A blue carpet covers the\n"+
  "floor and a small table stands in the northeast corner",
    "ceiling",
  "It has a small opening leading back to the altar",
  "villagers",
  "Some frightened villagers were brought here to serve Ashgan needs",
  "giants",
  "Giants of different colors were brought here to allow the evil souls to take\n"+
  "over their minds before they are added to Ashgan's army",
  "walls",
  "Smooth brown walls except for some cracks caused by the giants as they madly\n"+
  "pound the walls. Strong rings were fixed in the walls",  
  "cracks",
  "Some cracks are made in the smooth walls from the pounding of the mad giants",
  "rings",
  "These are metal rings attached to long chains and fixed in the walls",
  "chains",
  "Long chains made from a strange material. Each attached to the wall\n"+
  "by a strong ring from one side, while the other side is tied to\n"+
  "the giants' and villagers' legs bu another ring",
  "table",
  "A small wooden table stands in the northeast corner carrying some tools ",
  "tools",
  "Sharp tools of different sizes are placed on the small table. Probably \n"+
  "Ashgan used them to satisify her sadistic needs",
  "carpet",
  "A deep blue carpet made from a strange material covers the floor completely",
  "floor",
  "A blue carpet covers the floor completely",
  "opening",
  "A small opening in the ceiling",
  "stairs",
  "Wooden stairs leading up through a small opening in the ceiling",
  
});


}

init(){
  ::init();
  add_action("up_stairs", "stairs");
   add_action("up_stairs", "up");
  add_action("up_stairs", "u");
  }
up_stairs(){
 move_object(this_player(), "/players/coldwind/desert/rooms/ma7.c");
say(""+tpn+" arrives.\n");
command("look", this_player());
return 1;
}

	