inherit "room/room";

reset(arg)
{
   if(arg)
      return;
   short_desc = "You are in hell";
   long_desc = "You are in hell, the smell of sulphur penetrates everything.\n";
   set_light(1);
   dest_dir =
   ({
       "players/paulasx/hell/hell4", "north",
       "players/paulasx/hell/hell5", "south",
       "players/paulasx/hell/hell3", "east",
       "players/paulasx/hell/hell5", "west"
    });
}
