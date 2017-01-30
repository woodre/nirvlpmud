#include "/players/fred/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "School";
long_desc =
"  You are standing in the entryway of the South Park school.\n"+
"As you look around you see all the things you would come to\n"+ 
"expect in a school.  There are a few plaques, several rows of\n"+
"lockers and a drinking fountain.\n";

items = ({
  "plaques",
  "A few important looking plaques are displayed behind a glass\n"+
  "display case", 
  "lockers",
  "They are made of solid steel and have graffiti drawn all\n"+
  "all over them", 
  "fountain",
  "The drinking fountain has a white porcelain base",
  "case",
  "The case has a large glass viewing window, and holds all of\n"+
  "the school's accomplishments",
  });

dest_dir = ({
  "/players/fred/SP/Rooms/r3.c","out",
  "/players/fred/SP/Rooms/r16.c","lunch",
  "/players/fred/SP/Rooms/r17.c","class",
  });
}
