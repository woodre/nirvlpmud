#include "/players/mythos/closed/guild/def.h"
inherit "room/room";
reset(arg) {
  if(!present("drafnor")) {
    move_object(clone_object("/players/mythos/closed/guild/task/hills/speear.c"),
      this_object());
  }
  if(!arg) {
  set_light(10);
    short_desc = "Far bank of the River of Deacrom ";
    long_desc =
    "You are on the other side of the river.  Before you\n"+
    "in the sand is a ruby spear.  Light eminates from it.\n"+
    "A low drumming sound can be heard....\n";
  items = ({,
    "back","Leads back to the hill",
  });

  dest_dir = ({
    "/players/mythos/closed/guild/task/hills/river.c", "back",
  });
} }
