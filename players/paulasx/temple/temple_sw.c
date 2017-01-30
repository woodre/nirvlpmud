inherit "room/room";

reset(arg)
{
   if(arg)
      return;
   short_desc = "Temple Arena";
   long_desc = "You are in the southwest corner of the arena, the smell of death continues.\n";
   set_light(1);
   dest_dir =
   ({
       "players/paulasx/temple/temple_west", "north",
       "players/paulasx/temple/temple_south", "east",
    });
}
