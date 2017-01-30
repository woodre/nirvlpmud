#include "/players/coldwind/define.h"

inherit "room/room";
reset(arg) {	
  if(arg) return;
set_light(1);

short_desc = ""+HIY+"Dahna desert"+NORM+"";
long_desc =
"    You walk between the sand dunes going deeper into the featurless\n"+
"desert.  The sky above you looks clear and the sun makes the sand hot\n"+
"under your tired feet.  Some human footprints marks the sand heading\n"+
"south toward a small hut and a grassy area.\n";

items = ({
   "south",
   "A small white hut surrounded by a grassy area can be seen to the south.",
  "hut",
  "You can see a small wooden hut to the south, but you need to get closer\n"+
  "to get a better look.",
  "footprints",
  "Some recent human footprints mark the sand, heading south. You wonder\n"+
  "if you should "+BOLD+"track the footprints"+NORM+" or go "+BOLD+"back"+NORM+".",
  "desert",
  "Yellow featureless desert spreads around you, yet you can see a grassy area\n"+
  "to the south",
  "footprint",
  "A recent human footprint mark the sand, heading south. You wonder\n"+
  "if you should "+BOLD+"track the footprints"+NORM+" or go "+BOLD+"back"+NORM+".",
  "sky",
  "It's blue and clear of any clouds",
  "sun",
  "The sun is glowing hot as it floats in the heart of the sky",
  "sand",
  "Hot golden sand covers this endless desert. Some footprints marks the sand",
  "plants",
  "Someone has been planting in the middle of the desert, but you are too far\n"+
  "to make out what is being planted",
  "grassy area",
  "To the south, you see different type of plants sarrounding a small hut",
  "dunes",
  "The sandy dunes spreads to the limit of your vision",
  
  
});
}

init(){
  ::init();
  add_action("track_it", "track");
   add_action("go_path", "back");
     add_action("find_it", "search");
  }
  find_it(){
  write("You search the sand and notice some footprints marks the sand.\n");
  return 1;
  }

track_it(str){
if(str == "the footprints" || str == "footprints"){
move_object(this_player(), "/players/coldwind/desert/rooms/r6.c");
say(""+tpn+" arrives.\n");
command("look", this_player());
return 1;
}
write("Track what?\n");
return 1; }

 go_path(){
move_object(this_player(), "/players/coldwind/desert/rooms/r2.c");
say(""+tpn+" arrives.\n");
command("look", this_player());
return 1;
}			