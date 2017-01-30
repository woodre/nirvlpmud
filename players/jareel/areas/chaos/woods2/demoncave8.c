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
      
  if(set_light(0) > -4) set_light(-4);
  short_desc=(HIK+"Cave of the Dark Demon"+NORM);
  long_desc=
    HIK+"@@@@@@"+NORM+"   As you look around the tower, the gray stone seems to absorb\n"+
    HIK+"@"+NORM+"----"+HIK+"@"+NORM+"   all light. The smell of methane and decaying flesh fills the\n"+
    HIK+"@"+NORM+"|"+HIK+"@@"+NORM+"|-   air, burning your nostrils.  Assorted human, and not so human,\n"+
    HIK+"@"+NORM+BOLD+"X"+NORM+"-"+BOLD+YEL+"*"+HIK+"@@"+NORM+"   bones lay strewn across the cavern's floor.  Death lingers in\n"+
    HIK+"@@@@@@"+NORM+"   the air.\n";
  items = ({
    "cavern","The walls of the cavern are covered with a slimy mucus",
    "wall","A thin, muscus film coats the wall",
    "mucus","You see a substance drip off the moss and down the wall",
    "moss","A basic form of plant life that coats a lot of the wall",
    "rocks","Chips of stone can be found in the cavern's corners",
    "chips","Pieces of the cavern's walls litter the floor",
    "light","To the south a light illuminates the room",
    "east","You see that the cavern continues",
    "south","It appears to be an illuminated room",
    "flower","Several small, purple flowers blossom in the moss",
    "blossom","The flower looks very delicate",
    "stone","The stone has an eerie, grayish hue",
    "stones","The stones have an eerie, grayish hue",
    "pile","The remains of human bones",
    "flesh","Pieces of flesh cling to splintered bones that lie covering the floor",
    "bones","Shards of bone lay cover the floor",
    "remains","The scraps of human, and not-so-human, creatures clutter the cave's floor",
    "floor","The floor is cluttered with the remains of a variety of creatures",
  });

  dest_dir = ({
    "/players/jareel/areas/chaos/woods2/demoncave7","north",
    "/players/jareel/areas/chaos/woods2/demoncave9","east",
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
    move_object(clone_object(MON+"dark_demon.c"),this_object());
 
    if(random(5) == 1) {
        move_object(clone_object(MON+"dark_demon.c"),this_object());
  
    if(random(3) == 1)
        move_object(clone_object(MON+"dark_demon.c"),this_object());
    }
}

getmonsters_21to75() {

    if(1 == random(3))
        move_object(clone_object(MON+"dark_demon.c"),this_object());

    if(1 == random(5))
        move_object(clone_object(MON+"dark_demon.c"),this_object());

    if(1 == random(4))
        move_object(clone_object(MON+"dark_demon.c"),this_object());

    if(1 == random(4))
        move_object(clone_object(MON+"dark_demon.c"),this_object());

    if(1 == random(6))
        move_object(clone_object(MON+"dark_demon.c"),this_object());

    if(1 == random(5)) {
        move_object(clone_object(MON+"dark_demon.c"),this_object());

    if(random(3)==1)
        move_object(clone_object(MON+"dark_demon.c"),this_object());
    }
}

getmonsters_default() {

    if(random(50)==1)  move_object(clone_object(MON+"dark_demon.c"),this_object());

    if(random(20)==1)  move_object(clone_object(MON+"dark_demon.c"),this_object());

    if(random(17)==1){  move_object(clone_object(MON+"dark_demon.c"),this_object());

    if(random(2)==1) move_object(clone_object(MON+"dark_demon.c"),this_object()); }

    if(random(15)==1)  move_object(clone_object(MON+"dark_demon.c"),this_object());

    if(random(10)==1)  move_object(clone_object(MON+"dark_demon.c"),this_object());

    if(random(7)==1)  move_object(clone_object(MON+"dark_demon.c"),this_object());

    if(random(5)==1)  move_object(clone_object(MON+"dark_demon.c"),this_object());

    if(random(5)==1)  move_object(clone_object(MON+"dark_demon.c"),this_object());

    if(random(3)==1)  move_object(clone_object(MON+"dark_demon.c"),this_object());
}


Search(str) {
      if(!str) { write("Search what?\n"); return 1; }
        write("You search the "+str+" but find nothing special.\n");
        say(this_player()->query_name()+" searches around for something.\n");
      return 1;
}
