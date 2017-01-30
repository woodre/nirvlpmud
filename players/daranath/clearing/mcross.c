#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
short_desc= (BOLD+BLK+"City of Qual'tor"+NORM+" (Northern Realms)");
    long_desc=
      "The pathway ends at a small crossroads at the base of the mountain\n"+
      "itself, the dark clouds circling overhead. Bright flashes of light\n"+
      "illuminate the area every now and then, increasing the threatening\n"+
      "feel of the area. A small trail leads both east and west from the\n"+
      "crossroads here, while another path leads up the face of the\n"+
      "mountain itself.\n";

    items=({
      "range", "High mountains and rocky slopes make up the majority of\n"+
               "the mountains",
      "mountain", "Dark clouds surround the mountain peak, making you\n"+
                  "wonder if it is neccessary to traverse the rocky\n"+
                  "trails leading north",
      "clouds", "The dark clouds are very angry in nature",
      "lightning", "Flashed of blue and bright yellow energy cross the\n"+
                   "dark clouds in an agressive manner",
      "trail", "A small dirt trail leads to the east and west",
      "path", "A second path leads up the steep face of the mountain\n"+
              "itself, heading torwards the dark clouds",
    });

    dest_dir=({
      "/players/daranath/clearing/mpath5.c","south",
      "/players/daranath/clearing/mtrail5.c","east",
      "/players/daranath/clearing/mtrail1.c","west",
      "/players/daranath/clearing/mclimb1.c","up",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("You find nothing about the area of the crossroads.\n");
    say(tp +" searches the area.\n");
     return 1;
    }


