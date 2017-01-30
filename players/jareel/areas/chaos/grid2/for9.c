inherit "/players/jareel/room";
#include "/players/jareel/define.h"

#define line1 "   Large colorful trees line the forest path.  To the north"
#define line2 "   and south the foliage lines the dirt path.  The dense"
#define line3 "   canopy overhead allows very little light to pass, however"
#define line4 "   deep dark shadows flow accross the forest floor.  The"
#define line5 "   forest seems to consume the shadows endlessly engorging"
#define line6 "   itself, in a feeding orgy."

reset(arg) {
     if(arg) return;

     set_light(1);
     short_desc=(GRN+"The Chaos Wood"+NORM);
     long_desc=
       ""+GRN+"#####"+NORM+line1+"   \n"+
       ""+GRN+"#"+NORM+"+--+ "+NORM+line2+"   \n"+
       ""+NORM+"-|"+GRN+"##"+NORM+"X"+NORM+line3+"   \n"+
       ""+GRN+"#"+NORM+"|"+GRN+"##"+NORM+"|"+NORM+line4+"   \n"+
       ""+GRN+"#"+NORM+"+--+"+NORM+line5+"   \n"+
       ""+GRN+"#####"+NORM+line6+"\n";
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
     
     
     "/players/jareel/areas/chaos/grid2/for13","north",
     "/players/jareel/areas/chaos/grid2/for6","south",
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
