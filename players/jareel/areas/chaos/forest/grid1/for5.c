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
       ""+GRN+"#"+NORM+"|"+GRN+"###"+NORM+"   Large colorful trees line the forest path.  To the north\n"+
       ""+GRN+"#"+NORM+"X"+GRN+"#"+NORM+"|"+GRN+"#"+NORM+"   the path cuts pat the trees.  The foliage obstructs passage\n"+
       ""+GRN+"#"+NORM+"|"+GRN+"#"+NORM+"+-"+NORM+"   to the east and to the west.  The trees closing overhead\n"+
       ""+GRN+"#"+NORM+"|"+GRN+"#"+NORM+"|"+GRN+"#"+NORM+"   allow a few rays of light past their canopy, creating dark\n"+
       ""+GRN+"#"+NORM+"|"+GRN+"###"+NORM+"   shadows.  These shadows seem to watch your every move.\n"+
       ""+GRN+"#"+NORM+"|"+GRN+"###"+NORM+"\n";
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
        "rays","The light is obscured by the canopy of trees",
      });

dest_dir = ({
      "/players/jareel/areas/chaos/forest/grid1/for6","north",
      "/players/jareel/areas/chaos/forest/grid1/for4","south",
      
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
