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
        ""+HIK+"@"+NORM+GRN+"#####"+NORM+"   Large colorful trees line the forest path.  To the east\n"+
        ""+HIK+"@"+NORM+"-"+BOLD+"X"+NORM+"-"+NORM+HIK+"T"+NORM+GRN+"#"+NORM+"   a tower pierces the trees canopy.  The path that leads to\n"+
        ""+HIK+"@"+NORM+GRN+"#"+NORM+"|+|"+NORM+GRN+"#"+NORM+"   the west and south leads deep into the Wood.  The trees\n"+
        ""+HIK+"@"+NORM+GRN+"#"+NORM+"|"+NORM+GRN+"###"+NORM+"   allow a few rays of light past their canopy, creating deep\n"+
        ""+HIK+"@"+NORM+GRN+"#"+NORM+"|"+GRN+"###"+NORM+"   dark shadows.  These shadows seem to watch your every move.\n";
      items = ({
        "road","The road is made of a grayish dirt, it has seen a lot of travel",
        "branches","Twisted, gnarled, interlocking the wood makes traveling off the path impossible",
        "ray","The light is obscured by the canopy of trees",
        "shadow","The shadows flicker over the dirt road",
        "branch","Twisted, gnarled, interlocking the wood makes traveling off the path impossible",
        "dirt","The fine gray dirt sifts between your fingers as you examine it",
        "canopy","Most of the sky is obscured here due to the large amount of trees",
        "sky","The sky is hard to see past the tree cover",
        "trees","The trees loom overhead menacing your every move",
        "cliff","The cliff rises thousands of feet strait up",   
        "path","The road is made of a grayish dirt, it has seen a lot of travel",
        "forest","Large gnarled intertwined branches make up the walls of the wood",
        "shadows","The shadows flicker over the dirt road",
        "wood","The trees loom overhead menacing your every move",
        "tree","The trees loom overhead menacing your every move",
        "light","The light is obscured by the canopy of trees",
        "tower","To the east the Tower is a foreboding",
        "rays","The light is obscured by the canopy of trees",
      });

dest_dir = ({
      "/players/jareel/areas/chaos/forest9","west",
      "/players/jareel/areas/chaos/forest7","east",
      "/players/jareel/areas/chaos/forest3","south",
      });
}

init() {
     ::init();
       add_action("Search","search");
     }

Search(str) {
     if(!str) { write("Search what?\n"); return 1; }
       write("You search the "+str+" but find nothing special.\n");
       say(this_player()->query_name()+" searches around for something.\n");
     return 1;
}
