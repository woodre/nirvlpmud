#include "/players/mythos/closed/guild/def.h"
inherit "room/room";
reset(arg) {
  if(!arg) {
  set_light(0);
    short_desc = HIK+"The Forest <"+NORM+MAG+"Forbidden"+HIK+">"+NORM;
    long_desc =
    MAG+"You step into a realm of horror- a realm created by some warped god or\n"+
    "demon.  Dark purple light floods the area. The trees, looming over\n"+
    "everything- block any other light from entering or leaving. The plants \n"+
    "are pale white and twisted, the ground can not be seen.  Critters scurry\n"+
    "about and all is SILENT....\n"+NORM;
  items = ({
    "west","You can return to the less forbidding part of the forest",
    "east",HIK+"Darkness"+NORM+"....",
  });

  dest_dir = ({
    "/players/mythos/closed/guild/forest/rooms/hunter2.c", "east",
    "/players/mythos/aroom/forest/forestr2.c","west",
  });
} }

realm() { return "NT";}

init() {
  ::init();
  if(tp->id("white") || tp->id("thorns") || tp->id("blood")) { destruct(tp); }
  if(tl < 10) {
  write(HIR+"NEWBIE!"+NORM+BOLD+"  Understand that the chances of your\n"+
             "death is almost 100%.  Get out while you can!\n"+NORM); }
  else {
  write(BOLD+"NOTE: This an extremely dangerous place!\n"+NORM); }
  write(BOLD+"You can depart the forest to the west.\n"+NORM);
}
