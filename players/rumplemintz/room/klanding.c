inherit "room/room";

reset(arg)
{
  if(!arg)
    {
      set_light(1);
      short_desc = "Kor Landing";
      long_desc="     This is the Landing for the Orcs of Kor.  From here, you can\n"+
		"go East, into Kor, or West, back to the East Landing.\n";
      dest_dir =
	({
	   "players/rumplemintz/room/kor/room1", "east",
	   "players/rumplemintz/room/eastland", "west",
	});
    }
}

