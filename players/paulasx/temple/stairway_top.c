inherit "room/room";

reset(arg)
{
   if(arg)
      return;
   set_light(1);
   short_desc = "You are on the upper landing";
   long_desc = "You are on a landing in the stairway. This place gives you \n" +
                      "a bad feeling, you feel truly depressed at the thought of\n" +
                      "going further through the Temple.\n";
   dest_dir = ({ "players/paulasx/temple/upper1", "north",
                 "players/paulasx/temple/stairway_up", "down",});
}
