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
       ""+HIK+"@"+NORM+GRN+"#####"+NORM+"   Large colorful trees line the forest path.  To the north\n"+
       ""+HIK+"@"+NORM+"---"+HIK+"T"+NORM+GRN+"#"+NORM+"   and east the path forks moving deeper into the Wood, while\n"+
       ""+HIK+"@"+NORM+GRN+"#"+NORM+BOLD+"X"+NORM+"+|"+GRN+"#"+NORM+"   its south route leads back to the safety of civilization.\n"+
       ""+HIK+"@"+NORM+GRN+"#"+NORM+"|"+NORM+GRN+"###"+NORM+"   The trees allow very little light past the canopy, casting\n"+
       ""+HIK+"@"+NORM+GRN+"#"+NORM+"|"+GRN+"###"+NORM+"   deep shadows along the path.\n";
     items = ({
       "route","The route to the south leads out of the forest",
       "shadows","The flickering shadows dance over the forest floor",
       "civilization","Leaving the woods to safty maybe a good idea",
       "shadow","Shadows dance over the roads path",
       "forest","Thick gnarled intertwined trees form a dense wall of chaotic branches block off non obvious routes",
       "wood","Thick gnarled intertwined trees form a dense wall of chaotic branches block off non obvious routes",
       "road","The road is made of a grayish dirt, it has seen a lot of travel",
       "dirt","The fine gray dirt sifts between your fingers as you examine it",
       "canopy","Most of the sky is obscured here due to the large amount of trees",
       "sky","The sky is hard to see past the tree cover",
       "trees","The trees loom overhead menacing your every move",
       "town","Several buildings and a fountain can be seen to the south",   
       "buildings","Your still pretty far away to get any details",
       "path","The road is made of a grayish dirt, it has seen a lot of travel",
       "wood","The trees loom overhead menacing your every move",
       "tree","The trees loom overhead menacing your every move",
       "light","The light is obscured by the canopy of trees",
     });

dest_dir = ({
     "/players/jareel/areas/chaos/forest8","north",
     "/players/jareel/areas/chaos/forest4","east",
     "/players/jareel/areas/chaos/forest2","south",
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
