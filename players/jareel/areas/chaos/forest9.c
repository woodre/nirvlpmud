inherit "/players/jareel/room";
#include "/players/jareel/define.h"
     reset(arg) {
     
     if(arg) return;
     set_light(1);
     short_desc=(GRN+"The Chaos Wood"+NORM);
     long_desc=
       ""+HIK+"@"+NORM+GRN+"#####"+NORM+"   Large colorful trees sway and crash against the cliff \n"+
       ""+HIK+"@"+NORM+BOLD+"X"+NORM+"--"+HIK+"T"+NORM+GRN+"#"+NORM+"   face.  Looking over the rock face you make out a small \n"+
       ""+HIK+"@"+NORM+GRN+"#"+NORM+"|+|"+NORM+GRN+"#"+NORM+"   dark hole is near the base.  The forest's path leads off\n"+
       ""+HIK+"@"+NORM+GRN+"#"+NORM+"|"+NORM+GRN+"###"+NORM+"   to the east deeper into the Wood.  Light invades the\n"+
       ""+HIK+"@"+NORM+GRN+"#"+NORM+"|"+GRN+"###"+NORM+"   wood near the rocks softening the shadows watching you.\n";
     items = ({
       "road","The road is made of a grayish dirt, it has seen a lot of travel",
       "dirt","The fine gray dirt sifts between your fingers as you examine it",
       "canopy","Most of the sky is obscured here due to the large amount of trees",
       "sky","The sky is hard to see past the tree cover",
       "trees","The trees loom overhead menacing your every move",
       "cliff","The cliff rises thousands of feet straight up",
       "cliffs","The cliff rises thousands of feet straight up",
       "cliff face","The cliff rises thousands of feet straight up",
       "cliff's face","The cliff rises thousands of feet straight up",
       "path","The road is made of a grayish dirt, it has seen a lot of travel",
       "wood","The trees loom overhead menacing your every move",
       "tree","The trees loom overhead menacing your every move",
       "light","The light is obscured by the canopy of trees",
       "rays","The light is obscured by the canopy of trees",
       "cave","The dark hole in the rock face you may be able to 'enter'",
       "hole","The hole in the cliff face maybe a cave",
       "rocks","The cliff rises thousands of feet straight up",
       "rock","The rock of the cliff rises thousands of feet straight up",
       "forest","Large gnarled intertwined branches make up the walls of the wood",
       "branches","Twisted, gnarled, interlocking the wood makes traveling off the path impossible",
       "branch","Twisted, gnarled, interlocking the wood makes traveling off the path impossible",
       "shadow","The shadows flicker over the dirt road",
       "shadows","The shadows flicker over the dirt road",
       "face","The cliff rises thousands of feet strait up",
     });
      
dest_dir = ({
     "/players/jareel/areas/chaos/forest8","east",
     });
}

init() {
     ::init();
       add_action("Search","search");
       add_action("cave","enter");
     }

cave(){
     TP->move_player("enters the cave.#players/jareel/areas/chaos/cave/cave_enter");
     return 1;
     }

Search(str) {
     if(!str) { write("Search what?\n"); return 1; }
       write("You search the "+str+" but find nothing special.\n");
       say(this_player()->query_name()+" searches around for something.\n");
     return 1;
     }
