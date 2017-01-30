#include "/players/catacomb/misc/ansi.h"
#define TPN this_player()

inherit "room/room";

reset(arg) 
{
  if(arg) return;
  set_light(1);

  short_desc ="Second level of the Durkor Caverns" ;
  long_desc =(
  "  A single torch is placed on the rock wall to the south providing\n"+
  "little to no light to the passageway.  A sense of evil can be felt\n"+
  "nearby.  This area in the caves is so silent that it is almost \n"+
  "deafening.  The torch doesn't even crackle as it illuminates the\n"+
  "passageway.\n"); 

  items = ({
    "passage",
    "The silence of the passageway is almost deafening", 
    "torch",
    "The torch lights the passage silently", 
    "wall",
    "A single torch is on the wall",
  });

  dest_dir = ({
    "/players/catacomb/Cavern/rooms/lvl2_2.c","southwest",
    "/players/catacomb/Cavern/rooms/lvl2_4.c","southeast" 
  });

if(!present("scout"))
	  move_object(clone_object("/players/catacomb/Cavern/mobs/durkorScout.c"),
	    this_object());
}

init()
{
  ::init();
  
  add_action("hear","listen");
}

hear(str)
{
  write("You almost go "+HIY+"INS"+HIR+"ANE"+NORM+" trying to hear something.\n");
  say(TPN->query_name()+" almost goes "+YEL+"ins"+RED+"ane"+NORM+" trying to hear something.\n");
  return 1;
}