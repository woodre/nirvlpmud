#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
short_desc= (BOLD+BLK+"City of Qual'tor"+NORM+" (Northern Realms)");
    long_desc=
      "A small dirt trail encircles the base of the mountain itself, \n"+
      "running both east and west from the crossroads. Dark shadows,\n"+
      "illuminated only briefly by the flashes of lightning, line both\n"+
      "sides of the trail, hiding things dark and dangerous.\n";

    items=({
      "range", "High mountains and rocky slopes make up the majority of\n"+
               "the mountains",
      "clouds", "The dark clouds are very angry in nature",
      "lightning", "Flashed of blue and bright yellow energy cross the\n"+
                   "dark clouds in an agressive manner",
      "peak", "The mountain's peak is surrounded by the dark clouds",
      "shadows", "The shadows shift and move about, playing tricks\n"+
                 "on your eyes at times",
    });

    dest_dir=({
      "/players/daranath/clearing/mtrail7.c","northeast",
      "/players/daranath/clearing/mtrail5.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search_room");
    }

    search(){
    write("You find nothing along the trail encircling the mountain.\n");
    say(tp +" searches the area.\n");
     return 1;
    }


