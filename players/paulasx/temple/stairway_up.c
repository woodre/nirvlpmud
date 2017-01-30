inherit "room/room";

reset(arg)
{
   if(arg)
      return;
   short_desc = "You are on a landing in the stairway";
   long_desc = "You are on a landing in the stairway.\n" +
               "The stairway continues up and down and\n" +
               "you can also go north into the hall.\n" +
               "On the east wall you can see a large painting\n" +
               "of Benju and his new world order killing the\n" +
               "citizens of Legacy, and you feel enraged!!\n";
   dest_dir =
   ({
       "players/paulasx/temple/stairway", "down",
       "players/paulasx/temple/stairway_top", "up",
       "players/paulasx/temple/hallway1", "north"
    });
   items =
   ({
        "painting", "The large painting covers the wall from ceiling to floor.\n" +
                    "It is fastened to the wall with some large nails and it looks\n" +
                    "almost impossible to get loose"
    });
}
