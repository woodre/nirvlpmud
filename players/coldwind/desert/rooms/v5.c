#include "/players/coldwind/define.h"

inherit "room/room";
int i;
reset(arg) {	
if(!present("villager", this_object())){
move_object(clone_object("/players/coldwind/desert/mobs/villagers.c"), this_object());
move_object(clone_object("/players/coldwind/desert/mobs/villagers.c"), this_object());
}
if(!present("ape", this_object())){
move_object(clone_object("/players/coldwind/desert/mobs/apes.c"), this_object());
}
  if(arg) return;
set_light(1);

short_desc = ""+HIY+"Dahna desert"+NORM+"";
long_desc =
"    Pure water pours from a spring into a crystal blue pond.  Palm \n"+
"trees grow high protecting you from the cruel sunrays.  From looking\n"+
"at the burned tents on the east and south side of the pond, you \n"+
"understand that the village has been under a malicious attack \n"+
"recently.  Palm trees had been knocked down leaving a clear sign of\n"+
"destruction as if someone is trying to place a warning.  Some rocks\n"+
"are piled together forming what looks like a rocky hill to your north.\n"+
"The fallen trees block you from proceeding northeast and southeast\n"+
"while the rocks prevent you from going north.\n";

items = ({
  "tents",
  "Burned and destroyed tents extend south and east",
  "sun",
  "The palm trees and the smoke are blocking the sunlight...",
  "sunrays",
  "The palm trees and the smoke are blocking the sunlight...",
  "palm trees",
  "They stand around 30 feet tall, while others have fallen over\n"+
  "some of the tents",
  "fallen trees",
  "Few palm trees have fallen over some tents destroying them and blocking\n"+
  "you from walking northeast and souteast",
  "smoke",
  "Dark smokes rising from the burned tents and preventing you from having \n"+
  "a better look at the sarrounding",
  "spring",
  "Pumping pure water into a small pond, a natural crack made in the rocks",
  "pond",
  "The crystal blue pond reflects the sunlight playfully on your face",
  "rocks",
  "They formed a small pond holding on to the water pumping from the spring",
  "hill",
  "A rocky hill stands 90 feet tall with few cracks toward the bottom. Water \n"+
  "pours out from one of the cracks",
  "cracks",
  "On a closer look, you notice a crack big enough for you to "+BOLD+"squeeze"+NORM+"\n"+
  "yourself north through it",   
  
});

dest_dir = ({
  "/players/coldwind/desert/rooms/v2.c", "south",
  "/players/coldwind/desert/rooms/v4.c", "west",
  "/players/coldwind/desert/rooms/v6.c", "east",
  "/players/coldwind/desert/rooms/v1.c", "southwest",
});

}
init(){
  ::init();
  add_action("squeeze_self", "squeeze");
  }
   squeeze_self(string str){
if(!str){ write("Squeeze yourself where?\n"); return 1; }
	if(str == "north", "in", "hill", "through hill", "rocks", "through rocks", "crack"){
	move_object(this_player(), "/players/coldwind/desert/rooms/v7.c");
say(""+tpn+" arrives.\n");
command("look", this_player());
return 1;
}	
}
	
