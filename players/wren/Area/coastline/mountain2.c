/* Almost out of the mountains, worst weather behind, */
/* nice coast view to the west, dock southwest        */
#if 0 /* Rumplemintz */
#include "/sys/lib.h"
#include "/sys/ansi.h"
#endif
inherit "/room/room";
reset(arg)  {   
  if(arg) return; 
  set_light(1);
  short_desc = "Coastal Mountains";
  long_desc = 
    "The trail diverges here with a small footpath going west while\n"+
    "the main road runs from the north to the southwest. The storm\n"+
    "clouds are thinning and the weather softening. The sound of waves\n"+
    "crashing into sea cliffs is near. A few gulls glide by on rising\n"+
    "air currents quietly skirting the storms. Topping the rise reveals\n"+
    "a fishing village below with a dock lined with small boats. Anyone\n"+
    "needing passage across the sea should inquire there.\n";
  items=({		/*Remember two deep on noun descriptions*/
    "mountains","They are behind as you descend the foothills to the shore",
	"trail","Worn stone path leading between the mountains and coast",
    "footpath","A narrow path leading around the rocks to the sea cliffs",
	"road","Remainder of trade route between coast and main village",
	"storm","The bad weather is continuing east",
	"clouds","The strong sea breeze is blowing them inland",
	"weather","Little rain falls over head now",
	"gulls","White sea birds wheeling overhead driven inland by fowl weather",
    "rise","Highest point on the path before it descends to the coast",
    "village","A simple fishing village that supplements income as ferriers",
    "dock","Most of the boats are in port waiting out the storms",
    "boats","Fishing vessels a few are suitably large to be sea worthy",
    "sea","Waves are still rough following the heavy winds",
  });

  dest_dir = ({
    "/players/wren/Area/coastline/mountain","north",
    "/players/wren/Area/coastline/coast1","west", 
    "/players/wren/Area/coastline/coast2","southwest",
  }); 
 
  /* Commented out by Sparow 9/14/06
  set_chance(5);        
  add_msg("A gull cries out above as it wings its way back toward the shores. \n");
  add_msg("Thunder rumbles to the northeast as the storm works across the mountains. \n");
  add_msg("The loud crash of waves comes from somewhere to the west \n");
  add_msg("A boat can be seen braving the rough seas to sail to Hirandea. \n");
  */
  add_listen("main","The sea and birds can be heard here ");
  add_listen("sea","Rythmic crash of waves into the sea cliffs ");
  add_listen("birds","The birds call out as they return to the air after the storm");
  add_smell("main","Salty sea air pervades the area ");
  add_smell("air","It is salty and cool");
}

init() {
  ::init();
  add_action("search_room","search");
}

search_room()  {
  write("Nothing interesting is revealed examining the area \n");
  say(this_player()->query_name() +" searches the area. \n");
  return 1;
}
