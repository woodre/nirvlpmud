/*
===================================================================
=Chaos Wood add on started 5/10/06
=Creator Jareel
=
=This area will House Some tuff monsters 
=in the theme I have created in my area.
=
=A Humakti Temple will be located in 
=the woods where I may have Mondar 
=teleport too so he is tuffer to kill
=and not farmed as much as he is now
=
=As with most of the stuff I have created
=it will not be a cake walk and is designed
=to be entertaining for players of a high
=level.
===================================================================
*/

inherit "/players/jareel/room";
#include "/players/jareel/define.h"
#define MON "/players/jareel/monsters/chaos/woods2/"

int monsters;

reset(arg) {
  if(arg) return;
      
  set_light(1);
  short_desc=(GRN+"The Chaos Wood"+NORM);
  long_desc=
    HIK+"@"+NORM+GRN+"#####"+NORM+"   Large, colorful trees line the forest path.  To the west\n"+
    HIK+"@"+NORM+"---"+BOLD+"X"+NORM+GRN+"#"+NORM+"   and south the path weaves its way into the Wood.  The\n"+
    HIK+"@"+NORM+GRN+"##"+NORM+"||"+GRN+"#"+NORM+"   forest to the north and east impeads any progression.  The\n"+
    HIK+"@"+NORM+GRN+"#"+NORM+"H++-"+NORM+"   canopy allows a few rays of light to pass, creating deep\n"+
    HIK+"@"+NORM+GRN+"##"+NORM+"-|"+GRN+"#"+NORM+"   shadows.  These shadows seem to watch your every move.\n";
  items = ({
    "Ruins","What appears to be ruins just past some overgrown vegitation",
    "road","The road is made of a grayish dirt; it has seen a lot of travel",
    "shadow","The shadows flicker over the dirt road",
    "dirt","The fine gray dirt sifts between your fingers",
    "canopy","Most of the sky is concealed by the large amount of trees",
    "sky","The sky is hard to see past the canopy",
    "trees","The trees loom overhead, menacing your every move",
    "path","The road is made of a grayish dirt; it has seen a lot of travel",
    "forest","Large gnarled intertwined branches make up the walls of the Wood",
    "shadows","Shadows flicker over the dirt road",
    "wood","The trees loom overhead, menacing your every move",
    "tree","The trees loom overhead, menacing your every move",
    "light","The light is obscured by the canopy of trees",
    "rays","The light is obscured by the canopy of trees",
  });

  dest_dir = ({
    "/players/jareel/areas/chaos/woods2/cwf3","west",
    "/players/jareel/areas/chaos/woods2/cwf6","south",
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
    move_object(clone_object(MON+"skeleton.c"),this_object());

    if(random(2) == 1) move_object(clone_object(MON+"rhino_broo.c"),this_object());
}

getmonsters_06to20() {
    move_object(clone_object(MON+"skeleton.c"),this_object());
 
    if(random(5) == 1) {
        move_object(clone_object(MON+"rhino_broo.c"),this_object());
  
    if(random(3) == 1)
        move_object(clone_object(MON+"broo.c"),this_object());
    }
}

getmonsters_21to75() {

    if(1 == random(3))
        move_object(clone_object(MON+"skeleton.c"),this_object());

    if(1 == random(5))
        move_object(clone_object(MON+"rhino_broo.c"),this_object());

    if(1 == random(4))
        move_object(clone_object(MON+"broo.c"),this_object());

    if(1 == random(4))
        move_object(clone_object(MON+"skeleton.c"),this_object());

    if(1 == random(6))
        move_object(clone_object(MON+"rhino_broo.c"),this_object());

    if(1 == random(5)) {
        move_object(clone_object(MON+"broo.c"),this_object());

    if(random(3)==1)
        move_object(clone_object(MON+"rhino_broo.c"),this_object());
    }
}

getmonsters_default() {

    if(random(50)==1)  move_object(clone_object(MON+"skeleton.c"),this_object());

    if(random(20)==1)  move_object(clone_object(MON+"rhino_broo.c"),this_object());

    if(random(17)==1){  move_object(clone_object(MON+"broo.c"),this_object());

    if(random(2)==1) move_object(clone_object(MON+"skeleton.c"),this_object()); }

    if(random(15)==1)  move_object(clone_object(MON+"skeleton.c"),this_object());

    if(random(10)==1)  move_object(clone_object(MON+"rhino_broo.c"),this_object());

    if(random(7)==1)  move_object(clone_object(MON+"broo.c"),this_object());

    if(random(5)==1)  move_object(clone_object(MON+"skeleton.c"),this_object());

    if(random(5)==1)  move_object(clone_object(MON+"rhino_broo.c"),this_object());

    if(random(3)==1)  move_object(clone_object(MON+"broo.c"),this_object());
}

Search(str) {
      if(!str) { write("Search what?\n"); return 1; }
        write("You search the "+str+" but find nothing special.\n");
        say(this_player()->query_name()+" searches around for something.\n");
      return 1;
}
