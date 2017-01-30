inherit "/players/jareel/room";
#include "/players/jareel/define.h"

     reset(arg) {
     
     add_property("no_teleport");
     add_property("fight_area");

     if(!present("demon"))  {
     if(!present("sembrak"))  {
       MOCO("/players/jareel/monsters/chaos/sembrak.c"),this_object());
     }
       MOCO("/players/jareel/monsters/chaos/ice_demon.c"),this_object());
       MOCO("/players/jareel/monsters/chaos/ice_demon.c"),this_object());
     }
     
     if(arg) return;

     set_light(0);
     short_desc=(BOLD+BLK+"Sembrak Tower"+NORM);
     long_desc=
       ""+HIK+"     The third floor of the tower is covered with a red mucus bile,\n"+
       "that sticks to anything it touches.  The bones and weapons that lay in\n"+
       "mucus dissolve in its acidic nature.  The walls are decorated with half\n"+
       "eaten corpses, rotten and maggot ridden.  The air permeates a methane\n"+
       "death that lingers, and eats anything in the area."+NORM+"\n";
     items = ({
       "corpse","A sick and twisted trophy of a fallen hero",
       "walls","Sick, rotting, decaying corpses hang on the wall as a decoration",
       "wall","Sick, rotting, decaying corpses hand on the wall as a decoration",
       "bone","Shards of bone lay over the floor",
       "weapon","The weapons are like wet noodles laying in a soup",
       "weapons","The weapons are like wet noodles laying in a soup",
       "corpses","Sick and twisted trophys of fallen heros",
       "maggot","Small twisting creatures eating the dead flesh",
       "maggots","Small twisting creatures eating the dead flesh",
       "mucus","A red bile that can dissolve anything it touches",
       "bile","A red bile that can dissolve anything it touches",
       "tower","The tower swarms with the very essence of chaos",
       "stones","The stones have an eerie grayish huge",
       "pile","The remains of human bones",
       "flesh","Pieces of flesh cling to splintered bones that lie over the floor",
       "bones","Shards of bone lay over the floor",
       "floor","The floor is littered with the remains of a variety of creatures",
       "stairs","You could go up them to get to the next floor",
     });

dest_dir = ({
     "/players/jareel/areas/chaos/tower/floor2","down",
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
