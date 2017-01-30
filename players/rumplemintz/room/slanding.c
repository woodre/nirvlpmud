inherit "room/room";

reset(arg)
{
  if(!arg)
    {
      set_light(1);
      short_desc = "Selentine Landing";
	long_desc = "     This is the Selentine Landing.  From here, you can venture\n"+
		"Southeast, into the lands of Selentine, or Northwest, back to the\n"+
		"Eastern Landing.\n";
      dest_dir=({
	   "players/rumplemintz/room/selen/room1", "southeast",
	   "players/rumplemintz/room/eastland", "northwest",
	});
    }
}

