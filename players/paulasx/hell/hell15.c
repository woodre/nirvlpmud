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
       "players/paulasx/hell/hell2", "north",
       "players/paulasx/hell/hell16", "south",
       "players/paulasx/hell/hell6", "east",
       "players/paulasx/hell/hell2", "west"
    });
}
