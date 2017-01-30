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
       "players/paulasx/hell/hell_end", "north",
       "players/paulasx/hell/hell1", "south",
       "players/paulasx/hell/hell5", "east",
       "players/paulasx/hell/hell2", "west"
    });
}
