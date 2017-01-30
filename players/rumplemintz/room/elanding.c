inherit "room/room";

reset(arg)
{
  if(!arg)
    {
      set_light(1);
      short_desc = "Elevallie Landing";
      long_desc="     This is the Landing for Elevallie.  From here you can go South\n"+
		"into Elevallie, or North back to Town Central.\n";
      dest_dir=({
	   "players/rumplemintz/room/elevall/gate", "south",
	   "players/rumplemintz/room/central", "north",
	});
    }
}

