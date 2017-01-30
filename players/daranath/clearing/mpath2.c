#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
short_desc= (BOLD+"DarkenWood"+NORM+" (Northern Edge)");
    long_desc=
      "The dark forest thins a bit in this area, yet enough of it still\n"+ 
      "exists within the area to cast deep shadows all about. Through\n"+
      "a small opening between two trees, a mountain can be seen rising\n"+
      "to the north of your position. Dark clouds encircle the mountain's\n"+
      "peak, flashes of lightning can be seen from time to time.\n";

    items=({
      "forest", "The evil forest known as the DarkenWood spreads about\n"+
                "the area to the south",
      "trees", "The trees are blackened from the presence of the area",
      "tree", "Each individual tree stands out from another",
      "mountain", "Dark clouds surround the mountain peak, making you\n"+
                  "wonder if it is neccessary to traverse the rocky\n"+
                  "trails leading north",
      "clouds", "The dark clouds are very angry in nature",
      "lightning", "Flashed of blue and bright yellow energy cross the\n"+
                   "dark clouds in an agressive manner",
      "peak", "The mountain's peak is surrounded by the dark clouds",
    });

    dest_dir=({
      "/players/daranath/clearing/dwood6.c","south",
      "/players/daranath/clearing/mpath1.c","west",
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


