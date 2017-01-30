/*
===================================================================
=Chaos Wood add on started 5/10/06
=Creator Jareel
=
=This area will House Some tuff monsters 
=in the theme I have created in my area.
=
=A Humakti Temple will be located in 
=the woods where I may have Mondar 
=teleport too so he is tuffer to kill
=and not farmed as much as he is now
=
=As with most of the stuff I have created
=it will not be a cake walk and is designed
=to be entertaining for players of a high
=level.
===================================================================
*/

inherit "/players/jareel/room";
#include "/players/jareel/define.h"

reset(arg) {

  if(!present("broo")) {
    MOCO("/players/jareel/monsters/chaos/broo.c"),this_object()); 
    MOCO("/players/jareel/monsters/chaos/broo.c"),this_object()); 
  }

  if(!present("broo 2") && present("broo"))  {
    MOCO("/players/jareel/monsters/chaos/broo.c"),this_object()); 
  }
  if(arg) return;
      
  set_light(1);
  short_desc=(GRN+"The Chaos Wood"+NORM);
  long_desc=
    HIK+"@"+NORM+GRN+"#####"+NORM+"   Large, colorful trees line the forest path.  To the east\n"+
    HIK+"@"+NORM+"----"+NORM+GRN+"#"+NORM+"   the path continues deeper into the Wood, while smaller paths\n"+
    HIK+"@"+NORM+GRN+"##"+NORM+BOLD+"X"+NORM+"|"+NORM+GRN+"#"+NORM+"   that branch to the north and south, lead to the unknown. The\n"+
    HIK+"@"+NORM+GRN+"#"+NORM+"H++-"+NORM+"   little light the canopy allows to pass casts deep shadows over\n"+
    HIK+"@"+NORM+GRN+"##"+NORM+"-|"+GRN+"#"+NORM+"   the forest floor.\n";
  items = ({
    "Ruins","What appears to be ruins just past some overgrown vegitation",
    "road","The road is made of a grayish dirt; it has seen a lot of travel",
    "shadow","The shadows flicker over the dirt road",
    "dirt","The fine gray dirt sifts between your fingers",
    "canopy","Most of the sky is concealed by the large amount of trees",
    "sky","The sky is hard to see past the canopy",
    "trees","The trees loom overhead, menacing your every move",
    "path","The road is made of a grayish dirt; it has seen a lot of travel",
    "forest","Large gnarled intertwined branches make up the walls of the Wood",
    "shadows","Shadows flicker over the dirt road",
    "wood","The trees loom overhead, menacing your every move",
    "tree","The trees loom overhead, menacing your every move",
    "light","The light is obscured by the canopy of trees",
    "rays","The light is obscured by the canopy of trees",
  });

  dest_dir = ({
    "/players/jareel/areas/chaos/woods2/cwf3","north",
    "/players/jareel/areas/chaos/woods2/cwf6","east",
    "/players/jareel/areas/chaos/woods2/cwf7","south",
  });
}

Search(str) {
  if(!str) { write("Search what?\n"); return 1; }
    write("You search the "+str+" but find nothing special.\n");
    say(this_player()->query_name()+" searches around for something.\n");
  return 1;
}
