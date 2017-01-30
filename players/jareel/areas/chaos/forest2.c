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
       ""+HIK+"@"+NORM+"---"+HIK+"T"+NORM+GRN+"#"+NORM+"   the path continues deeper into the Wood, while its south\n"+
       ""+HIK+"@"+NORM+GRN+"#"+NORM+"|+|"+GRN+"#"+NORM+"   route leads back to the safety of civilization.  The tree's\n"+ 
       ""+HIK+"@"+NORM+GRN+"#"+NORM+BOLD+"X"+NORM+GRN+"###"+NORM+"   dark darting shadows follow your every move.\n"+
       ""+HIK+"@"+NORM+GRN+"#"+NORM+"|"+GRN+"###"+NORM+"\n";
     items = ({
       "road","The road is made of a grayish dirt, it twists and turns through the wood",
       "shadow","Shadows dance over the roads path",
       "dirt","The fine gray dirt sifts between your fingers as you examine it",
       "canopy","Most of the sky is obscured here due to the large amount of trees",
       "sky","The sky is hard to see past the tree cover",
       "trees","The gnarled looming overhead, like arms waiting to ensnare their prey",
       "town","Several buildings and a fountain can be seen to the south",   
       "buildings","Your still pretty far away to get any details",
       "path","The road is made of a grayish dirt, it has seen a lot of travel",
       "wood","The trees loom overhead menacing your every move",
       "tree","The trees loom overhead menacing your every move",
       "light","The light is obscured by the canopy of trees",
       "shadows","Shadows flicker over the ground",
       "route","The path leads north and south here",
       "civilization","The way out of the wood is to the south",
     });
 
dest_dir = ({
     "/players/jareel/areas/chaos/forest3","north",
     "/players/jareel/areas/chaos/forest1","south",
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
