inherit "/players/softly/point/rooms/std_lh.c";
  reset(arg) {
  object p;
  ::reset();
    if(p = present("blackbeard", this_object()))
    {
      move_object(p, "/room/void");
      destruct(p);
    }
  if(arg) return;

long_desc =
"  A thin iron railing surrounds the outer edge of the\n"+
"platform.  The large blinking beacon illuminates the area\n"+
"intermittently.  The platform surrounds the center door.\n";

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
"railing",
"The railing intended to prevent falling is fragile",
  });


dest_dir = ({
  "/players/softly/point/rooms/lh12.c","southwest",
  "/players/softly/point/rooms/lh15.c","south",
  });
}

