inherit "room/room";

reset(arg) 
{
  if(arg) return;
 set_light(1);

 short_desc ="The Durkor caverns";
 long_desc =(
 "  A large wall of stone blocks passage to the west.  Across the \n"+
 "ceiling are strange forms that appear to be moving between the \n"+
 "stalactites.  Echoes from the many bats of the cave are reflected\n"+
 "off the wall to the west.  The only way to get out of here is to \n"+
 "the east.\n");

 items = ({
   "cavern",
   "The screeches echo off the dead end", 
   "wall",
   "The cave ends in a dead end here", 
   "cave",
   "The screeches echo off the dead end", 
   "stone",
   "The cave ends in a dead end here", 
   "forms",
   "Several sleeping bats litter the ceiling",
   "form",
   "Several sleeping bats litter the ceiling", 
   "bats",
   "Several sleeping bats litter the ceiling", 
   "bat",
   "Several sleeping bats litter the ceiling",
   "ceiling",
   "Several sleeping bats litter the ceiling",
   "stalactites",
   "The stalactites hide several bats",
   "stalactite",
   "The stalactites hide several bats",
   });

 dest_dir = ({
   "/players/catacomb/Cavern/rooms/lvl1_4.c","east", 
   });

  if(!present("bat"))
	  move_object(clone_object("/players/catacomb/Cavern/mobs/bigbat.c"),
	    this_object());


}
