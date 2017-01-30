#include "/players/mythos/closed/ansi.h"
inherit "room/room";
reset(arg) {
  if(!present("messenger")) {
    move_object(clone_object("/players/mythos/amon/messenger.c"),this_object()); }
  if(!arg) {
  set_light(1);
    short_desc = "Beaten Path";
    long_desc =
    "You step upon a well beaten path leading toward the Far Eastern Empire- \n"+
    "                             Ancient Japan.\n"+
    "The air is a bit more humid than what you are used to.  Things are quiet.\n"+
    "To the "+BOLD+"east"+NORM+" is the rest of the empire, behind is a portal leading back to\n"+
    "to the Chamber of Realms.\n";
  items = ({
    "portal","The portal shimmers with blue light",
    "path","The path has been used a lot",
    "east","You make out a village to the far east",
  });

  dest_dir = ({
    "/players/mythos/aroom/path2.c", "east",
    "/players/mythos/entrance.c","portal",
  });
} }
