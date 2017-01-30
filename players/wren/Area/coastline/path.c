/* Western Coastal path 
   Replace Reflex and his lame-ass
   descriptions. 
*/
#if 0 /* Rumplemintz */
#include "/sys/lib.h"
#include "/sys/ansi.h"
#endif

inherit "/room/room";
reset(arg)  {   
  if(arg) return; 
  set_light(1);
  short_desc = "Coastal road";
  long_desc = 
"Remains of an old road linking the village and the coast.\n\
Tufts of grass dance in the wind between the ancient cobbles.\n\
Ill repair has not slowed traffic as is evident by the mud  \n\
and footprints. In the distance the road narrows as it enters \n\
the Coastal Mountains. A pass is evident between two of the \n\
nearby peaks. \n";
  items=({		/*Remember two deep on noun descriptions*/
    "remains","Like main old roads this one has been plundered for building stone",
    "road","The road leads between the old coastal settlement ruins and the village in the east",
    "tufts","Long stems of grass that escaped being trampled",
    "cobbles","Weathered stones that were part of the old road",
    "grass","Prairie grass going to seed and drying out",
    "mud","Muddy puddles formed between some stones and captured footprints and wheel ruts",
    "footprints","Boot marks and creature tracks from a wide variety of sources",
    "mountains","The Coastal Mountains, these natural barriers deter invaders and block rough storms",
    "pass","Between two of the mountains lies a passage, at this distance its hard to gauge its width",
    "ruts","Wheel marks from trade and farm wagons that have passed along the road to market",
    "puddle","Water from a recent rainstorm collected in a depression where a cobble used to be",
    "storms","Dark clouds are gathering in the sky, rain fall is likely in near future",
    "barriers","Except for the pass the mountains are difficult to circumvent",
    "lightning","Occasional flashes of lightning highlight the clouds and the mountains",
    "tracks","Wildlife and possibly monsters have been across this trail"
  });

  dest_dir = ({
    "/room/orc_dump","east",
    "/players/wren/Area/coastline/pass","west", 
  }); 
 
  /* Commented out by Sparrow 9/14/06
  set_chance(5);       
  add_msg("Thunder rumbles among the distant peeks before rolling down onto the plains\n");
  add_msg("Chill winds whip around you \n");
  add_msg("Lightning flashes in the distant clouds \n");
  add_msg("Grass flicks back in forth in the breeze \n");
  add_msg("Large rain drops fall sporadically \n");
  */
  add_listen("main","Crickets chirp in the tall grass and thunder echoes in the peaks");
  add_listen("crickets","Out of sight but clearly heard is the crickets song ");
  add_listen("thunder","A gentle rumble is all that is heard this far from the storm ");
  add_smell("main","You can smell the rain in the air, the straw near the road, and horse droppings");
  add_smell("straw","The scent of damp straw wafts up from the side of the road ");
  add_smell("droppings","Yep, its horse #$%^ alright");
  add_smell("rain","The clean damp scent of an impending storm ");
  add_touch("print","Gauging the depth you feel that most of the travelers were moving quickly ");
  add_touch("tracks","The tracks are still slightly warm and damp, recently made it seems ");
}

init() {
  ::init();
  add_action("search_room","search");
}

search_room()  {
  write("You find nothing of importance when examining the area. \n");
  say (this_player()->query_name() +" searches the area. \n");
  return 1;
}
