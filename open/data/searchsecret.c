#include "/players/coldwind/define.h"

inherit "room/room";
reset(arg) {	
  if(arg) return;
set_light(1);

short_desc = ""+HIY+"Dahna desert"+NORM+"";
long_desc =
"    In every direction, the sandy wind is blowing and the sun is \n"+
"shooting it's burning sunrays.  As you look downward, You can see a \n"+
"well used path leading toward a far oasis to the southeast and coming\n"+
"from the heart of the desert.  As you look upward, you see the rocky \n"+
"mountain towers high reaching the clouds.  Random caves and curves\n"+
"decorate the giant mountain.\n";

items = ({
  "oasis",
  "You can see the palm trees towering to the southeast",
  "palm trees",
  "Their stems look spiky and carry red palm fruits",
  "path",
  "The constant travel through this area made the sand more\n"+
  "dense, forming a sandy path that leads west toward the\n"+
  "endless desert and southeast to a distant oasis",
  "desert",
  "The sand spreads around covering the face of the desert",
  "sun",
  "It's hard to look at the sun directly!",
  "sand",
  "The soft sand spreads covering the face of the earth",
  "ground",
  "The dark brown ground is solid, while rocks of different sizes \n"+
  "are scattered around", 
  "mountain",
  "A giant rocky mountain with random caves and curves decorate its body",
  "rocks",
  "Dark brown rocks of different sizes",
  "caves",
  "Small holes were formed in the giant mountain. They would make\n"+
  "great shelters from the direct sunlight and the sandy wind.\n"+
  "You notice a nearby cave to the "+BOLD+"west"+NORM+"",
  "curves",
  "It might be possible to "+BOLD+"descend or climb"+NORM+" up using the natural curves in the rocky mountain",
  
});


}

init(){
  ::init();
  add_action("climb_up", "climb");
  add_action("west_cave", "west");
  add_action("west_cave", "w");
  add_action("descending", "descend");
    add_action("find_it", "search");
  }
  find_it(){
  write("You notice many caves and curves in the mountain.\n");
  return 1;
   }
  descending(){
move_object(this_player(), "/players/coldwind/desert/rooms/r3.c");
say(""+tpn+" arrives.\n");
command("look", this_player());
return 1;
}
  climb_up(){
move_object(this_player(), "/players/coldwind/desert/rooms/ma3.c");
say (""+tpn+" arrives.\n");
command("look", this_player());
return 1;
}	

  west_cave(){
  
move_object(this_player(), "/players/coldwind/desert/rooms/ma2.c");
say(""+tpn+" arrives.\n");
command("look", this_player());
return 1;
}
	