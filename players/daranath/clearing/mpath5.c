#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
short_desc= (BOLD+BLK+"City of Qual'tor"+NORM+" (Northern Realms)");
    long_desc=
      "The dark forest that is the DarkenWood is left far to the south\n"+
      "from your position, its threatening inhabitants within. A path\n"+
      "heads torward the mountain range rising from the ground to the\n"+
      "north of your position. Dark clouds encircle the center peak of\n"+
      "the range, flashes of lightning can be seen from time to time.\n"+
      "The pathway leads right to a crossroads to the north.\n";

    items=({
      "forest", "The evil forest known as the DarkenWood spreads about\n"+
                "the area to the south",
      "range", "High mountains and rocky slopes make up the majority of\n"+
               "the mountains",
      "mountain", "Dark clouds surround the mountain peak, making you\n"+
                  "wonder if it is neccessary to traverse the rocky\n"+
                  "trails leading north",
      "clouds", "The dark clouds are very angry in nature",
      "lightning", "Flashed of blue and bright yellow energy cross the\n"+
                   "dark clouds in an agressive manner",
      "peak", "The mountain's peak is surrounded by the dark clouds",
      "crossroads", "Several paths seem to converge at the crossing\n"+
                    "area just to the north of your position",
    });

    dest_dir=({
      "/players/daranath/clearing/mcross.c","north",
      "/players/daranath/clearing/mpath4.c","south",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("You find nothing along the pathway leading to the mountain.\n");
    say(tp +" searches the area.\n");
     return 1;
    }


