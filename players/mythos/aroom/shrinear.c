#include "/players/mythos/closed/ansi.h"
inherit "room/room";
reset(arg) {
  if(!present("messenger")) {
    move_object(clone_object("/players/mythos/prac/mess.c"),this_object()); }
  if(!arg) {
  set_light(1);
    short_desc = "Shrine Garden (west)";
    long_desc = YEL+
  "\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n"+
    "\t^  ^^^    ^^^    ^     ^^^   ^^^   ^\n"+
    "\t^  ^  ^   ^     ^ ^    ^     ^     ^\n"+NORM+YEL+
    "\t^  ^^^    ^^^  ^^^^^   ^     ^^^   ^\n"+
    "\t^  ^      ^    ^   ^   ^     ^     ^\n"+
    "\t^  ^      ^^^  ^   ^   ^^^   ^^^   ^\n"+
    "\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n"+NORM+
    "\tYou have entered the west garden of \n"+
    "\tthe shrine.  Rest and be welcome\n";
  items = ({
    "east","The Shrine Center is that way",
    "west","Leads to the rice fields...",
  });

  dest_dir = ({
    "/players/mythos/aroom/shrinear5.c","east",
    "/players/mythos/aroom/ricev.c", "west",
  });
} }

query_no_fight() { return 1; }
