#include "/players/mythos/closed/ansi.h"
inherit "room/room";
reset(arg) {
  if(!present("messenger")) {
    move_object(clone_object("/players/mythos/prac/mess.c"),this_object()); }
  if(!arg) {
  set_light(1);
    short_desc = "Shrine Entrance (Torii)";
    long_desc = RED+
  "\n     _________________________________________\n"+
    "               |                   |\n"+
    "               |                   |\n"+
    "     __________|___________________|__________\n"+
    "               |                   |\n"+
    "               |                   |\n"+
    "               |                   |\n"+
    "               |                   |\n"+
    "               |                   |\n"+
    "               |                   |\n\n"+NORM+
    "You step unto a small stone path which leads under\n"+
    "a great Torii- a wooden shrine gate.  Here you may enter\n"+
    "the Shrine center.\n";
  items = ({
    "south","You see the village path",
    "enter","The center of the shrine is there",
    "torii","A beautiful wooden torii",
  });

  dest_dir = ({
    "/players/mythos/aroom/vil1.c","south",
    "/players/mythos/aroom/shrinear5.c","enter",
  });
} }
