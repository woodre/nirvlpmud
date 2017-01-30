/* Beach view, possibly a place for somebody else to build on */
#if 0 /* Rumplemintz */
#include "/sys/lib.h"
#include "/sys/ansi.h"
#endif

inherit "/room/room";
reset(arg)  {   
  if(arg) return; 
  set_no_clean(1);
  set_light(1);
  short_desc = "Western Coastal Beach";
  long_desc = 
  "A quiet beach away from everything. If it were warmer you could\n"+
  "see this as a pleasant place to lounge. With the chill in the air\n"+
  "it is best used as a beautiful view. Unspoiled white sand dunes lay\n"+
  "between the lapping waves and the sea cliffs. A path leads back\n"+
  "over the rocks to the village north. Gulls dart about at the edge\n"+
  "of the water catching things dislodged by the sea and storms. It\n"+
  "is extremely peaceful and serene here.\n";
  items=({		/*Remember two deep on noun descriptions*/
    "beach","Smooth and sandy it appears to be seldom disturbed",
	"view","Breathtaking view of the beach and sea beyond",
    "dunes","Wind blown piles of sand with some sea grasses growing on top",
	"sand","White sands erroded from the cliffs and ground smooth by the sea",
	"waves","Rolling in large with the strong wind and breaking before the beach",
	"cliffs","Rise straight up behind, isolating this area from most directions",
	"path","Area cleared to give access to the fishing village",
	"rocks","Large jagged rocks weathered by the sea and storms",
    "village","Fishing village nearby with lots of boats",
    "gulls","The birds are feeding on small animals revealed by the waves",
    "water","Bits of debris and animals float about on the edge of the beach",
    "things","Small bits of fish and small crabs, bits of seaweed",
    "grasses","Long stemmed sea grasses cling to the top of the sandy dunes",
    "debris","Broken bits of shells, drift wood, bits of garbage from the village",
   });
   dest_dir = ({
     "/players/wren/Area/coastline/coast2","north",
   }); 
 
  /* Commented out by Sparrow 9/13/06
  set_chance(1);       
  add_msg("Waves break and roll onto the beach \n");
  add_msg("A gull cries as it glides down to the sands \n");
  add_msg("Sea grasses sway in the wind \n");
  */
  add_listen("main","Waves crashing into the rocks and gulls squalking ");
  add_listen("waves","Eroding the rocks with steady impacts ");
  add_listen("gulls","Fighting over little scraps found in the sand");
  add_smell("main","Salty sea spray with some fishy scents near the tide line");
  add_smell("sea","Crisp salty breeze ");
  add_smell("fishy","Some remains of sealife picked over by the birds");
  add_touch("sand","The white sand sifts smoothly through your fingers");
}

init() {
  ::init();
  add_action("search_room","search");
}

search_room()  {
  write("Combing the sands gets you tired but finds nothing to take \n");
  say (this_player()->query_name() +" searches the area. \n");
  return 1;
}
