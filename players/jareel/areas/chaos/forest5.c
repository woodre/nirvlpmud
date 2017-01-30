inherit "/players/jareel/room";
#include "/players/jareel/define.h"

      reset(arg) {

      if(!present("broo")) {
        MOCO("/players/jareel/monsters/chaos/broo.c"),this_object());
        MOCO("/players/jareel/monsters/chaos/broo.c"),this_object());
        MOCO("/players/jareel/monsters/chaos/broo.c"),this_object());
        MOCO("/players/jareel/monsters/chaos/broo.c"),this_object());
      }

      if(!present("broo 4") && !present("broo 3") && !present("broo 2") && present("broo"))  {
        MOCO("/players/jareel/monsters/chaos/broo.c"),this_object()); 
        MOCO("/players/jareel/monsters/chaos/broo.c"),this_object()); 
        MOCO("/players/jareel/monsters/chaos/broo.c"),this_object()); 
      }

      if(!present("broo 3") && !present("broo 2") && present("broo"))  {
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
        ""+HIK+"@"+NORM+GRN+"#####"+NORM+"   Large colorful trees line the forest path.  To the north\n"+
        ""+HIK+"@"+NORM+"---"+HIK+"T"+NORM+GRN+"#"+NORM+"   a tower pierces the trees canopy.  The path that leads to\n"+
        ""+HIK+"@"+NORM+GRN+"#"+NORM+"|+"+NORM+BOLD+"X"+NORM+GRN+"#"+NORM+"   the west leads deep into the Wood.  The trees allow only\n"+
        ""+HIK+"@"+NORM+GRN+"#"+NORM+"|"+NORM+GRN+"###"+NORM+"   a few rays of light past their canopy, creating deep dark\n"+
        ""+HIK+"@"+NORM+GRN+"#"+NORM+"|"+GRN+"###"+NORM+"   shadows.  These shadows seem to watch your every move.\n";
      items = ({
        "road","The road is made of a grayish dirt, it has seen a lot of travel",
        "ray","The light is obscured by the canopy of trees",
        "shadow","The shadows flicker over the dirt road",
        "dirt","The fine gray dirt sifts between your fingers as you examine it",
        "canopy","Most of the sky is obscured here due to the large amount of trees",
        "sky","The sky is hard to see past the tree cover",
        "trees","The trees loom overhead menacing your every move",
        "branches","Twisted, gnarled, interlocking the wood makes traveling off the path impossible",
        "woods","Twisted, gnarled, interlocking the trees makes up this chaotic forest",
        "branch","Twisted, gnarled, interlocking the wood makes traveling off the path impossible",
        "forest","Large gnarled intertwined branches make up the walls of the wood",
        "shadows","The shadows flicker over the dirt road",
        "path","The road is made of a grayish dirt, it has seen a lot of travel",
        "wood","The trees loom overhead menacing your every move",
        "tree","The trees loom overhead menacing your every move",
        "light","The light is obscured by the canopy of trees",
        "rays","The light is obscured by the canopy of trees",
        "tower","The tower to the north reaches beyond the canopy the trees create",
      });

dest_dir = ({
      "/players/jareel/areas/chaos/forest6","north",
      "/players/jareel/areas/chaos/forest4","west",
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
