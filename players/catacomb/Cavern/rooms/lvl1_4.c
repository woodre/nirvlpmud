#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) 
{
  if(arg) return;
 set_light(1);

 short_desc ="The Durkor caverns";
 long_desc =(
 "  The bats screech at the intruders into their domain.  Lined \n"+
 "across the ceiling are thousands of bats waiting for their next\n"+
 "victims.  The passage is littered with rocks and boulders making\n"+
 "movement very limited.  The small amount of light creeping in \n"+
 "through the cracks in the ceiling does little to help deter the \n"+
 "evil pervading the area.\n");

 items = ({
   "bats",
   "The bats screech at you from their ceiling resting area", 
   "bat",
   "A single bat flies down at you in protest of your intrusion", 
   "ceiling",
   "Thousands of bats line the ceiling of the passage",
   "passage",
   "The low ceiling of the passage makes it difficult to avoid the bats",
   "rocks",
   "Several pieces of stone are scattered through the passage",
   "rock",
   "Several pieces of stone are scattered through the passage",
    "boulders",
   "Several pieces of stone are scattered through the passage",
   "boulder",
   "Several pieces of stone are scattered through the passage",
   "cracks",
   "Light seeps through the cracks in the ceiling",
   "crack",
   "Light seeps through the cracks in the ceiling"
   });

 dest_dir = ({
   "/players/catacomb/Cavern/rooms/lvl1_6.c","west",
   "/players/catacomb/Cavern/rooms/lvl1_3.c","south", 
   });

 if(!present("bat"))
	  move_object(clone_object("/players/catacomb/Cavern/mobs/bigbat.c"),
	    this_object());

}
