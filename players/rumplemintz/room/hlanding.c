inherit "room/room";

reset(arg)
{
  if(!arg)
    {
      set_light(1);
      short_desc = "Horse Lord's Landing";
      long_desc="     This is the Horse Lord's Landing.  From here, you can go\n"+
		"Northwest, into their area, or Southeast, back to the West Landing.\n";
      dest_dir =
        (
         {
	   "players/rumplemintz/room/hlords/room1", "northwest",
	   "players/rumplemintz/room/westland", "southeast",
         }
         );
      
    }
}

