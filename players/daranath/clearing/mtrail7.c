#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
short_desc= (BOLD+BLK+"City of Qual'tor"+NORM+" (Northern Realms)");
    long_desc=
      "The trail continues to encircle the base of the mountain,\n"+
      "turning to the northeast around an outcropping of dark grey\n"+
      "stone. A cave mouth opens in the stone to the north along the\n"+
      "face of the mountain, the shadows making it difficult to see\n"+
      "anything within. The trail continues to the east.\n";

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
      "/players/daranath/clearing/mtrail8.c","east",
      "/players/daranath/clearing/mtrail6.c","southwest",
      "/players/daranath/clearing/mcave.c","enter",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("You find nothing along the trail encircling the mountain.\n");
    say(tp +" searches the area.\n");
     return 1;
    }


