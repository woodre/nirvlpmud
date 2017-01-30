inherit "room/room";
reset(arg) {
  set_light(1);
  short_desc=("A clearing");
  long_desc=
"This is the edge of a clearing. It extends to the west.\n"+
"You can see a pack of wild animals standing in a circle.\n"+
"As if they are in some sort of meeting. To the southwest\n"+
"you see a cave.\n";
  dest_dir=
    ({
      "/players/bagera/jungle/room9.c", "west",
      "/players/bagera/jungle/room17.c", "southwest",
      "/players/bagera/jungle/room18.c", "south",
      "/players/bagera/jungle/room11.c", "east",
      "/players/bagera/jungle/room2.c", "north"
          });
   }
