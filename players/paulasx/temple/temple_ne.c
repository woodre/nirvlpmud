inherit "room/room";

reset(arg)
{
   if(arg)
      return;
   short_desc = "Temple Arena";
   long_desc = "You are in the northeast corner of the arena, the smell of death continues.\n";
   set_light(1);
   dest_dir =
   ({
       "players/paulasx/temple/temple_east", "south",
/*
       "players/paulasx/temple/temple_north", "west",
*/
    });
}
