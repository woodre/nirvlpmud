inherit "room/room";

reset(arg)
{
  if(!arg)
    {
      set_light(1);
      short_desc = "Dwarf Lord's Landing";
      long_desc="     This is the Dwarf Lord's Landing, from it you can venture\n"+
		"North, into the Land they own, or South, back to Town Central.\n";
      dest_dir =
        (
         {
	   "players/rumplemintz/room/dlords/room1", "north",
	   "players/rumplemintz/room/central", "south",
         }
         );
      
    }
}

