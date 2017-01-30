inherit "room/room";

reset(arg)
{
  if(!arg)
    {
      set_light(1);
      short_desc = "Storm Landing";
      long_desc="     This is the Landing of the Storm Giants.  From here, you can\n"+
		"venture West, into their land, or East, back to the Western Landing.\n";
      dest_dir =
        (
         {
	   "players/rumplemintz/room/storm/room1", "west",
	   "players/rumplemintz/room/westland", "east",
         }
         );
      
    }
}

