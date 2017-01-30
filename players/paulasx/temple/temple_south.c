inherit "room/room";

reset(arg)
{
   if(arg)
      return;
   short_desc = "South end of Temple Arena";
  long_desc = "You are in the south end of the Temple Arena.  People meet here to worship and\n" +
              "pray for hope.  You can see an altar to the north, and some people to the\n" +
              "west and east.  There is a strange smell all around, like something that has\n" +
              "died and is still rotting..\n\n";
   set_light(1);
   dest_dir =
   ({
       "players/paulasx/temple/temple_center", "north",
       "players/paulasx/temple/temple3.c", "south",
       "players/paulasx/temple/temple_se", "east",
       "players/paulasx/temple/temple_sw", "west"
    });
}

