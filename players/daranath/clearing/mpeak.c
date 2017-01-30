#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
short_desc= ("Storm Mountain (Peak)");
    long_desc=
      "The path leading up the side of the mountain opens into a very\n"+
      "unusual area. A rocky area just to the north of here opens up,\n"+
      "craddled within the embrace of the stone all about. The clouds\n"+
      "threatened everything within the area, looking as if they might\n"+
      "unleash thier anger at any time.\n";

    items=({
      "clouds", "The dark clouds are very angry in nature",
      "lightning", "Flashed of blue and bright yellow energy cross the\n"+
                   "dark clouds in an agressive manner",
      "area", "The rocky area to the north invites you within",
      "stone", "The dark stone seems to have borne the brunt of the storm\n"+
               "which rages all about you. Blast marks from the lightning\n"+
               "cover the rock all about",
      "path", "The path leads back down the mountain",
    });

    dest_dir=({
      "/players/daranath/clearing/marea1.c","north",
      "/players/daranath/clearing/mclimb3.c","south",
      "/players/daranath/clearing/mmulan.c","east",
      "/players/daranath/clearing/mtent.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("You find nothing along the mountain path.\n");
    say(tp +" searches the area.\n");
     return 1;
    }


