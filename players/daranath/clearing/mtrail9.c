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
     "stone. The trail winds its way around to the north and west from\n"+
     "here, turning to another cave entrance slightly north of your\n"+
     "current position.\n";

    items=({
      "range", "High mountains and rocky slopes make up the majority of\n"+
               "the mountains",
      "clouds", "The dark clouds are very angry in nature",
      "trail","The trail heads east torwards an empty lot",
      "lightning", "Flashed of blue and bright yellow energy cross the\n"+
                   "dark clouds in an agressive manner",
      "peak", "The mountain's peak is surrounded by the dark clouds",
      "shadows", "The shadows shift and move about, playing tricks\n"+
                 "on your eyes at times",
      "cave","The cave mouth to the north has wooden supports holding it\n"+
             "up, making it seem to be the entrance to a mine shaft",
    });

    dest_dir=({
      "/players/daranath/mines/entry1.c","north",
      "/players/daranath/qualtor/nor_qual2.c","south",
/*
      "/players/daranath/qualtor/mansion/lot13.c","east",
*/
      "/players/daranath/clearing/mtrail8.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("You find little bits and pieces of dark grey stone along the trail.\n");
    say(tp +" searches the area.\n");
     return 1;
    }


