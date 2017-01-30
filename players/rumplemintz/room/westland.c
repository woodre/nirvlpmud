inherit "room/room";

reset(arg)
{
  if(!arg)
    {
      set_light(1);
      short_desc = "West Landing";
      long_desc = "     This is the Western Landing of Town Central, from here you can\n"+
		"venture Northwest, to the Horse Lord area, West, to the Storm Giants\n"+
		"Southwest, to the Druid Lands, or East will take you back to\n"+
		"Town Central.\n";

      dest_dir =
        (
         {
	   "players/rumplemintz/room/central", "east",
	   "players/rumplemintz/room/hlanding", "northwest",
           "players/rumplemintz/room/stlanding", "west",
           "players/rumplemintz/room/glanding", "southwest",
         }
         );
      
    }
}

