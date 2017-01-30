#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
short_desc= (BOLD+BLK+"City of Qual'tor"+NORM+" (Southern Entrance)");
    long_desc=
      "A short valley runs between the path leading to the mountain and\n"+
      "the main entrance to a city just to the east of here. The entrance itself\n"+
      "is undergoing a vast construction project, bringing the city back from the\n"+
      "realm of death.\n";

    items=({
      "mountain", "Dark clouds surround the mountain peak, making you\n"+
                  "wonder if it is neccessary to traverse the rocky\n"+
                  "trails leading north",
      "clouds", "The dark clouds are very angry in nature",
      "lightning", "Flashed of blue and bright yellow energy cross the\n"+
                   "dark clouds in an agressive manner",
      "valley","The valley extends from the path leading to the mountain\n"+
               "to a large clearing just northeast of here",
      "ruins","The ruined city looks as if a large battle destroyed\n"+
              "what it had for a wall and defenses",
    });

    dest_dir=({
      "/players/daranath/qualtor/wayin2.c","east",
      "/players/daranath/clearing/mpath4.c","southwest",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("You find nothing about the area.\n");
    say(tp +" searches the area.\n");
     return 1;
    }


