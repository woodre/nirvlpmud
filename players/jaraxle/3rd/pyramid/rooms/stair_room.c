#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

int OPEN;
reset(arg) {
OPEN == 0;
if(present("linger")){
if(arg) return 0;
}
else{
  if(arg) return;
set_light(-1);

long_desc =
  ""+BLK+BOLD+"  A dusty room, filled with spider webs and broken\n"+
  "clay artifacts.  The room is closed in with three\n"+
  "walls to the north with the stairway leading back\n"+
  "into the main chamber of the pyramid. There is no\n"+
  "ceiling to this room, but the top of the pyramid\n"+
  "can be seen from down here.\n"+NORM+"";

items = ({
  "webs","Dust covered webs, partially torn.\nThey seem to have been here for ages",
  "artifacts","Broken vases, cups, and dishes lay about the room.\nThere are some sticking out of a wall",
  "wall","Look at which wall?\nWall 1, wall 2 or wall 3",
  "wall 2","A large wall covered in dust, and spider webs",
  "wall 1","A large wall with a small torch attached",
  "wall 3","A wall which reaches up to the top of the pyramid",
  "stairway","A stone stairway that leads up, into the pyramid",
  "top of pyramid","High above, you see the ceiling to the pyramid",
  "torch","A small wooden torch.\nIt looks as though the torch has been pulled before",
});

MOCO("/players/jaraxle/3rd/pyramid/mon/spirit.c"),TO);
dest_dir = ({
  "/players/jaraxle/3rd/pyramid/rooms/roomw2.c","stairway",
});
}
}
short(){ return ""+BOLD+""+BLK+"Dark Pyramid"+NORM+""; }
realm() { return "NT"; }

init(){
    ::init();
  add_action("pull","pull");
}

pull(arg){
if(arg == "torch"){
write("You pull the torch, and fall through a trap door!\n");
 move_object(this_player(), "/players/jaraxle/3rd/pyramid/rooms/torch_room.c");  
say(TPN+" falls in through the trap door!\n");
return 1; }
}
