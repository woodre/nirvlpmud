inherit "/players/jareel/room";
#include "/players/jareel/define.h"

reset(arg) {
     if(arg) return;

     set_light(1);
     short_desc=(GRN+"The Chaos Wood"+NORM);
     long_desc=
       ""+HIK+"@"+NORM+GRN+"#####"+NORM+"   Large colorful trees line the forest path.  To the north\n"+
       ""+HIK+"@"+NORM+"---"+HIK+"T"+NORM+GRN+"#"+NORM+"   the path continues deeper into the Wood.  The small town\n"+
       ""+HIK+"@"+NORM+GRN+"#"+NORM+"|+|"+GRN+"#"+NORM+"   of Hendrickville lies to the south.  The trees allow only\n"+
       ""+HIK+"@"+NORM+GRN+"#"+NORM+"|"+GRN+"###"+NORM+"   a few rays of light past their canopy, creating deep dark\n"+
       ""+HIK+"@"+NORM+GRN+"#"+NORM+BOLD+"X"+NORM+GRN+"###"+NORM+"   shadows, that seem to watch your every move.\n";
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
       "path","The road is less apparent here, and has patches of grass growing sparingly along its route",
       "wood","The trees loom overhead menacing your every move",
       "tree","Twisted and gnarled in a myriad of colors the trees themselves are chaotic",
       "light","The light is obscured by the canopy of trees",
       "forest","A gnarled myriad of trees interlace around you",
       "shadows","Shadows dance over the roads path",
       "rays","Few sunbeams escape into the Chaos Wood",
});

dest_dir = ({
     "/players/jareel/areas/entrance/road3","south",
     "/players/jareel/areas/chaos/forest2","north",
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
