inherit "/players/jareel/room";
#include "/players/jareel/define.h"
#define MON "/players/jareel/monsters/chaos/woods2/"

int monsters;
	 
 void setDescriptions() {
   
   string *line1,*line2,*line3,*line4;
   
   line1 = ({ });
   line2 = ({ });
   line3 = ({ });
   line4 = ({ });
   
   line1 += ({ "Large colourful trees surround the long isolated worn driven path." });
   line1 += ({ "Large trees loom ominously overhead seemingly watching every move." });
   line1 += ({ "Large swaying branches creek in the wind as trees move overhead." });
   line1 += ({ "Large colourful trees let little light in past the dense canopy." });
   line1 += ({ "Large swaying branches sway overhead creating ominous shadows ahead." }); 
   
   line2 += ({ "Flowing mystical energy creates a quiescent aura that flow in the air." });
   line2 += ({ "A crackling mystical energy creates a powerful aura throughout the air." });
   line2 += ({ "A crackling mystical energy creates a powerful aura throughout the air." });
   line2 += ({ "Crackling mystical energy permeates the air creating a powerful aura." });   
   
   line3 += ({ "Heavily travelled dirt lies beneath every step taken along the path." });
   line3 += ({ "Worn beaten heavily travelled dirt lies beneath every weary stride. " });
   line3 += ({ "A Heavily trodden dirt path lies beneath every weary stride you take."  });
   
   line4 += ({ "Dark shifting shadows ebb and flow over the forest floor." });
   line4 += ({ "Rolling shadows shift over the forest floor causing dark illusions." });
   line4 += ({ "Shifting shadows cause stark illusions over the dirt road." });
   line4 += ({ "Running shadows shift and flow over to forest floor." });   
   
        long_desc=
       GRN+"####"+NORM+"|"+NORM+GRN+"######     "+NORM+"   \n"+
       GRN+"#"+NORM+"|------X--   "+NORM+line1[random(sizeof(line1))]+"\n"+
       GRN+"#"+NORM+"|"+NORM+GRN+"######"+NORM+"|"+NORM+GRN+"##   "+NORM+line2[random(sizeof(line2))]+"\n"+
       GRN+"#"+NORM+"|"+NORM+GRN+"#"+NORM+HIK+"S"+NORM+GRN+"####"+NORM+"|"+NORM+GRN+"##   "+NORM+line3[random(sizeof(line3))]+"\n"+
       GRN+"#"+NORM+"|-|"+NORM+GRN+"####"+NORM+"|"+NORM+GRN+"##   "+NORM+line4[random(sizeof(line4))]+"\n"+
       GRN+"#####"+NORM+HIY+"H"+NORM+"--|"+NORM+GRN+"##"+NORM+"   \n"+ 
       GRN+"###########"+NORM+"\n";
}

reset(arg) {
     if(arg) return;

     set_light(1);
     short_desc=(GRN+"The Chaos Wood"+NORM);
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
     
 "/players/jareel/areas/chaos/woods4/wood4","west",
  "/players/jareel/areas/chaos/woods4/wood2","east",
    "/players/jareel/areas/chaos/woods4/wood12","south",
  
});

get_monsters(); }

get_monsters() {
  int i;
    i = random(100);
    monsters = 1;

    switch(i)
    {
    case 0..5:
        getmonsters_00to05();
    break;


    case 6..20:
        getmonsters_06to20();
    break;


    case 21..75: 
        getmonsters_21to75();
    break;

    
    case 76..90: 
    break;

    
    default:
        getmonsters_default();
    break; 
    }
}

getmonsters_00to05() {
    move_object(clone_object(MON+"dark_demon.c"),this_object());

    if(random(2) == 1) move_object(clone_object(MON+"dark_demon.c"),this_object());
}

getmonsters_06to20() {
    move_object(clone_object(MON+"skeleton.c"),this_object());
 
    if(random(15) == 1) {
        move_object(clone_object(MON+"rhino_broo.c"),this_object());
  
    if(random(5) == 1)
        move_object(clone_object(MON+"broo.c"),this_object());
		move_object(clone_object(MON+"broo.c"),this_object());
		move_object(clone_object(MON+"broo.c"),this_object());
		move_object(clone_object(MON+"broo.c"),this_object());
		move_object(clone_object(MON+"broo.c"),this_object());
    }
}

getmonsters_21to75() {

    if(1 == random(3))
        move_object(clone_object(MON+"skeleton.c"),this_object());


    if(1 == random(2))
        move_object(clone_object(MON+"broo.c"),this_object());

    if(1 == random(4))
        move_object(clone_object(MON+"broo.c"),this_object());

    if(1 == random(4))
        move_object(clone_object(MON+"skeleton.c"),this_object());

    if(1 == random(5)) {
        move_object(clone_object(MON+"broo.c"),this_object());

    if(random(13)==1)
        move_object(clone_object(MON+"rhino_broo.c"),this_object());
    }
}

getmonsters_default() {

    if(random(5)==1)  move_object(clone_object(MON+"skeleton.c"),this_object());

    if(random(20)==1)  move_object(clone_object(MON+"rhino_broo.c"),this_object());

    if(random(2)==1){  move_object(clone_object(MON+"broo.c"),this_object());

    if(random(2)==1) move_object(clone_object(MON+"skeleton.c"),this_object()); }

    if(random(15)==1)  move_object(clone_object(MON+"skeleton.c"),this_object());

    if(random(20)==1)  move_object(clone_object(MON+"rhino_broo.c"),this_object());

    if(random(3)==1)  move_object(clone_object(MON+"broo.c"),this_object());

    if(random(5)==1)  move_object(clone_object(MON+"skeleton.c"),this_object());

    if(random(15)==1)  move_object(clone_object(MON+"rhino_broo.c"),this_object());

    if(random(2)==1)  move_object(clone_object(MON+"broo.c"),this_object());
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
