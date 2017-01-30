#include "/players/catacomb/misc/ansi.h"
#define TP this_player()
#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc =("Durkor Caverns");
long_desc =(
"  The bridge lies to the north providing what appears to be safe\n"+
"passage to the other side.  The rocks reaching down from the ceiling\n"+
"suggest that there may be more to crossing the bridge than what there\n"+
"appears to be.  None the less the only ways out of the area are to the\n"+
"north across the bridge or east, down the stairs.\n");

if(!present("mage"))
	  move_object(clone_object("/players/catacomb/Cavern/mobs/Dmage.c"),
	    this_object());

items = ({
  "bridge",
  "The bridge is very sturdy but something gives you an eerie feeling about it,\n"+
  "perhaps you could "+HIW+"'cross'"+NORM+" it.", 
  "staircase",
  "The staircase leads down to the east", 
  "rocks",
  "Large rocks hang from the ceiling providing cover for the Durkor",
  "ceiling",
  "Large rocks hang from the ceiling providing cover for the Durkor"
  });

dest_dir = ({
  "/players/catacomb/Cavern/rooms/lvl3_10.c","east", 
  });
  }

init()
{
  ::init();
  
      add_action("crossing","cross");  
}

crossing(str)
{
  int chance;
  chance = random(10);
  if (str == "bridge")
  {
    if (present("mage"))
    {
        write("You try to cross the bridge but the warrior blocks your path.\n");
        say(TPN+" tries to cross the bridge but the warrior blocks them.\n");
        return 1;
    }
    else
    {
     if (chance <= 2) 
     {
       write("You fall from the rocks to the ground below.\n");
       say(TPN+" falls to the ground below.\n");
       TP->move_player("cross#/players/catacomb/Cavern/rooms/lvl3_9.c");
       return 1;
     }
     else 
     {
        TP->move_player("cross#/players/catacomb/Cavern/rooms/lvl3_12.c");
        return 1;
     }
    }
  }
  else if (str != "bridge")
  {
    write("Cross what?");
    return 1;
  }
}
