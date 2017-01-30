#include "/sys/lib.h"
#include "/players/pestilence/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = ""+HIC+"Amity Memorial Hospital <403>"+NORM+"";
long_desc =
  "    This is one of the rooms that the patients of the insanity ward \n"+
  "sleep in.  The floor tiles are spotless.  The walls are covered with\n"+
  "padding from floor to ceiling.  Two beds sit in this room, with two\n"+
  "small tables.  It seems as if there is very few things allowed in\n"+
  "these rooms, as it is fairly empty.\n";
set_light(1);

items = ({
  "lobby","It's to the east, but hard to make out.",
  "door","The door to the north, swings easily open.",
});

dest_dir = ({
  "/players/pestilence/hospital/room/4whall2.c","out",
});
}
