#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
move_object(clone_object(ROOT+"mon/goblin5.c"),this_object());
  if(!arg){
    
set_light(1);
short_desc= ("Deep within the "+BLK+BOLD+"Gundar Caves"+NORM);
long_desc=
"The dark, twisting passages end here, at a small opening within the rock. A\n"+
"dark chute leads down, deep down into the ink blackness of the stone. The only\n"+
"exit from the room seems to be back down the passage south.\n";

items=({
"rock","The rock is darker here then elsewhere within the cave complex",
"passages","The tunnels ends here, a small chute leading down into the mountain",
"stone","The stone is dark here, probably due to an extended lack of sunlight",
"exit","The only exit is south, due to the chute being blocked by debris",
"cave","A dark cave sits upon the facing of a larger rocky outcropping",
"chute","The dark chute leads down into the rock at a sharp angle. You belive its\n"+
     "big enough for someone to "+HIR+"slide"+NORM+" down",
    });

    dest_dir=({
  ROOT+"caves5.c","south",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
add_action("slide_down","slide");
}

search(){
write("You find a small dart, perhaps a tiny crossbow bolt of some kinds. Its age\n"+
      "becomes apparent has it crumbles to dust in your hand.\n");
  say(tp +" searches the area.\n");
 return 1;
}

slide_down(){
/* The chute will lead into the second level of the underdark once it opens */
write("The chute is currently blocked by too much debris to travel through.\n"+
      "It would take too long to clear for you to travel it right now.\n");
return 1;
}

realm() {return "NT"; }
