inherit "/players/softly/point/rooms/std_lh.c";

  reset(arg) {
  if(arg) return;
  ::reset();

long_desc =
"  Through an open trap door atop the lighthouse is the\n\
beacon, a large blinking light pointing toward the southeast.\n\
It is mounted on raised iron scaffolding high above a broad\n\
platform.  The platform extends outward in all directions.\n";

items = ({
  "door",
"A wooden hinged door opens easily. ",
"lighthouse",
"The tall red and white striped lighthouse stands on\n\
 large bounders that rise from the sea.  It might be\n\
 reachable over the rocks",
"beacon",
"Although the lighthouse has been long abandoned,\n\
 the large yellow light still shines toward the\n\
 southeast, warning ships away from the rocks",
"scaffolding",
"An iron structure holds the beacon above the platform",
"platform",
"A surface extends outward six feet in all directions",
  });


dest_dir = ({
  "/players/softly/point/rooms/lh13.c","north",
  "/players/softly/point/rooms/lh14.c","northeast",
  "/players/softly/point/rooms/lh16.c","southeast",
  "/players/softly/point/rooms/lh17.c","south",
  "/players/softly/point/rooms/lh18.c","southwest",
  "/players/softly/point/rooms/lh19.c","west",
  "/players/softly/point/rooms/lh11.c","down",
  });
}

