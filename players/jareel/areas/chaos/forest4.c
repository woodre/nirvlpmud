inherit "/players/jareel/room";
#include "/players/jareel/define.h"

     reset(arg) {

       if(!present("broo"))  {
         MOCO("/players/jareel/monsters/chaos/broo.c"),this_object()); 
       }
       
       if(arg) return;
       set_light(1);
       short_desc=(GRN+"The Chaos Wood"+NORM);
       long_desc=
         ""+HIK+"@"+NORM+GRN+"#####"+NORM+"   Large colorful trees line the forest path.  To the north\n"+
         ""+HIK+"@"+NORM+"---"+HIK+"T"+NORM+GRN+"#"+NORM+"   the path continues deeper into the Wood, while smaller paths\n"+
         ""+HIK+"@"+NORM+GRN+"#"+NORM+"|"+NORM+BOLD+"X"+NORM+"|"+GRN+"#"+NORM+"   branch to the east and west, leading to the unknown.  The\n"+
         ""+HIK+"@"+NORM+GRN+"#"+NORM+"|"+NORM+GRN+"###"+NORM+"   little light the canopy allows to pass cast deep shadows over\n"+
         ""+HIK+"@"+NORM+GRN+"#"+NORM+"|"+GRN+"###"+NORM+"   the forest floor.\n";
       items = ({
         "forest","Large gnarled intertwined branches make up the walls of the Wood",
         "floor","Grass and dirt make up the vast surface of the forests floor",
         "shadow","Shadows dance over the roads path",
         "branches","The forest path leads to the north, west and east here",
         "branch","The forest path leads to the north, west and east here",
         "shadows","The shadows flicker over the dirt road",
         "grass","The blades of grass sway together over the floor of the Wood following your every move",
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
         "light","The light is obscured by the canopy of trees",
       });

dest_dir = ({
      "/players/jareel/areas/chaos/forest7","north",
      "/players/jareel/areas/chaos/forest5","east",
      "/players/jareel/areas/chaos/forest3","west",
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
