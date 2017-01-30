inherit "/players/jareel/room";
#include "/players/jareel/define.h"

reset(arg) {

     

     if(arg) return;
     set_light(1);
     short_desc=(GRN+"The Chaos Wood"+NORM);
     long_desc=
       ""+GRN+"#"+NORM+"|"+GRN+"###"+NORM+"   Large colorful trees line the forest path.  To the east and\n"+
       ""+GRN+"#"+NORM+"|"+GRN+"#"+NORM+"|"+GRN+"#"+NORM+"   west vegetation lines the dirt path, while to the north\n"+
       ""+GRN+"#"+NORM+"|"+GRN+"#"+NORM+"+-"+NORM+"   and south the path leads off into the unknown.  The little\n"+
       ""+GRN+"#"+NORM+"X"+GRN+"#"+NORM+"|"+GRN+"#"+NORM+"   bit of light that passes the canopy, casts deep shadows\n"+
       ""+GRN+"#"+NORM+"|"+GRN+"###"+NORM+"   over the forest floor.\n"+
       ""+GRN+"#"+NORM+"|"+GRN+"###"+NORM+"\n";
     items = ({
       "route","The route to the south leads out of the forest",
       "shadows","The flickering shadows dance over the forest floor",
       "civilization","Leaving the woods to safty maybe a good idea",
       "shadow","Shadows dance over the roads path",
       "forest","Thick gnarled intertwined trees appearerd to have been "+HIW+"'push'"+NORM+"ed to the east",
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
     "/players/jareel/areas/chaos/grid1/for4","north",
     "/players/jareel/areas/chaos/grid1/for2","south",
});
}

init() {
     ::init();
       add_action("Search","search");
       add_action("SecretDoor","push");
}

Search(str) {
     if(!str) { write("Search what?\n"); return 1; }
       write("You search the "+str+" but find nothing special.\n");
       say(this_player()->query_name()+" searches around for something.\n");
     return 1;
}

SecretDoor(str) {
     if(str == "push" || "east" || "e") {  
       this_player()->move_player("pushes aside the trees#/players/jareel/areas/chaos/grid1/secdoor.c");
       return 1;  
     } 
}




