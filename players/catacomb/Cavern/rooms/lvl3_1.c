#define TPN this_player()->query_name();
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc =("Deep within the Durkor Caverns");
long_desc =(
"  The sound of metalwork can be heard to the west, but that is the only\n"+
"thing that can be heard.  The Durkor live within this level and guard\n"+
"their city with all of their souls.  No outsider has ever entered into\n"+
"Sivart, their guards are fierce and show no mercy to those who challenge\n"+
"them.  The stairs lead up closer to the surface and away from the dreaded Durkor.\n");
 

items = ({
  "stair",
  "The stairs leave up to a safer level in the caverns", 
  "stairs",
  "The stairs leave up to a safer level in the caverns" 
});

dest_dir = ({
  "/players/catacomb/Cavern/rooms/lvl2_12.c","stairs",
  "/players/catacomb/Cavern/rooms/lvl3_2.c","northwest",
  "/players/catacomb/Cavern/rooms/lvl3_3.c","west",
  "/players/catacomb/Cavern/rooms/lvl3_5.c","east", 
  });
  }

