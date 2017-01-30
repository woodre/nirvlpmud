inherit "room/room";

reset(arg)
{
   if(arg)
      return;
   short_desc = "Temple Overflow Room";
   long_desc = "You are in the overflow room for the temple gathering arena.  When people can\n" +
               "no longer fit into the arena, they must wait out here until there is room.\n" +
               "There is a stairway to the east; you feel rather inclined to leave it alone.\n\n";
   set_light(1);
   dest_dir =
   ({
       "players/paulasx/temple/stairway", "east",
       "players/paulasx/temple/temple_south", "north",
       "players/paulasx/temple/temple_dogs1", "south",
    });
}
