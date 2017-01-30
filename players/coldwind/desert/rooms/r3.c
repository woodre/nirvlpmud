#include "/players/coldwind/define.h"

inherit "room/room";
reset(arg) {	
if(!present("villager", this_object())){
move_object(clone_object("/players/coldwind/desert/mobs/villagers.c"), this_object());
move_object(clone_object("/players/coldwind/desert/mobs/villagers.c"), this_object());
}
  if(arg) return;
set_light(1);

short_desc = ""+HIY+"Dahna desert"+NORM+"";
long_desc =
"    A great mountain stands here blocking you from proceeding north \n"+
"and east.  You fail to find enough shade to hide from the burning\n"+
"sunlight.  The path turns southeast leading toward a far oasis, \n"+
"while the desert spreads furiously to the west.  A few cacti grow \n"+
"around randomly.\n";

items = ({
  "oasis",
  "You can see the palm trees towering to the southeast",
  "palm trees",
  "Tall trees growing red palm and towering to the southeast",
  "trees",
  "Tall trees growing red palm and towering to the southeast",
  "path",
  "The constant travel through this area made the sand more\n"+
  "dense, forming a sandy path that leads west and southwest",
  "desert",
  "The yellow desert spreads around you. Some dunes and cacti can be\n"+
  "seen here and there",
  "sunlight",
  "The sun glows hot making you feel hot and sweaty",
  "sand",
  "Hot gold sand cover this endless desert",
  "dunes",
  "Small sandy dunes are scattered around randomly",
  "cacti",
  "A few cacti are growing randomly like skeleton hands reaching for help",
  "mountain",
  "The brown rocky mountain towers over five thousand feet high\n"+
  "with many caves and curves",
  "caves",
  "Some natural caves toward the top of the mountain. They would make\n"+
  "great shelters from the unbearable heat and direct sunlight",
  "curves",
  "It might be possible to "+BOLD+"climb"+NORM+" up using the natural curves in the rocky mountain",
  
});

dest_dir = ({
  "/players/coldwind/desert/rooms/r4.c","southeast",
  "/players/coldwind/desert/rooms/r2.c","west",
});

}

init(){
  ::init();
  add_action("climb_up", "climb");
    add_action("find_it", "search");
  }
  find_it(str){
  if(str == "mountain"){
  write("You can use the curves to "+BOLD+"climb"+NORM+" up the rocky mountain.\n");
  return 1;
  }
  write("Search what?\n");
  return 1;
  }
  
  climb_up(){
move_object(this_player(), "/players/coldwind/desert/rooms/ma1.c");
say(""+tpn+" arrives.\n");
command("look", this_player());
return 1;
}	
	