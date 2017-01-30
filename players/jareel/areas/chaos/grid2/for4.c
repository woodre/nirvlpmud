inherit "/players/jareel/room";
#include "/players/jareel/define.h"

#define l1 "   Large colorful trees sway and crash into each other."
#define l2 "   Looking over the foliage you see the chaotic growth"
#define l3 "   that makes passage impossible.  The forest's path leads"
#define l4 "   off deeper into the deep chaotic Wood.  Light invades"
#define l5 "   the wood causing shadows that seem to watch you."

reset(arg) {
     if(arg) return;

     set_light(1);
     short_desc=(GRN+"The Chaos Wood"+NORM);
     long_desc=
       ""+GRN+"#####"+NORM+l1+"   \n"+
       ""+GRN+"#"+NORM+"+--+ "+NORM+l2+"   \n"+
       ""+NORM+"-|"+GRN+"##"+NORM+"|"+NORM+l3+"   \n"+
       ""+GRN+"#"+NORM+"|"+GRN+"##"+NORM+"|"+NORM+l4+"   \n"+
       ""+GRN+"#"+NORM+"+--X"+NORM+l5+"   \n"+
       ""+GRN+"#####"+NORM+"\n";
     items = ({
       "road","The road is less apparent here, and has patches of grass growing sparingly along its route",
       "grass","Patches of green blades start to cover the path",
       "shadow","Shadows dance over the roads path",
       "hendrickville","A small town recessed in the side of the Chaos Wood",
       "ray","Few sunbeams escape into the Chaos Wood",
       "dirt","The fine gray dirt sifts between your fingers as you examine it",
       "canopy","Most of the sky is obscured here due to the large gnarled intertwined trees",
       "sky","The sky is barely visible past the tree cover",
       "trees","The trees twisted and gnarled intertwine to form imposing walls around you",
       "town","The edge of the small town is apparent past several trees",   
       "path"," The road is less apparent here, and has patches of grass growing sparingly along its route ",
       "wood","The trees loom overhead menacing your every move",
       "tree","Twisted and gnarled in a myriad of colors the trees themselves are chaotic",
       "light","The light is obscured by the canopy of trees",
       "forest","A gnarled myriad of trees interlace around you",
       "shadows","Shadows dance over the roads path",
       "rays","Few sunbeams escape into the Chaos Wood",
});

dest_dir = ({
     
     "/players/jareel/areas/chaos/grid2/for6","north",
     "/players/jareel/areas/chaos/grid3/for1","east",
     "/players/jareel/areas/chaos/grid2/for3","west",
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
