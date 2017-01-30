#include "/players/coldwind/define.h"

inherit "room/room";
reset(arg) {	
if(!present("ape", this_object())){
move_object(clone_object("/players/coldwind/desert/mobs/apes.c"), this_object());
move_object(clone_object("/players/coldwind/desert/mobs/apes.c"), this_object());
}
  if(arg) return;
set_light(1);

short_desc = ""+HIY+"Dahna desert"+NORM+"";
long_desc =
"    The path continues east to a distant oasis and northwest toward\n"+    
"the endless desert.  Footprints of different sizes mark the sandy\n"+
"path.  A few cactus plants grow on both sides of the path giving you an\n"+
"odd feeling of fear.  A huge mountain stands to the north and\n"+
"continues northwest blocking you from proceeding north.\n";

items = ({
  "oasis",
  "You can see the palm trees towering to the east",
  "palm trees",
  "Some tall trees growing red palm and towering by the oasis to the east",
  "path",
  "Footprints of different sizes mark the well-used path",
  "footprints",
  "Footprints of different races have made their marks in the sandy path",
  "desert",
  "The yellow sand spreads around covering the face of the desert, while\n"+
  "some dunes are scattered around randomly",
  "sand",
  "Hot gold sand cover this endless desert",
  "cacti",
  "Few cacti are growing randomly like skeleton hands reaching for help",
  "mountain",
  "The mountain towers over five thousand feet high with many caves and curves",
  "caves",
  "Some natural caves toward the top of the mountain. They would make great shelters\n"+
  "from the unbearable heat and direct sunlight",
  "curves",
  "Natural curves decorate the rocky mountain",
  "dunes",
  "Small yellow hills formed by the accumulation of sand",
  
});

dest_dir = ({
  "/players/coldwind/desert/rooms/v4.c","east",
  "/players/coldwind/desert/rooms/r3.c","northwest",
});

}


	