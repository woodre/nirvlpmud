inherit "room/room";       /* ec22 */

reset(arg){
 if(!arg){

  set_light(0);
  short_desc = "inculta creperum";  /* waste / desert darkness */
  long_desc=
"  Towering mountains loom to the south and east of this corner of the\n"+
"desert.  The warmth of the darkness seems to surround you here.  The\n"+
"thick looking black sky swirls slowly as the wind cuts through it.\n"+
"Flecks of sand fly past your face, obscuring your vision.  The ground\n"+
"is hard, dry and seemingly lifeless.  Small rocks are scattered over\n"+
"the flat tiles of brownish stone.  \n";
  items=({
  "sky",
"The sky is a luminous mass of dark swirls.  The wind causes it to\n"+
"constantly writhe and shift above you",
  "wind",
"The wind is blowing all around you, blowing the sand which obscures\n"+
"your vision",
  "sand",
"Bits of sand writhe at your feet, as well as fly past your face.  The\n"+
"wind which never seems to stop makes the sand almost seem alive",
  "ground",
"The ground seems so lifeless and dead.  It is hard and flat, lined with\n"+
"dry cracks which run ever so deep.  Life does not seem to have existed\n"+
"here for ages",
  "rocks",
"Small rocks are littered across the ground, mingling with the sand",
  "mountains",
"The mountains to the south and east make travel in those directions\n"+
"impossible.  They are massive towers of rock that penetrate the\n"+
"ongoing darkness of the sky",
  "stone",
"The ground is made of dull, brown stone.  It is all very dry and cracked",
  "cracks",
"The ground is lined with small and large cracks",
  });
  /*
  dest_dir=({  "/players/zeus/desert/r/ec18.c", "north",
               "/players/zeus/desert/r/ec21.c", "west",  });
  */
 }
}

void init(){
  ::init();
  add_action("west_dir", "west");
  add_action("north_dir", "north");
  add_action("search_cmd", "search");
}

west_dir(){
  write("You walk west into the darkness...\n\n");
  this_player()->move_player("west#/players/zeus/desert/r/ec21.c");
  return 1;
}

north_dir(){
  write("You walk north into the darkness...\n\n");
  this_player()->move_player("north#/players/zeus/desert/r/ec18.c");
  return 1;
}

/* For the Inculta Creperum quest */
#include "/players/zeus/desert/r/search.h"

