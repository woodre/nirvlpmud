#include "/players/catacomb/misc/ansi.h"
#define TP this_player()
#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc =("Durkor Caverns");
long_desc =(
"  A large bridge lies to the south providing passage to the Durkor's\n"+
"underground city.  The bridge is very close to the ceiling and the \n"+
"rocks hanging down make passage difficult, but it is still possible\n"+
"to "+HIW+"'cross'"+NORM+" to the other side of the bridge.\n");

if(!present("mage"))
	  move_object(clone_object("/players/catacomb/Cavern/mobs/Dumage.c"),
	    this_object());

items = ({
  "bridge",
  "A stone bridge lies to the south.\nPerhaps you could cross it", 
  "rocks",
  "Several rocks reach down from the ceiling making crossing trecherous at times", 
  "ceiling",
  "Several rocks reach down from the ceiling making crossing trecherous at times",
  });

dest_dir = ({
  "/players/catacomb/Cavern/rooms/lvl3_13.c","east", 
  });
  }

init()
{
  ::init();
  
      add_action("crossing","cross");  
}

crossing(str)
{
  if (str == "bridge")
  {
    write("You carefully cross the bridge.\n");
    say(TPN+" carefully crosses the bridge.\n");
    TP->move_player("cross#/players/catacomb/Cavern/rooms/lvl3_11.c");
    return 1;
  }
  else
  {
    write("Cross what?\n");
    return 1;
  }
}