/* Coast2 this will house the docks how bout a fishing village too */

#if 0 /* Rumplemintz */
#include "/sys/lib.h"
#include "/sys/ansi.h"
#endif

inherit "/room/room";
reset(arg)  {		
  if(arg) return; 
  if(!present("city_object")){
    move_object(clone_object("/players/maledicta/cont/castles/dock"), this_object()); 
  }
  set_light(1);
  short_desc = "Fishing Village ";
  long_desc = 
    "This small fishing village has been here for many seasons. Some\n"+
    "of its oldest inhabitants helped with the Orc War exodus. They\n"+
    "mostly keep to their own interests but they do serve as ferrymen\n"+
    "to the continent. Anyone needing transportation can seek it on\n"+
    "the dock. The sailors of these parts are well renown for their\n"+
    "boat skills and sea craft. The path back into the mountains is\n"+
    "to the northeast and a trail winds to a beach in the south.\n";
  items=({		/*Remember two deep on noun descriptions*/
    "village","A small collection of low houses and a few larger buildings",
    "houses","Sturdy wooden structures built to withstand harsh weather",
    "buildings","Solid stone and wood structures to hold merchandise",
    "moutains","The Western Coastal mountains loom to the east",
    "boats","Small fishing vessels with a few large deepwater vessels",
    "path","Road leading back to the main village track",
    "beach","A sandy beach tucked away below the mountains",
    "flotsum","Unwanted debris cast aside",
  });

  dest_dir = ({
    "/players/wren/Area/coastline/mountain2","northeast",
    "/players/wren/Area/coastline/coast3","south", 
  }); 
 
  /* Commented out by Sparrow 9/13/2006
  set_chance(5);			 
  add_msg("Two gulls scream as they fight for a fishhead by the dock \n");
  add_msg("A sailor staggers by returning from a visit to the tavern \n");
  add_msg("A sea shanty is being played on a squeeze-box somewhere near \n");
  add_msg("Fishermen wander by in small groups to check thier boats \n");
  add_msg("A mongrel dog scampers past to chase the gulls \n");
  */

  add_listen("main","Music played in one of the boats, the sea, sailers talking");
  add_listen("music","A rough ditty about an inkeepers daughter and a lucky sailer");
  add_listen("sea","Steady pounding of the sea on the cliffs");
  add_smell("main","The sea, fish, wood smoke, tar, and stale seaweed. ");
  add_smell("sea","Salty crisp sea air");
  add_smell("fish","Strong smell of fish guts left out from an earlier catch ");
  add_smell("smoke","Smoke from the houses cook fires");
  add_smell("tar","Hot pitch for sealing holes, smells strong and unpleasant");
  add_smell("seaweed","Smells like rotting plants");
}

init() {
  ::init();
  add_action("search_room","search");
}

search_room()  {
  write("Searching the flotsum reveals nothing to take in area \n");
  say (this_player()->query_name() +" searches the area. \n");
  return 1;
}
