inherit "/players/jareel/room";
#include "/players/jareel/define.h"

reset(arg) {

     

     if(arg) return;
     set_light(1);
     short_desc=(GRN+"The Chaos Wood"+NORM);
     long_desc=
       ""+GRN+"#"+NORM+"|"+GRN+"###"+NORM+"   Large colorful trees line the forest path.  To the north\n"+
       ""+GRN+"#"+NORM+"|"+GRN+"#"+NORM+"|"+GRN+"#"+NORM+"   and south the foliage lines the dirt path.  The dense\n"+
       ""+GRN+"#"+NORM+"|"+GRN+"#"+NORM+"+-"+NORM+"   canopy overhead allows very little light to pass, however\n"+
       ""+GRN+"#"+NORM+"|"+GRN+"#"+NORM+"|"+GRN+"#"+NORM+"   deep dark shadows flow accross the forest floor.  The\n"+
       ""+GRN+"#"+NORM+"X"+GRN+"###"+NORM+"   forest seems to consume the shadows endlessly engorging\n"+
       ""+GRN+"#"+NORM+"|"+GRN+"###"+NORM+"   itself, in a feeding orgy.\n";
     items = ({
       "road","The road is made of a grayish dirt, it twists and turns through the wood",
       "shadow","Shadows dance over the roads path",
       "dirt","The fine gray dirt sifts between your fingers as you examine it",
       "canopy","Most of the sky is obscured here due to the large amount of trees",
       "sky","The sky is hard to see past the tree cover",
       "trees","The trees loom overhead gnarled looming overhead",
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
     "/players/jareel/areas/chaos/grid1/for3","north",
     "/players/jareel/areas/chaos/grid1/for1","south",
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
