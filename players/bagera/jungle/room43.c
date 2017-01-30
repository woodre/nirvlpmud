inherit "room/room";
reset(arg) {
  set_light(1);
  short_desc=("Old stone structure");
  long_desc=
    "You are inside the stone structure. There are\n"+
    "crumpled and broken stones lieing everywhere. You\n"+
    "see banana peelings strewn all over the floor of\n"+
    "this delapidated stone structure. You hear squealing\n"+
    "coming from the other rooms.\n";
  dest_dir=
   ({
      "/players/bagera/jungle/room51.c", "south",
      "/players/bagera/jungle/room44.c", "east",
  });
 }
