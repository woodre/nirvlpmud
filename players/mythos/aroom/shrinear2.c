#include "/players/mythos/closed/ansi.h"
inherit "room/room";
reset(arg) {
  if(!present("messenger")) {
    move_object(clone_object("/players/mythos/prac/mess.c"),this_object()); }
  if(!arg) {
  set_light(1);
    short_desc = "Shrine Edge";
    long_desc =
    "Here you reach the edge of the Shrine grounds, where nothing truly\n"+
    "malicious (spirits) may enter.  Before you is the forest where the\n"+
    "Hunter reigned and learned dark secrets.  Be careful....\n";
  items = ({
    "south","You see the Shrine center",
    "forest","Becareful... the forest holds many dark secrets",
  });

  dest_dir = ({
    "/players/mythos/aroom/shrinear5.c","south",
    "/players/mythos/aroom/forest/forest9.c", "forest",
  });
} }
