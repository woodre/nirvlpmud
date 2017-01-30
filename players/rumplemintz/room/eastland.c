inherit "room/room";

reset(arg)
{
  if(!arg)
    {
      set_light(1);
      short_desc = "East Landing";
      long_desc = "     This is the Eastern Landing of Town Central, from here you can\n"+
		"venture Northeast, to Lord Bane's area, East, to the Land of Kor\n"+
		"Southeast, to the Selentine Lands, or West will take you back to\n"+
		"Town Central.\n";

      dest_dir =
        (
         {
	   "players/rumplemintz/room/central", "west",
	   "players/rumplemintz/room/blanding", "northeast",
           "players/rumplemintz/room/klanding", "east",
           "players/rumplemintz/room/slanding", "southeast",
         }
         );
      
    }
}

