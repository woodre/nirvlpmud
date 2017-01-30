#include "/players/coldwind/define.h"

inherit "room/room";
reset(arg) {	
if(!present("ape", this_object())){
move_object(clone_object("/players/coldwind/desert/mobs/gapes.c"), this_object());
}
  if(arg) return;
set_light(1);

short_desc = ""+HIY+"Dahna desert"+NORM+"";
long_desc =
"    The stone road leads you to the middle of the desert.  The sun \n"+
"glares at you angrily, while the wind seems to be blowing the hot sand \n"+
"directly at you.  Long sticks have been scattered on both sides of the\n"+
"road.  Human skulls have been placed on top of each stick.\n";

items = ({
  "desert",
  "Yellow sand expands in every direction",
  "sand",
  "Hot sand covers the face of the desert. The wind blows the sand\n"+
  "directly at you",
  "sun",
  "The sun looks angry as it glows hot sending it's burning sunrays\n"+
  "directly at you",
  "road",
  "It was built with great care. The stone road continues south toward \n"+
  "some hills and east toward what looks like a graveyard",
  "skulls",
  "Gray human skulls are lying on top of wooden sticks. As you look at\n"+
  "the empty eye sockets, a short tremble takes over you",
  "eye sockets",
  "Empty eye sockets staring at you silently. Your heart shudders!!",
  "hill",
  "A brown rocky hill stands proud further south",
  "warning",
  "On both sides of the road, someone placed wooden sticks with human\n"+
  "skull lying on top of each",
  "sticks",
  "Wooden sticks have been scattered on both sides of the road. Each is carrying\n"+
  "a human skull. It seems like some sort of a warning",   
  
});

dest_dir = ({
  "/players/coldwind/desert/rooms/v7.c","south",
  "/players/coldwind/desert/rooms/v9.c","east",
});
}
exit(){    if(this_player()) this_player()->clear_fight_area();     }
	