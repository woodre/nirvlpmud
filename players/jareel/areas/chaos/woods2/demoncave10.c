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

reset(arg) {

  if(!present("demon"))  {
  if(!present("sembrak"))  {
    MOCO("/players/jareel/monsters/chaos/woods2/cacodemon.c"),this_object());
  }
    MOCO("/players/jareel/monsters/chaos/woods2/dark_demon.c"),this_object());
    MOCO("/players/jareel/monsters/chaos/woods2/dark_demon.c"),this_object());
    MOCO("/players/jareel/monsters/chaos/woods2/dark_demon.c"),this_object());
  }

  if(arg) return;
      
   if(set_light(0) > -8) set_light(-8);
  short_desc=(HIK+"Liar of Cacodemon"+NORM);
  long_desc=
    HIK+"@@@@@@"+NORM+"   As you look around the tower, the gray stone seems to absorb\n"+
    HIK+"@"+NORM+"----"+HIK+"@"+NORM+"   all light.  The smell of methane and decaying flesh fills the\n"+
    HIK+"@"+NORM+"|"+HIK+"@@"+NORM+"|-   air, burning your nostrils.  Maggot ridden corpses, decaying\n"+
    HIK+"@"+NORM+"|-"+BOLD+YEL+"X"+HIK+"@@"+NORM+"   and half eaten, adorn the cavern wall.  Death hangs in the\n"+
    HIK+"@@@@@@"+NORM+"   air.\n";
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
    "/players/jareel/areas/chaos/woods2/demoncave9","west",
  });
}

Search(str) {
  if(!str) { write("Search what?\n"); return 1; }
    write("You search the "+str+" but find nothing special.\n");
    say(this_player()->query_name()+" searches around for something.\n");
  return 1;
}
