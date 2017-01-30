inherit "room/room";

reset(arg)
{
  if(!arg)
    {
      set_light(1);
      short_desc = "Bane Landing";
      long_desc = "     This is the Landing of Lord Bane, from here you can go\n"+
		"Northeast, to his lands, or Southwest back to the East Landing.\n";
      dest_dir =
        (
         {
	   "players/rumplemintz/room/bane/room1.c", "northeast",
	   "players/rumplemintz/room/eastland", "southwest",
         }
         );
      
    }
}

