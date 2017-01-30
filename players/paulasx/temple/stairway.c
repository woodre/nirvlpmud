inherit "room/room";

reset(arg)
{
   if(arg)
      return;
   short_desc = "A landing in a stairway";
   long_desc = "You are in a landing on the stairway.\n" +
               "The stairway goes up and disappears down\n" +
               "into the darkness. A passage leads west.\n";
   set_light(1);
   dest_dir =
   ({
       "players/paulasx/temple/temple3", "west",
      "players/paulasx/temple/stairway_up", "up",
      "players/paulasx/temple/stairway_down", "down",
    });
}
