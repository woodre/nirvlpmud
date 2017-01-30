inherit "/players/jareel/room";
#include "/players/jareel/define.h"
#define MON "/players/jareel/monsters/chaos/woods2/"

int monsters;
	 
 void setDescriptions() {
   
   string *line1,*line2,*line3,*line4,*line5;
   
   line1 = ({ });
   line2 = ({ });
   line3 = ({ });
   line4 = ({ });
   line5 = ({ });
   
   line1 += ({ "A larger hearthstone rests in a large large stone fireplace on the north" });
   
   line2 += ({ "wall.  Animal pelts and mounted heads hang on the walls of the establishment" });
   
   line3 += ({ "in a rustic decoration.  An eccentric menu hangs behind the bar, offering" });
   
   line4 += ({ "items to dine in and to take out.  The only obvious exit is back out to the" });
   
   line5 += ({ "Chaos Woods to the east." });

   
        long_desc=
NORM+"   \n"+
NORM+line1[random(sizeof(line1))]+"\n"+
NORM+line2[random(sizeof(line2))]+"\n"+
NORM+line3[random(sizeof(line3))]+"\n"+
NORM+line4[random(sizeof(line4))]+"\n"+
NORM+line5[random(sizeof(line5))]+"\n"+
NORM+"\n";
}

reset(arg) {

if(!present("malikir"))  {
MOCO("/players/jareel/monsters/LUNAR/CrimsonBat/Malikir.c"),this_object()); }
if(!present("joe"))  {
MOCO("/players/jareel/monsters/town/bar_shop_owner.c"),this_object()); }
if(!present("menu"))  {
MOCO("/players/jareel/general_stuff/bar_shop_menu.c"),this_object()); }

     if(arg) return;

     set_light(1);
     short_desc=(HIY+"Hog-N-Bones"+NORM);
     setDescriptions();
    
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
     
 "/players/jareel/areas/chaos/woods4/wood19","east",

  
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
