#include "/players/grimm/header"
inherit "room/room";

reset(arg) {
  if (arg) return;
  short_desc="Old Street";
  long_desc="This is an old street once used by great adventures when they had\n"
  +"to hide their possessions.  A large storage facility is to the north\n"
 +"which is boarded up and look as though it was abandoned. To the south\n"
 +"is Sacred Blood's main road into town.\n";
  dest_dir=({ROOT(street2),"south",
         });
  set_light(0);
}
