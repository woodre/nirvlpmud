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


  if(!present("skeleton")) {
    MOCO("/players/jareel/monsters/chaos/woods2/skeleton.c"),this_object());
    MOCO("/players/jareel/monsters/chaos/woods2/skeleton.c"),this_object());
    MOCO("/players/jareel/monsters/chaos/woods2/skeleton.c"),this_object());
    MOCO("/players/jareel/monsters/chaos/woods2/skeleton.c"),this_object());
  }

  if(!present("skeleton 4") && !present("skeleton 3") && !present("skeleton 2") && present("skeleton"))  {
    MOCO("/players/jareel/monsters/woods2/skeleton.c"),this_object()); 
    MOCO("/players/jareel/monsters/woods2/skeleton.c"),this_object()); 
    MOCO("/players/jareel/monsters/woods2/skeleton.c"),this_object()); 
  }

  if(!present("skeleton 3") && !present("skeleton 2") && present("skeleton"))  {
    MOCO("/players/jareel/monsters/woods2/skeleton.c"),this_object()); 
    MOCO("/players/jareel/monsters/woods2/skeleton.c"),this_object()); 
  }

  if(!present("skeleton 2") && present("skeleton"))  {
    MOCO("/players/jareel/monsters/woods2/skeleton.c"),this_object()); 
  }

  if(arg) return;
      
  set_light(1);
  short_desc=(GRN+"The Chaos Wood"+NORM);
  long_desc=
    HIK+"@"+NORM+GRN+"#####"+NORM+"   Large, colorful trees sway and crash against the cliff\n"+
    HIK+"@"+NORM+BOLD+"X"+NORM+"---"+GRN+"#"+NORM+"   face.  Looking over the rock face, you make out a small, \n"+
    HIK+"@"+NORM+GRN+"##"+NORM+"||"+GRN+"#"+NORM+"   dark hole near its base.  The forest path leads off to\n"+
    HIK+"@"+NORM+GRN+"#"+NORM+"H++-"+NORM+"   the east, deeper into the Wood.  Light invades the Wood\n"+
    HIK+"@"+NORM+GRN+"##"+NORM+"-|"+GRN+"#"+NORM+"   near the rocks, softening the eyeful shadows.\n";
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
    "hole","The hole looks like it could be very dangerous; maybe you should 'enter' and see",
    "rock","The grey rock seems to be the only thing that stops the growth of this forest",
    "rocks","These grey rocks seem to be the only things that stop the growth of this forest",
    "face","You see a small, dark hole",
  });

  dest_dir = ({
    "/players/jareel/areas/chaos/woods2/cwf2","east",
  });
}

init() {
  ::init();
    add_action("hole","enter");
    add_action("Search","search");
}

hole(){
  TP->move_player("enters some ruins.#players/jareel/areas/chaos/woods2/demoncave1");
  return 1;
}

Search(str) {
  if(!str) { write("Search what?\n"); return 1; }
    write("You search the "+str+" but find nothing special.\n");
    say(this_player()->query_name()+" searches around for something.\n");
  return 1;
}
