inherit "/players/jareel/room";
#include "/players/jareel/define.h"

     reset(arg) {
     add_property("fight_area");
  
     if(!present("demon"))  {
       MOCO("/players/jareel/monsters/chaos/ice_demon.c"),this_object()); 
     }

     if(arg) return;
     
     set_light(0);
     short_desc=(BOLD+BLK+"Sembrak Tower"+NORM);
     long_desc=
       ""+HIK+"     As you look around the tower the gray stone seems to absorb all\n"+
       "light.  The smell of methane and decaying flesh fills the air, burning\n"+
       "your nostrils.  Assorted human (and not-so-human) bones lay strewn\n"+
       "across the tower's floor.  Death lingers in the air."+NORM+"\n";
     items = ({
       "remains","The scraps of human and not-so-human creatures litter the tower's floor",
       "stone","The stones have an eerie grayish huge",
       "tower","The tower swarms with the very essence of chaos",
       "stones","The stones have an eerie grayish huge",
       "pile","The remains of human bones",
       "flesh","Pieces of flesh cling to splintered bones that lie over the floor",
       "bones","Shards of bone lay over the floor",
       "floor","The floor is littered with the remains of a variety of creatures",
       "stairs","You could go up them to get to the next floor",
     });

dest_dir = ({
     "/players/jareel/areas/chaos/tower/floor3","up",
     "/players/jareel/areas/chaos/tower/floor1","down",
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
