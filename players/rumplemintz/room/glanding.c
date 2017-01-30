inherit "room/room";

reset(arg)
{
  if(!arg)
    {
      set_light(1);
      short_desc = "Druid Landing";
      long_desc="     This is the Druid Landing.  From here, you can either go\n"+
		"Southwest, to the Druid Lounge, or Northeast, back to the West Landing.\n";
      dest_dir =
        (
         {
           "players/rumplemintz/guild/guild", "southwest",
	   "players/rumplemintz/room/westland", "northeast",
         }
         );
    }
}

