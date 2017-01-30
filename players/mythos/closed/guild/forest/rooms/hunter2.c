#include "/players/mythos/closed/guild/def.h"
object obb;
inherit "room/room";
reset(arg) {
  if(!present("xb")) { 
  move_object(clone_object("/players/mythos/closed/guild/forest/misc/xb.c"),this_object());
  }
  if(!arg) {
  set_light(0);
    short_desc = HIK+"The Forest <"+NORM+MAG+"Forbidden"+HIK+">"+NORM;
    long_desc = MAG+
    "You step into a realm of horror- a realm created by some warped god or\n"+
    "demon.  Dark purple light floods the area. The trees, looming over\n"+
    "everything- block any other light from entering or leaving. The plants \n"+
    "are pale white and twisted, the ground can not be seen.  Critters scurry\n"+
    "about and all is SILENT....\n"+NORM;
  items = ({
    "west","You can return to the less forbidding part of the forest",
    "east",HIK+"Darkness"+NORM+"....",
    "north",HIK+"Darkness"+NORM+"....",
    "south",HIK+"Darkness"+NORM+"....",
  });

  dest_dir = ({
    "/players/mythos/closed/guild/forest/rooms/cavern.c", "north",
    "/players/mythos/closed/guild/forest/rooms/hunter3.c", "east",
    "/players/mythos/closed/guild/forest/rooms/cave.c", "south",
    "/players/mythos/closed/guild/forest/rooms/hunter.c", "west",
  });
} }

realm() { return "NT";}

init() {
  ::init();
  if(tp->is_player()) {
if(!present("night_mare_check",tp)) {
  obb = clone_object("/players/mythos/closed/guild/forest/misc/nit.c");
  move_object(obb,tp); 
  obb->set_ss(tp->query_sp());}} }
