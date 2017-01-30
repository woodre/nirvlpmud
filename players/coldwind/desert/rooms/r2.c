#include "/players/coldwind/define.h"

inherit "room/room";
reset(arg) {	
  if(arg) return;
set_light(1);

short_desc = ""+HIY+"Dahna desert"+NORM+"";
long_desc =
"    The endless desert surrounds you as you follow the path.  A \n"+
"mountain stands soaring to the northwest, while the path continues\n"+
"west and east.  The sky above you looks clear and the sun makes the \n"+
"sand awfully hot under your feet.  A few cactus plants grow on both \n"+
"sides of the path giving you an uneasy feeling. \n";

items = ({
  "path",
  "The constant travel through this area made the sand more\n"+
  "dense, forming a sandy path that leads west and east",
   "footprints",
  "Some recent human footprints mark the sand, heading south. You wonder\n"+
  "if you should "+BOLD+"track the footprints"+NORM+".",
  "footprint",
  "A recent human footprint mark the sand, heading south. You wonder\n"+
  "if you should "+BOLD+"track the footprints"+NORM+".",
  "desert",
  "Yellow dunes are scattered randomly across the endless desert",
  "dune",
  "Small hills of yellow sand are scattered across the desert randomly",
  "sky",
  "It's blue and clear of any clouds",
  "sun",
  "The sun glows warm making you feel as if it's close",
  "sand",
  "Hot golden sand covers this endless desert. You notice some footprints \n"+
  "marking the sand",
  "cactus",
  "A few cacti grow on both sides of the path like skeleton hands reaching for help",
  "sides",
  "Some cactus plants are growing on both sides",
  "mountain",
  "A huge rocky mountain stands tall to the northwest",
  
  
});

dest_dir = ({
  "/players/coldwind/desert/rooms/r3.c","east",
  "/players/coldwind/desert/rooms/r1.c","west",
});

}
init(){
  ::init();
  add_action("track_it", "track");
  add_action("find_it", "search");
  }
  find_it(){
  write("You notice some footprints marking the sand.\n");
  return 1;
  }
track_it(str){
if(str == "the footprints" || str == "footprints"){
move_object(this_player(), "/players/coldwind/desert/rooms/r5.c");
say(""+tpn+" arrives.\n");
command("look", this_player());
return 1;
}
write("Track what?\n");
return 1; }